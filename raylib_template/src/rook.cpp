//
// Created by agupt on 14/07/2023.
//

#include "rook.h"
#include <vector>

bool Rook ::isValidMove(Position *position) {
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
