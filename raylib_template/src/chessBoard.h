//
// Created by agupt on 14/07/2023.
//

#pragma once

#ifndef CHESS_CPP_CHESSBOARD_H
#define CHESS_CPP_CHESSBOARD_H

#define ROWS 8
#define COLUMNS 8
#define tile_size 100

#include "raylib.h"
#include <cmath>
#include <stdio.h>
#include <stdbool.h>


class ChessBoard {
public:
    bool board[ROWS][COLUMNS];
    int pieceIDs[ROWS][COLUMNS];
    char chessPieces[ROWS][COLUMNS][4];
    Rectangle tiles[ROWS][COLUMNS];

    ChessBoard(){
       setBoard();
       setChessPieces();
       setTiles();
       setPID();
    }

    void setBoard();
    void setChessPieces();
    void setTiles();
    void setPID();
    void printBoardState();
};

#endif //CHESS_CPP_CHESSBOARD_H
