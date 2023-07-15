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
};
