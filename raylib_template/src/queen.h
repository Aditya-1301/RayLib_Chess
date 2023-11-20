//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <cmath>
#include "chessBoard.h"
#include "chessPiece.h"

class Queen : public ChessPiece {
public:
    Queen(){}
    Queen(Position position, bool isWhite, bool isPieceCaptured, ChessBoard &chessBoard){
        this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_queen_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_queen_2x_ns.png");
        this->position = position;
        this->isWhite = isWhite;
        this->isCaptured = isPieceCaptured;
        this->type = PieceType::QUEEN;
        chessBoard.pieceIDs[(int)round((this->position).x)][(int)round((this->position).y)] = (isWhite) ? 5 : 21;
        this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
        sprintf(chessBoard.chessPieces[(int)round(position.x)][(int)round(position.y)], "Q_%c", (isWhite) ? 'W' : 'B');
    }

    bool isValidMove(Position * position) override;
};

#endif //CHESS_CPP_QUEEN_H
