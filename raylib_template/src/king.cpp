#include "headers.h"

class King : public ChessPiece{
    public:

        King(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_king_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_king_2x_ns.png");
            this->position = position;
            this->isWhite = isWhite;
            this->type = PieceType::KING;
            this->pieceRectangle = { (float)(position).y*tile_size, (float)(position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            this->pieceID = (isWhite)? 4 : 28; 
            sprintf(chessBoard.chessPieces[position.x][position.y], "K_%c", (isWhite) ? 'W' : 'B');
            // chessBoard.printBoardState();
        }

        bool isValidMove(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            Position surroundingPositions[] = {
                    Position(x-1, y-1),
                    Position(x-1, y),
                    Position(x-1, y+1),
                    Position(x, y-1),
                    Position(x, y+1),
                    Position(x+1, y-1),
                    Position(x+1, y),
                    Position(x+1, y+1)
            };
            printf("Color of surrounding piece : %c\n", chessPieces[position->x][position->y][2]);
            for (int i = 0; i < sizeof(surroundingPositions) / sizeof(Position); i++) {
                if (position->x == surroundingPositions[i].x && position->y == surroundingPositions[i].y){
                    if((isWhite && chessPieces[position->x][position->y][2] == 'B') ||
                        (!isWhite && chessPieces[position->x][position->y][2] == 'W'))
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        void MoveToPosition(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            printf("Current Position: %d, %d\n", (this->position).x, (this->position).y);
            printf("Target Position: %d, %d\n", position->x, position->y);
            auto validMove = isValidMove(position, chessPieces);
            printf("isValidMove = %d\n", validMove);
            if(validMove){
                printf("Valid Move\n");
                sprintf(chessPieces[(this->position).x][(this->position).y], " %c ", ((this->position).x + (this->position).y)%2 == 0 ? '0' : '#');
                this->position = *position;
                sprintf(chessPieces[(this->position).x][(this->position).y], "K_%c", (isWhite) ? 'W' : 'B');
            }
            else printf("Invalid Move\n"); 
        }       
};