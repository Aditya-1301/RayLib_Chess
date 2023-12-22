//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_KING_H
#define CHESS_CPP_KING_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;

class King : public ChessPiece{
public:
    King(){}
    King(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_king_2x_ns.png") : LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_king_2x_ns.png");
        this->position = position;
        this->isWhite = isWhite;
        this->type = PieceType::KING;
        this->isCaptured = isPieceCaptured;
        this->pieceRectangle = { (float)(position).y*tile_size, (float)(position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 4 : 20;
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "K_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};


#endif //CHESS_CPP_KING_H
