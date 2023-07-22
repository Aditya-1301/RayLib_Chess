#include "headers.h"
  
class ChessBoard{
    public:
        bool board[ROWS][COLUMNS];
        char chessPieces[ROWS][COLUMNS][4];
        int pieceIDs [ROWS][COLUMNS];
        Rectangle tiles [ROWS][COLUMNS];

        ChessBoard(){
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    sprintf(chessPieces[i][j], " %c ", ((i+j)%2 == 0) ? '0' : '#');
                }
            }
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    board[i][j] = ((i+j)%2) == 0;
                }
            }
            for(auto i = 0; i < ROWS; i++){
                for(auto j = 0; j < ROWS; j++){
                    pieceIDs[i][j] = 0; 
                }
            }
            for (auto i = 0; i < ROWS; i++)
            {
                for (auto j = 0; j < COLUMNS; j++)
                {
                    tiles[i][j] = {(float)(i*tile_size), (float)(j*tile_size), tile_size, tile_size};
                }   
            }
        }

        void printBoardState(){
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
};

