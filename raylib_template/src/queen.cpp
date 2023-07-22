#include "headers.h"

class Queen : public ChessPiece{
    public:
        Queen(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_queen_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_queen_2x_ns.png");
            this->position = position;
            // position = (isWhite)? Position(0,4) : Position(7,4); 
            this->isWhite = isWhite;
            this->type = PieceType::QUEEN;
            this->pieceID = (isWhite) ? 5 : 29;
            this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            chessBoard.pieceIDs[this->position.x][this->position.y] = this->pieceID;
            sprintf(chessBoard.chessPieces[position.x][position.y], "Q_%c", (isWhite) ? 'W' : 'B');
        }

        bool isValidMove(Position * position) override{
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            std::vector<Position> possiblePositions;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLUMNS; j++) {
                    if(i == (this->position).x || j == (this->position).y){
                        possiblePositions.push_back(Position(i,j));
                    }
                }
            }    
            for (int i = 0; i < 4; i++) {
                switch (i){
                    case 0 :
                        {
                            int j = x;
                            int k = y;
                            while(j >= 0 && k >= 0){
                                possiblePositions.push_back(Position(j--,k--));
                            }
                        }
                        break;
                    case 1 :
                        {
                            int j = x;
                            int k = y;
                            while(j >= 0 && k < COLUMNS){
                                possiblePositions.push_back(Position(j--,k++));
                            }
                        }
                        break;
                    case 2 :
                        {
                            int j = x;
                            int k = y;
                            while(j < ROWS && k >= 0){
                                possiblePositions.push_back(Position(j++,k--));
                            }
                        }
                        break;
                    case 3 :
                        {
                            int j = x;
                            int k = y;
                            while(j < ROWS && k < COLUMNS){
                                possiblePositions.push_back(Position(j++,k++));
                            }
                        }
                        break;
                }
            }
            for (auto possiblePosition: possiblePositions) {
                if(possiblePosition.x == position->x && possiblePosition.y == position->y){
                    return true;
                }
            }
            return false;
        }  
};