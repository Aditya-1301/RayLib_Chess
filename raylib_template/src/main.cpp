#include "raylib.h"
#include "ChessBoard.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include <vector>
#include "utilities.h"

using namespace ChessPiece_N;
using namespace Utilities_N;

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Chess");
    SetTargetFPS(60);

    ChessBoard c = ChessBoard();

    InitTextures();

    Rook rook1 = Rook(Position(0, 0), true, false, c);
    Rook rook2 = Rook(Position(0, 7), true, false, c);
    Bishop bishop1 = Bishop(Position(0, 2), true, false, c);
    Bishop bishop2 = Bishop(Position(0, 5), true, false, c);
    Knight knight1 = Knight(Position(0, 1), true, false, c);
    Knight knight2 = Knight(Position(0, 6), true, false, c);
    King king = King(Position(0, 3), true, false, c);
    Queen queen = Queen(Position(0, 4), true, false, c);
    Pawn pawn1 = Pawn(Position(1, 0), true, false, c);
    Pawn pawn2 = Pawn(Position(1, 1), true, false, c);
    Pawn pawn3 = Pawn(Position(1, 2), true, false, c);
    Pawn pawn4 = Pawn(Position(1, 3), true, false, c);
    Pawn pawn5 = Pawn(Position(1, 4), true, false, c);
    Pawn pawn6 = Pawn(Position(1, 5), true, false, c);
    Pawn pawn7 = Pawn(Position(1, 6), true, false, c);
    Pawn pawn8 = Pawn(Position(1, 7), true, false, c);


    Rook rook3 = Rook(Position(7, 0), false, false, c);
    Rook rook4 = Rook(Position(7, 7), false, false, c);
    Bishop bishop3 = Bishop(Position(7, 2), false, false, c);
    Bishop bishop4 = Bishop(Position(7, 5), false, false, c);
    Knight knight3 = Knight(Position(7, 1), false, false, c);
    Knight knight4 = Knight(Position(7, 6), false, false, c);
    King king2 = King(Position(7, 3), false, false, c);
    Queen queen2 = Queen(Position(7, 4), false, false, c);
    Pawn pawn9 = Pawn(Position(6, 0), false, false, c);
    Pawn pawn10 = Pawn(Position(6, 1), false, false, c);
    Pawn pawn11 = Pawn(Position(6, 2), false, false, c);
    Pawn pawn12 = Pawn(Position(6, 3), false, false, c);
    Pawn pawn13 = Pawn(Position(6, 4), false, false, c);
    Pawn pawn14 = Pawn(Position(6, 5), false, false, c);
    Pawn pawn15 = Pawn(Position(6, 6), false, false, c);
    Pawn pawn16 = Pawn(Position(6, 7), false, false, c);

    std::vector<Rectangle> destRects = {
            {static_cast<float>(king.position.y) * tile_size, static_cast<float>(king.position.x) * tile_size, static_cast<float>(kingWImage.width) / 10, static_cast<float>(kingWImage.height) / 10},
            {static_cast<float>(queen.position.y) * tile_size, static_cast<float>(queen.position.x) * tile_size, static_cast<float>(queenWImage.width) / 10, static_cast<float>(queenWImage.height) / 10},
            {static_cast<float>(rook1.position.y) * tile_size, static_cast<float>(rook1.position.x) * tile_size, static_cast<float>(rookWImage.width) / 10, static_cast<float>(rookWImage.height) / 10},
            {static_cast<float>(rook2.position.y) * tile_size, static_cast<float>(rook2.position.x) * tile_size, static_cast<float>(rookWImage.width) / 10, static_cast<float>(rookWImage.height) / 10},
            {static_cast<float>(knight1.position.y) * tile_size, static_cast<float>(knight1.position.x) * tile_size, static_cast<float>(knightWImage.width) / 10, static_cast<float>(knightWImage.height) / 10},
            {static_cast<float>(knight2.position.y) * tile_size, static_cast<float>(knight2.position.x) * tile_size, static_cast<float>(knightWImage.width) / 10, static_cast<float>(knightWImage.height) / 10},
            {static_cast<float>(bishop1.position.y) * tile_size, static_cast<float>(bishop1.position.x) * tile_size, static_cast<float>(bishopWImage.width) / 10, static_cast<float>(bishopWImage.height) / 10},
            {static_cast<float>(bishop2.position.y) * tile_size, static_cast<float>(bishop2.position.x) * tile_size, static_cast<float>(bishopWImage.width) / 10, static_cast<float>(bishopWImage.height) / 10},
            {static_cast<float>(pawn1.position.y) * tile_size, static_cast<float>(pawn1.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn2.position.y) * tile_size, static_cast<float>(pawn2.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn3.position.y) * tile_size, static_cast<float>(pawn3.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn4.position.y) * tile_size, static_cast<float>(pawn4.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn5.position.y) * tile_size, static_cast<float>(pawn5.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn6.position.y) * tile_size, static_cast<float>(pawn6.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn7.position.y) * tile_size, static_cast<float>(pawn7.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(pawn8.position.y) * tile_size, static_cast<float>(pawn8.position.x) * tile_size, static_cast<float>(pawnWImage.width) / 10, static_cast<float>(pawnWImage.height) / 10},
            {static_cast<float>(king2.position.y) * tile_size, static_cast<float>(king2.position.x) * tile_size, static_cast<float>(kingBImage.width) / 10, static_cast<float>(kingBImage.height) / 10},
            {static_cast<float>(queen2.position.y) * tile_size, static_cast<float>(queen2.position.x) * tile_size, static_cast<float>(queenBImage.width) / 10, static_cast<float>(queenBImage.height) / 10},
            {static_cast<float>(rook3.position.y) * tile_size, static_cast<float>(rook3.position.x) * tile_size, static_cast<float>(rookBImage.width) / 10, static_cast<float>(rookBImage.height) / 10},
            {static_cast<float>(rook4.position.y) * tile_size, static_cast<float>(rook4.position.x) * tile_size, static_cast<float>(rookBImage.width) / 10, static_cast<float>(rookBImage.height) / 10},
            {static_cast<float>(knight3.position.y) * tile_size, static_cast<float>(knight3.position.x) * tile_size, static_cast<float>(knightBImage.width) / 10, static_cast<float>(knightBImage.height) / 10},
            {static_cast<float>(knight4.position.y) * tile_size, static_cast<float>(knight4.position.x) * tile_size, static_cast<float>(knightBImage.width) / 10, static_cast<float>(knightBImage.height) / 10},
            {static_cast<float>(bishop3.position.y) * tile_size, static_cast<float>(bishop3.position.x) * tile_size, static_cast<float>(bishopBImage.width) / 10, static_cast<float>(bishopBImage.height) / 10},
            {static_cast<float>(bishop4.position.y) * tile_size, static_cast<float>(bishop4.position.x) * tile_size, static_cast<float>(bishopBImage.width) / 10, static_cast<float>(bishopBImage.height) / 10},
            {static_cast<float>(pawn9.position.y) * tile_size, static_cast<float>(pawn9.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn10.position.y) * tile_size, static_cast<float>(pawn10.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn11.position.y) * tile_size, static_cast<float>(pawn11.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn12.position.y) * tile_size, static_cast<float>(pawn12.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn13.position.y) * tile_size, static_cast<float>(pawn13.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn14.position.y) * tile_size, static_cast<float>(pawn14.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn15.position.y) * tile_size, static_cast<float>(pawn15.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10},
            {static_cast<float>(pawn16.position.y) * tile_size, static_cast<float>(pawn16.position.x) * tile_size, static_cast<float>(pawnBImage.width) / 10, static_cast<float>(pawnBImage.height) / 10}
    };

    pieces = {
            {&king, &destRects[0]},
            {&queen, &destRects[1]},
            {&rook1, &destRects[2]},
            {&rook2, &destRects[3]},
            {&knight1, &destRects[4]},
            {&knight2, &destRects[5]},
            {&bishop1, &destRects[6]},
            {&bishop2, &destRects[7]},
            {&pawn1, &destRects[8]},
            {&pawn2, &destRects[9]},
            {&pawn3, &destRects[10]},
            {&pawn4, &destRects[11]},
            {&pawn5, &destRects[12]},
            {&pawn6, &destRects[13]},
            {&pawn7, &destRects[14]},
            {&pawn8, &destRects[15]},

            {&king2, &destRects[16]},
            {&queen2, &destRects[17]},
            {&rook3, &destRects[18]},
            {&rook4, &destRects[19]},
            {&knight3, &destRects[20]},
            {&knight4, &destRects[21]},
            {&bishop3, &destRects[22]},
            {&bishop4, &destRects[23]},
            {&pawn9, &destRects[24]},
            {&pawn10, &destRects[25]},
            {&pawn11, &destRects[26]},
            {&pawn12, &destRects[27]},
            {&pawn13, &destRects[28]},
            {&pawn14, &destRects[29]},
            {&pawn15, &destRects[30]},
            {&pawn16, &destRects[31]}
    };

    for(auto i : destRects){
        printf("pieces dr = (%f,%f,%f,%f)\n", i.y, i.x, i.width, i.height);
    }

    Vector2 offset = { 0, 0 };

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(WHITE);

        RenderChessBoard();

        HandleChessPieceSelection(pieces, offset);

        RenderChessPieceImage(pieces);

        EndDrawing();
    }

    CloseWindow();

    UnloadTextures();

    return 0;
}
