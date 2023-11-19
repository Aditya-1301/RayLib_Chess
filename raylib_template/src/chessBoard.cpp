//
// Created by agupt on 14/07/2023.
//

#include "ChessBoard.h"

void ChessBoard ::setBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = ((i+j)%2) == 0;
        }
    }
}

void ChessBoard ::setChessPieces() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            sprintf(chessPieces[i][j], " %c ", ((i+j)%2 == 0) ? '0' : '#');
        }
    }
}

void ChessBoard ::setTiles() {
    for (auto i = 0; i < ROWS; i++)
    {
        for (auto j = 0; j < COLUMNS; j++)
        {
            tiles[i][j] = {(float)(i*tile_size), (float)(j*tile_size), tile_size, tile_size};
        }
    }
}

void ChessBoard ::setPID() {
    for(auto i = 0; i < ROWS; i++){
        for(auto j = 0; j < COLUMNS; j++){
            pieceIDs[i][j] = 0;
        }
    }
}


void ChessBoard ::printBoardState(){
    for (int j = 0; j < COLUMNS; j++) {
        printf("----");
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLUMNS; j++) {
            for(int k = 0; k < 4; k++){
                printf("%c", chessPieces[i][j][k]);
            }
            printf("|");
        }
        printf("\n");
        for (int j = 0; j < COLUMNS; j++) {
            printf("----");
        }
        printf("\n");
    }
    printf("\n\n\n");
}



