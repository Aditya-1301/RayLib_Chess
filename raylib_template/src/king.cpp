//
// Created by agupt on 14/07/2023.
//

#include "king.h"

bool King::isValidMove(Position *position) {
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

