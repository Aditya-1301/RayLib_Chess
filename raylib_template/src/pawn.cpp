#include "headers.h"

class Pawn : public ChessPiece{
    public:
        Pawn(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_pawn_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_pawn_2x_ns.png");
            this->position = position; 
            this->isWhite = isWhite;
            this->type = PieceType::PAWN;
            if((this->position).x == 2 && isWhite){
                this->pieceID = (this->position).y + 9; 
            }
            else if((this->position).x == 6 && !isWhite){
                this->pieceID = (this->position).y + 17;
            }
            this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            sprintf(chessBoard.chessPieces[position.x][position.y], "P_%c", (isWhite) ? 'W' : 'B');
        }

        bool isValidMove(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            if(isWhite && (this->position).x == 1){
                if(position->x == 2 || position->x == 3){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(!isWhite && (this->position).x == 6){
                if(position->x == 4 || position->x == 5){
                    return true;
                }
                else{
                    return false;
                }
            }
            return false;
        }

        void MoveToPosition(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            printf("Current Position: %d, %d\n", (this->position).x, (this->position).y);
            printf("Target Position: %d, %d\n", position->x, position->y);
            if(isValidMove(position, chessPieces)){
                sprintf(chessPieces[(this->position).x][(this->position).y], " %c ", ((this->position).x + (this->position).y)%2 == 0 ? '0' : '#');
                this->position = *position;
                sprintf(chessPieces[(this->position).x][(this->position).y], "P_%c", (isWhite) ? 'W' : 'B');
            }
            else printf("Invalid Move\n");
        }    
};