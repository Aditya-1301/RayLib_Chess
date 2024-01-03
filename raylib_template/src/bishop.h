//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_BISHOP_H
#define CHESS_CPP_BISHOP_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;

class Bishop : public ChessPiece{
public:
    Bishop(){}
    Bishop(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
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
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "B_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};

#endif //CHESS_CPP_BISHOP_H
