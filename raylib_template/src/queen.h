//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_QUEEN_H
#define CHESS_CPP_QUEEN_H

#include "ChessBoard.h"
#include "ChessPiece.h"
#include <cmath>
using namespace ChessPiece_N;

class Queen : public ChessPiece {
public:
    Queen(){}
    Queen(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->position = position;
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::QUEEN;
        chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite) ? 5 : 21;
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "Q_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};

#endif //CHESS_CPP_QUEEN_H
