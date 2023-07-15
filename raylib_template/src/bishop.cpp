#include "headers.h"

class Bishop : public ChessPiece{
    public:
        Bishop(Position position, bool isWhite, ChessBoard &chessBoard){
            this->pieceImage = (isWhite) ? LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_bishop_2x_ns.png") : LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
            this->position = position;
            // position = (isWhite)? Position(0,2) : Position(7,5); 
            this->isWhite = isWhite;
            this->type = PieceType::BISHOP;
            if((this->position).y == 2){
                chessBoard.pieceIDs[(this->position).x][(this->position).y] = (isWhite)? 3 : 19;
            }
            else if((this->position).y == 5){
                chessBoard.pieceIDs[(this->position).x][(this->position).y] = (isWhite)? 6 : 22;
            }
            this->pieceRectangle = { (float)(this->position).y*tile_size, (float)(this->position).x*tile_size, (float)((this->pieceImage).width / 10), (float)((this->pieceImage).height / 10 )};
            sprintf(chessBoard.chessPieces[position.x][position.y], "B_%c", (isWhite) ? 'W' : 'B');
            // chessBoard.printBoardState();
        }

        bool isValidMove(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            std::vector<Position> possiblePositions;
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

        void MoveToPosition(Position * position, char chessPieces [ROWS][COLUMNS][4]) override{
            printf("Current Position: %d, %d\n", (this->position).x, (this->position).y);
            printf("Target Position: %d, %d\n", position->x, position->y);
            if(isValidMove(position, chessPieces)){
                sprintf(chessPieces[(this->position).x][(this->position).y], " %c ", ((this->position).x + (this->position).y)%2 == 0 ? '0' : '#');
                this->position = *position;
                sprintf(chessPieces[(this->position).x][(this->position).y], "B_%c", (isWhite) ? 'W' : 'B');
            }
            else printf("Invalid Move\n");
        }    
};