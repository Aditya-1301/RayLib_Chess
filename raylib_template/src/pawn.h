//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_PAWN_H
#define CHESS_CPP_PAWN_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;


class Pawn : public ChessPiece{
public:
    Pawn(){}
    Pawn(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->position = position;
        this->isWhite = isWhite;
        this->type = PieceType::PAWN;
        this->isCaptured = isPieceCaptured;
        if((this->position).x == 2 && isWhite){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (this->position).y + 8;
        }
        else if((this->position).x == 6 && !isWhite){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (this->position).y + 16;
        }
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "P_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};


#endif //CHESS_CPP_PAWN_H
