//
// Created by agupt on 14/07/2023.
//

#include <cmath>
#include "knight.h"

bool Knight::isValidMove(Position *position) {
    int x = (int) round((this->position).x);
    int y = (int) round((this->position).y);
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
