#include "headers.h"

enum PieceType {
    KING,
    QUEEN,
    KNIGHT,
    BISHOP,
    ROOK,
    PAWN
};

class Position{
    public:
        int x;
        int y;

        Position(){

        }

        Position(int X, int Y){
            x = X;
            y = Y;
        }
};

class ChessPiece{
    protected:
        virtual bool isValidMove(Position * position, char chessPieces [ROWS][COLUMNS][4]) = 0;
    public:
        Image pieceImage;
        Rectangle pieceRectangle;
        Position position;
        PieceType type;
        bool isWhite;
        ChessPiece(){

        }

        virtual void MoveToPosition(Position * position, char chessPieces [ROWS][COLUMNS][4]) = 0;
        std::string getType(){
            switch (this->type)
            {
            case KING:
                return "King";
            case QUEEN:
                return "Queen";
            case ROOK:
                return "Rook";
            case KNIGHT:
                return "Knight";
            case BISHOP:
                return "Bishop";
            case PAWN:
                return "Pawn";
            }
        } 

        bool kingCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
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

        bool queenCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
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

        bool pawnCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            if(isWhite){
                if((this->position.x + 1 == position->x) || (this->position.x == 1 && position->x == 4)){
                    return true;
                }
                else return false;
            }
            else{
                if((this->position.x - 1 == position->x) || (this->position.x == 6 && position->x == 4)){
                    return true;
                }
                else return false;
            }
        }
        
        bool rookCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
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
            for (auto possiblePosition : possiblePositions) {
                printf("(%d, %d), ", possiblePosition.x, possiblePosition.y);
            }
            printf("\n");
            for (auto possiblePosition: possiblePositions) {
                if(possiblePosition.x == position->x && possiblePosition.y == position->y){
                    return true;
                }
            }
            return false;
        }
        
        bool knightCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
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
        
        bool bishopCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
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

        bool validityCheck(Position * position,char chessPieces [ROWS][COLUMNS][4]){
            switch (this->type)
            {
                case KING:
                    return kingCheck(position, chessPieces);
                case QUEEN:
                    return queenCheck(position, chessPieces);
                case ROOK:
                    return rookCheck(position, chessPieces);
                case KNIGHT:
                    return knightCheck(position, chessPieces);
                case BISHOP:
                    return bishopCheck(position, chessPieces);
                case PAWN:
                    return pawnCheck(position, chessPieces);
            }
        }
};
