
#include "headers.h"

class Knight : public ChessPiece{
    public:
        Knight(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_knight_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_knight_2x_ns.png");
            this->position = position;
            this->isWhite = isWhite;
            this->type = PieceType::KNIGHT;
            if((this->position).y == 1){
                this->pieceID = (isWhite)? 2 : 26;
            }
            else if((this->position).y == 6){
                this->pieceID = (isWhite)? 7 : 31;
            }
            chessBoard.pieceIDs[this->position.x][this->position.y] = this->pieceID;
            this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            sprintf(chessBoard.chessPieces[position.x][position.y], "Kn%c", (isWhite) ? 'W' : 'B');
        }

        bool isValidMove(Position * position) override{
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            Position possiblePositions[] = {
                Position(x-2, y-1),
                Position(x-2, y+1),
                Position(x+2, y-1),
                Position(x+2, y+1),
                Position(x-1, y-2),
                Position(x-1, y+2),
                Position(x+1, y-2),
                Position(x+1, y+2)
            };
            for (auto possiblePosition: possiblePositions) {
                if(possiblePosition.x == position->x && possiblePosition.y == position->y){
                    return true;
                }
                else{
                    return false;
                }
            }
            return false;
        }
};