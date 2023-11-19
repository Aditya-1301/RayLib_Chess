//
// Created by agupt on 14/07/2023.
//

#pragma once

#include "chessBoard.h"
#include "chessPiece.h"
#include <cmath>

#ifndef CHESS_CPP_BISHOP_H
#define CHESS_CPP_BISHOP_H

class Bishop : public ChessPiece{
public:
    Bishop(){}
    Bishop(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png") : LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
        this->position = position;
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::BISHOP;
        if((this->position).y == 2){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 3 : 19;
        }
        else if((this->position).y == 5){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 6 : 22;
        }
        this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "B_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};


#endif //CHESS_CPP_BISHOP_H
