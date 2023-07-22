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
            chessBoard.pieceIDs[this->position.x][this->position.y] = this->pieceID;
            sprintf(chessBoard.chessPieces[position.x][position.y], "K_%c", (isWhite) ? 'W' : 'B');
        }

        bool isValidMove(Position * position) override{
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

            for (int i = 0; i < sizeof(surroundingPositions) / sizeof(Position); i++) {
                if (position->x == surroundingPositions[i].x && position->y == surroundingPositions[i].y){
                    return true;
                }
            }
            return false;
        }
};