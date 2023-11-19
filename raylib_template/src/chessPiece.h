//
// Created by agupt on 14/07/2023.
//

#pragma once

#include "raylib.h"
#include "chessBoard.h"
#include <stdio.h>
#include <cmath>
#include <string>

#define ROWS 8
#define COLUMNS 8

#ifndef CHESS_CPP_CHESSPIECE_H
#define CHESS_CPP_CHESSPIECE_H

enum PieceType {
    KING,
    QUEEN,
    KNIGHT,
    BISHOP,
    ROOK,
    PAWN
};

class Position{
public:
    int x;
    int y;

    Position(){

    }

    Position(int X, int Y){
        x = X;
        y = Y;
    }
};

class ChessPiece {
protected:
    bool selected = false;
public:
    Image pieceImage;
    Rectangle pieceRectangle;
    Position position;
    PieceType type;
    bool isWhite;
    bool isCaptured = false;
    ChessPiece(){}

    bool isSelected() const {
        return selected;
    }

    void setSelected(bool value) {
        selected = value;
    }

    void setPosition(int x, int y) {
        this->position.x = x;
        this->position.y = y;
    }

    virtual bool isValidMove(Position * position) = 0;

    void MoveToPosition(Position * position){
        printf("Current Position: %d, %d\n", (this->position).x, (this->position).y);
        printf("Target Position: %d, %d\n", position->x, position->y);
        setPosition(position->x, position->y);
    }

    std::string getType();

    bool kingCheck(Position * position);

    bool queenCheck(Position * position);

    bool rookCheck(Position * position);

    bool pawnCheck(Position * position);

    bool knightCheck(Position * position);

    bool bishopCheck(Position * position);

    bool validityCheck(Position * position){
        switch (this->type)
        {
            case KING:
                return kingCheck(position);
            case QUEEN:
                return queenCheck(position);
            case ROOK:
                return rookCheck(position);
            case KNIGHT:
                return knightCheck(position);
            case BISHOP:
                return bishopCheck(position);
            case PAWN:
                return pawnCheck(position);
        }
    }
};

#endif //CHESS_CPP_CHESSPIECE_H
