//
// Created by agupt on 14/07/2023.
//

#include "bishop.h"
#include <vector>

bool Bishop::isValidMove(Position *position) {
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

