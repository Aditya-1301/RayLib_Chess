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
        bool selected = false;
    public:
        Image pieceImage;
        int pieceID;
        Rectangle pieceRectangle;
        Position position;
        PieceType type;
        bool isWhite;
        ChessPiece(){

        }

        bool isSelected() const {
            return selected;
        }

        void setSelected(bool value) {
            selected = value;
        }

        void setPosition(int x, int y) {
            this->position.x = x;
            this->position.y = y;
        }

        virtual bool isValidMove(Position * position) = 0; //{
            // // std :: cout << "entered" << std :: endl;
            // // return validityCheck(position);
            // switch (this->type)
            // {
            //     case KING:
            //         std :: cout << "works" << std :: endl;
            //         return kingCheck(position);
            //     case QUEEN:
            //         std :: cout << "works" << std :: endl;
            //         return queenCheck(position);
            //     case ROOK:
            //         std :: cout << "works" << std :: endl;
            //         return rookCheck(position);
            //     case KNIGHT:
            //         std :: cout << "works" << std :: endl;
            //         return knightCheck(position);
            //     case BISHOP:
            //         std :: cout << "works" << std :: endl;
            //         return bishopCheck(position);
            //     case PAWN:
            //         std :: cout << "works" << std :: endl;
            //         return pawnCheck(position);
        //     }
        // }

        void MoveToPosition(Position * position){
            printf("Current Position: %d, %d\n", (this->position).x, (this->position).y);
            printf("Target Position: %d, %d\n", position->x, position->y);
            setPosition(position->x, position->y);
            // if(isValidMove(position)){
            //     setPosition(position->x, position->y);
            // }
            // else printf("Invalid Move\n");
        }


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

        bool kingCheck(Position * position){
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

        bool queenCheck(Position * position){
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

        bool pawnCheck(Position * position){
            int x = (this->position).x;
            int y = (this->position).y;
            if( 0 > x || x > 8 || 0 > y || y > 8){
                return false;
            }
            if(isWhite){
                if((this->position.x + 1 == position->x) || (this->position.x == 1 && position->x == 3) && (this->position.y == position->y)){
                    return true;
                }
                else return false;
            }
            else{
                if((this->position.x - 1 == position->x) || (this->position.x == 6 && position->x == 4) && (this->position.y == position->y)){
                    return true;
                }
                else return false;
            }
        }
        
        bool rookCheck(Position * position){
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
        
        bool knightCheck(Position * position){
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
        
        bool bishopCheck(Position * position){
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

        bool validityCheck(Position * position){
            switch (this->type)
            {
                case KING:
                    return kingCheck(position);
                case QUEEN:
                    return queenCheck(position);
                case ROOK:
                    return rookCheck(position);
                case KNIGHT:
                    return knightCheck(position);
                case BISHOP:
                    return bishopCheck(position);
                case PAWN:
                    return pawnCheck(position);
            }
        }
};

/*
---------------------------------
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 
---------------------------------
| 9 | 10| 11| 12| 13| 14| 15| 16|
---------------------------------
---------------------------------
| 17| 18| 19| 20| 21| 22| 23| 24| 
---------------------------------
| 25| 26| 27| 28| 29| 30| 31| 32|
---------------------------------
*/
