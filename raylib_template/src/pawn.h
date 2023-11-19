//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_PAWN_H
#define CHESS_CPP_PAWN_H

#include "chessBoard.h"
#include "chessPiece.h"
#include <cmath>

class Pawn : public ChessPiece{
public:
    Pawn(){}
    Pawn(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_pawn_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_pawn_2x_ns.png");
        this->position = position;
        // position = (isWhite)? Position(1,0) : Position(6,7);
        this->isWhite = isWhite;
        this->type = PieceType::PAWN;
        this->isCaptured = isPieceCaptured;
        if((this->position).x == 2 && isWhite){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (this->position).y + 8;
        }
        else if((this->position).x == 6 && !isWhite){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (this->position).y + 16;
        }
        this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "P_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};


#endif //CHESS_CPP_PAWN_H
