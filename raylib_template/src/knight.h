//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_KNIGHT_H
#define CHESS_CPP_KNIGHT_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;

class Knight : public ChessPiece{
public:
    Knight(){}
    Knight(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->position = position;
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::KNIGHT;
        if((this->position).y == 1){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 2 : 18;
        }
        else if((this->position).y == 6){
            chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite)? 7 : 23;
        }
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "Kn%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};

#endif //CHESS_CPP_KNIGHT_H
