//
// Created by agupt on 14/07/2023.
//

#pragma once

#include "chessBoard.h"
#include "chessPiece.h"
#include <cmath>

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


class Knight : public ChessPiece{
public:
    Knight(){}
    Knight(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_knight_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_knight_2x_ns.png");
        this->position = position;
        // position = (isWhite)? Position(0,1) : Position(7,6);
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::KNIGHT;
        if((this->position).y == 1){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 2 : 18;
        }
        else if((this->position).y == 6){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 7 : 23;
        }
        this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "Kn%c", (isWhite) ? 'W' : 'B');
        // chessBoard.printBoardState();
    }

    bool isValidMove(Position * position) override;
};


#endif //CHESS_CPP_KNIGHT_H
