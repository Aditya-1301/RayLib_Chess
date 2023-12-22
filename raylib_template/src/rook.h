//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_ROOK_H
#define CHESS_CPP_ROOK_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;

class Rook : public ChessPiece{
public:
    Rook(){}
    Rook(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png") : LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
        this->position = position;
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::ROOK;
        if((this->position).y == 0){
            chessBoard.pieceIDs[(int)(this->position).x][(int)(this->position).y] = (isWhite)? 1 : 17;
        }
        else if((this->position).y == 7){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int) round((this->position).y)] = (isWhite)? 8 : 24;
        }
        this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "R_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};

#endif //CHESS_CPP_ROOK_H
