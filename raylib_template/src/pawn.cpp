#include "headers.h"

class Pawn : public ChessPiece{
    public:
        Pawn(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_pawn_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_pawn_2x_ns.png");
            this->position = position; 
            this->isWhite = isWhite;
            this->type = PieceType::PAWN;
            if((this->position).x == 1 && isWhite){
                this->pieceID = (this->position).y + 9; 
            }
            else if((this->position).x == 6 && !isWhite){
                this->pieceID = (this->position).y + 17;
            }
            chessBoard.pieceIDs[this->position.x][this->position.y] = this->pieceID;
            this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            sprintf(chessBoard.chessPieces[position.x][position.y], "P_%c", (isWhite) ? 'W' : 'B');
        }

        bool isValidMove(Position * position) override{
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
};