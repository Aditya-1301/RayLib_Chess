#include "headers.h"
#include <vector>

int main(){
    ChessBoard c = ChessBoard();
    King king =  King(Position(0,3), true, c);
    Pawn pawn =  Pawn(Position(1,0), true, c);
    Rook rook =  Rook(Position(0,0), true, c);
    Bishop bishop = Bishop(Position(0,2), true, c);
    Queen queen = Queen(Position(7,4), false, c);
    Knight knight =  Knight(Position(7,1), false, c);
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