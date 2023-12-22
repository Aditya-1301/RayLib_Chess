//
// Created by agupt on 14/07/2023.
//

#include "pawn.h"


bool Pawn ::isValidMove(Position *position) {
    int x = (this->position).x;
    int y = (this->position).y;
    if( 0 > x || x > 8 || 0 > y || y > 8){
        return false;
    }
    if(isWhite && (this->position).x == 1){
        if(position->x == 2 || position->x == 3){
            return true;
        }
        else{
            return false;
        }
    }
    else if(!isWhite && (this->position).x == 6){
        if(position->x == 4 || position->x == 5){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}