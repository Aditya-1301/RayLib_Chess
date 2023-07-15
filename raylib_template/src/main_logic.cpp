#include "headers.h"
#include <vector>

int main(){
    ChessBoard c = ChessBoard();
    King king =  King(true, false, c);
    Pawn pawn =  Pawn(true, false, c);
    Rook rook =  Rook(false, false, c);
    Bishop bishop = Bishop(true, false, c);
    Queen queen = Queen(false, false, c);
    Knight knight = Knight(false, false, c);
    std::vector<Position> positions = {Position(0,4), Position(2,0), Position(7,1), Position(2,4), Position(3,4), Position(5,5)};
    king.MoveToPosition(&positions[0], c.chessPieces);
    pawn.MoveToPosition(&positions[1], c.chessPieces);
    rook.MoveToPosition(&positions[2], c.chessPieces);
    bishop.MoveToPosition(&positions[3], c.chessPieces);
    queen.MoveToPosition(&positions[4], c.chessPieces);
    knight.MoveToPosition(&positions[5], c.chessPieces);
    c.printBoardState();
    return 0;
}