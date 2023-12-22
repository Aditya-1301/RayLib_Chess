//
// Created by agupt on 14/07/2023.
//

#include <string>
#include <vector>
#include "ChessPiece.h"
#include "utilities.h"
using namespace Utilities_N;

void utils_test(){
    std::vector<c_pieces> ps = returnPieces();
    std::cout<<"\tUTILS TEST BEGIN\t"<<std::endl;
    for (auto p : ps) {
        std::cout<<p.cp->position.x<<" "<<p.cp->position.y<<std::endl;
    }
    std::cout<<"\tUTILS TEST END\t"<<std::endl;
}

namespace ChessPiece_N{

    std::string ChessPiece::getType(){
        utils_test();
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

    bool ChessPiece :: kingCheck(Position * position){
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

    bool ChessPiece :: queenCheck(Position * position){
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

    bool ChessPiece :: pawnCheck(Position * position){
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

    bool ChessPiece :: rookCheck(Position * position){
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

    bool ChessPiece :: knightCheck(Position * position){
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
        }
        return false;
    }

    bool ChessPiece :: bishopCheck(Position * position){
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
}