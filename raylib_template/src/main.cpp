#include "raylib.h"
#include "chessBoard.h"
#include "chessPiece.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"
#include <vector>
#include <iostream>

#define W_WIDTH 800 //500
#define W_HEIGHT 800 //500

#define tile_size 100

typedef struct piece{
    ChessPiece * cp;
    Rectangle * dr;
} c_pieces;

ChessPiece * selectedPiece = nullptr;
int index;
int turnCount = 0;

Texture2D imageR1;
Texture2D imageR2;
Texture2D imageB1;
Texture2D imageB2;
Texture2D imageKn1;
Texture2D imageKn2;
Texture2D imageK;
Texture2D imageQ;
Texture2D imageP;

Texture2D image_r1;
Texture2D image_r2;
Texture2D image_b1;
Texture2D image_b2;
Texture2D image_kn1;
Texture2D image_kn2;
Texture2D imageK2;
Texture2D imageQ2;
Texture2D image_p;

Image rookWImage;
Image bishopWImage;
Image knightWImage;
Image kingWImage;
Image queenWImage;
Image pawnWImage;

Image rookBImage;
Image bishopBImage;
Image knightBImage;
Image kingBImage;
Image queenBImage;
Image pawnBImage;

Rectangle sourceRectKing;
Rectangle sourceRectQueen;
Rectangle sourceRectRook;
Rectangle sourceRectBishop;
Rectangle sourceRectKnight;
Rectangle sourceRectPawn;

void boardColorsSet(std::vector<std::vector<Color>>& boardColors){
    Vector2 mousePos = GetMousePosition();
    int tileX = static_cast<int>(mousePos.x / tile_size);
    int tileY = static_cast<int>(mousePos.y / tile_size);

    // Check if the mouse is inside the chessboard bounds
    if (tileX >= 0 && tileX < 8 && tileY >= 0 && tileY < 8)
    {
        // Update the color of the tile being hovered over
        for (auto i = 0; i < 8; i++)
        {
            for (auto j = 0; j < 8; j++)
            {
                if (i == tileX && j == tileY)
                    boardColors[i][j] = GRAY;
                else{
                    if((i+j)%2 == 0){
                        if(turnCount % 2 == 0){
                            boardColors[i][j] = BLUE;
                        }else{
                            boardColors[i][j] = RED;
                        }
                    }
                    else{
                        if(turnCount % 2 == 0){
                            boardColors[i][j] = WHITE; //LIGHTGRAY
                        }else{
                            boardColors[i][j] = BLACK;
                        }
                    }
                }
            }
        }
    }
}

void RenderChessBoard(){
    std::vector<std::vector<Color>> boardColors(8, std::vector<Color>(8, WHITE));
    boardColorsSet(boardColors);

    for (auto i = 0; i < 8; i++)
    {
        for (auto j = 0; j < 8; j++)
        {
            DrawRectangle(i*tile_size, j*tile_size, tile_size, tile_size, boardColors[i][j]);
        }
    }
}

void InitTextures() {
    imageR1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    imageR2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    imageB1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    imageB2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    imageKn1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    imageKn2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    imageK = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_king_2x_ns.png");
    imageQ = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    imageP = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    image_r1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    image_r2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    image_b1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    image_b2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    image_kn1 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    image_kn2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    imageK2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_king_2x_ns.png");
    imageQ2 = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    image_p = LoadTexture("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_pawn_2x_ns.png");


    rookWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    bishopWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    knightWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    kingWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_king_2x_ns.png");
    queenWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    pawnWImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    rookBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    bishopBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    knightBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    kingBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_king_2x_ns.png");
    queenBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    pawnBImage = LoadImage("D:\\RayLib\\Chess\\raylib_template\\src\\res\\b_pawn_2x_ns.png");

    sourceRectKing = {0, 0, (float) kingWImage.width, (float) kingWImage.height};  // Entire image
    sourceRectQueen = {0, 0, (float) queenWImage.width, (float) queenWImage.height};
    sourceRectRook = {0, 0, (float) rookWImage.width, (float) rookWImage.height};
    sourceRectBishop = {0, 0, (float) bishopWImage.width, (float) bishopWImage.height};
    sourceRectKnight = {0, 0, (float) knightWImage.width, (float) knightWImage.height};
    sourceRectPawn = {0, 0, (float) pawnWImage.width, (float) pawnWImage.height};
}

void UnloadTextures() {
    UnloadTexture(imageR1);
    UnloadTexture(imageR2);
    UnloadTexture(image_r1);
    UnloadTexture(image_r2);
    UnloadTexture(imageB1);
    UnloadTexture(imageB2);
    UnloadTexture(image_b1);
    UnloadTexture(image_b2);
    UnloadTexture(imageKn1);
    UnloadTexture(imageKn2);
    UnloadTexture(image_kn1);
    UnloadTexture(image_kn2);
    UnloadTexture(imageK);
    UnloadTexture(imageK2);
    UnloadTexture(imageQ);
    UnloadTexture(imageQ2);
    UnloadTexture(imageP);
    UnloadTexture(image_p);
}

bool IsSameColor(std::vector<c_pieces> pieces, ChessPiece * selectedPiece, Position dest){
    bool IsSameColor = false;
    for (int i = 0; i < pieces.size(); i++) {
        if(i != index){
            if(pieces[i].cp->position.x == dest.x && pieces[i].cp->position.y == dest.y){
                IsSameColor = (pieces[i].cp->isCaptured) ? false : (selectedPiece->isWhite == pieces[i].cp->isWhite);
            }
        }
    }
    return IsSameColor;
}

int SetCapturedIndices(std::vector<c_pieces> pieces, Position dest){
    int cap_index = -1;
    for (int i = 0; i < pieces.size(); ++i) {
        if(i != index && (pieces[i].cp->position.x == dest.x && pieces[i].cp->position.y == dest.y)){
            cap_index = i;
        }
    }
    return cap_index;
}

void CheckMoveValidityForSelectedPiece(std::vector<c_pieces>& pieces, Position dest) {
    if (selectedPiece) {
        printf("Is Valid: %d\n", selectedPiece->validityCheck(&dest));
        // Call the specific move validity check for the selected piece
        if (selectedPiece->validityCheck(&dest) && !IsSameColor(pieces, selectedPiece, dest)
            && !(selectedPiece->position.x == dest.x && selectedPiece->position.y == dest.y)) {
            // The move is valid, update the piece's position on the chessboard
            selectedPiece->MoveToPosition(&dest);
            pieces[index].dr->x = selectedPiece->position.y * tile_size;
            pieces[index].dr->y = selectedPiece->position.x * tile_size;
            turnCount++;

            int captured_index = SetCapturedIndices(pieces,dest);
            if(captured_index != -1){
                pieces[captured_index].cp->isCaptured = true;
            }
        } else {
            std::cout << "INVALID MOVE: " + selectedPiece->getType() << std::endl;
            // Handle the invalid move appropriately (e.g., show an error message)
            pieces[index].dr->x = selectedPiece->position.y * tile_size; // Reset position to original
            pieces[index].dr->y = selectedPiece->position.x * tile_size;
        }

        // Deselect the piece after checking its move validity
        selectedPiece->setSelected(false);
        selectedPiece = nullptr; // Reset selectedPiece after the move
    }
}

bool WhenButtonPressed(std::vector<c_pieces> pieces, int i, Vector2 offset, Vector2 mousePosition){
    // Check if left mouse button is pressed
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

        std :: cout << pieces[i].cp -> getType() << std:: endl;
        pieces[i].cp->setSelected(true);
        selectedPiece = pieces[i].cp;
        index = i;
        offset.x = mousePosition.x - pieces[i].dr->x;
        offset.y = mousePosition.y - pieces[i].dr->y;
        printf("Index i : %d \n",index);
        printf("Selected Piece Type: %s \n",selectedPiece -> getType().c_str());
        printf("Offset : (%f, %f)\n", offset.x, offset.y);
        return true;
    }
    return false;
}

void HandleChessPieceSelection(std::vector<c_pieces>& pieces, Vector2 offset) {
    Vector2 mousePosition = GetMousePosition();
    // Deselect all pieces first
    for (int i = 0; i < pieces.size(); ++i) {
        pieces[i].cp->setSelected(false);
    }

    // Check for mouse click on any piece and select it
    for (int i = 0; i < pieces.size(); ++i) {
        if(!pieces[i].cp->isCaptured){
            bool isMouseClickedOnImage = CheckCollisionPointRec(mousePosition, *pieces[i].dr);
            if(turnCount % 2 == 0){
                if(pieces[i].cp->isWhite && isMouseClickedOnImage){
                    if(WhenButtonPressed(pieces,i,offset,mousePosition)){
                        break;
                    }
                }
            }
            else{
                if(!pieces[i].cp->isWhite && isMouseClickedOnImage){
                    if(WhenButtonPressed(pieces,i,offset,mousePosition)){
                        break;
                    }
                }
            }
            /*
            if (isMouseClickedOnImage) {
                // Check if left mouse button is pressed
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    turnCount++;
                    std :: cout << pieces[i].cp -> getType() << std:: endl;
                    pieces[i].cp->setSelected(true);
                    selectedPiece = pieces[i].cp;
                    index = i;
                    offset.x = mousePosition.x - pieces[i].dr->x;
                    offset.y = mousePosition.y - pieces[i].dr->y;
                    printf("Index i : %d \n",index);
                    printf("Selected Piece Type: %s \n",selectedPiece -> getType().c_str());
                    printf("Offset : (%f, %f)\n", offset.x, offset.y);
                    break; // Break the loop after selecting one piece
                }
            }
            */
        }
    }

    // Update position if dragging
    if(selectedPiece){
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            selectedPiece->setSelected(true);
            pieces[index].dr->x = mousePosition.x - offset.x;
            pieces[index].dr->y = mousePosition.y - offset.y;
            printf("Pieces Rectangle (%f,%f)\n", pieces[index].dr->y, pieces[index].dr->x);
        }
        else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            CheckMoveValidityForSelectedPiece(pieces, Position(mousePosition.y / tile_size, mousePosition.x / tile_size));
        }
    }
}

void RenderChessPieceImage(const std::vector<c_pieces>& pieces){
    for (int i = 0; i < pieces.size(); i++) {
        if(pieces[i].cp->isCaptured == false){
            switch (pieces[i].cp->type)
            {
                case KING:
                {
                    if(pieces[i].cp->isWhite){
                        DrawTexturePro(imageK, sourceRectKing, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                    }
                    else{
                        DrawTexturePro(imageK2, sourceRectKing, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                    }
                }break;

                case QUEEN:
                {
                    if(pieces[i].cp->isWhite){
                        DrawTexturePro(imageQ, sourceRectQueen, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                    }
                    else{
                        DrawTexturePro(imageQ2, sourceRectQueen, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                    }
                }break;

                case ROOK:
                {
                    if(pieces[i].cp->isWhite){
                        if(i == 2){
                            DrawTexturePro(imageR1, sourceRectRook, *(pieces[i].dr), Vector2{-20, -20}, 0, WHITE);
                        }
                        else if (i == 3){
                            DrawTexturePro(imageR2, sourceRectRook, *(pieces[i].dr), Vector2{-20, -20}, 0, WHITE);
                        }
                    }
                    else {
                        if(i == 18){
                            DrawTexturePro(image_r1, sourceRectRook, *(pieces[i].dr), Vector2{-20, -20}, 0, WHITE);
                        }
                        else if (i == 19){
                            DrawTexturePro(image_r2, sourceRectRook, *(pieces[i].dr), Vector2{-20, -20}, 0, WHITE);
                        }
                    }
                }break;

                case KNIGHT:
                {
                    if(pieces[i].cp->isWhite){
                        if(i == 4){
                            DrawTexturePro(imageKn1, sourceRectKnight, *(pieces[i].dr), Vector2{-15, -20}, 0, WHITE);
                        }
                        else if (i == 5){
                            DrawTexturePro(imageKn2, sourceRectKnight, *(pieces[i].dr), Vector2{-15, -20}, 0, WHITE);
                        }
                    }
                    else {
                        if(i == 20){
                            DrawTexturePro(image_kn1, sourceRectKnight, *(pieces[i].dr), Vector2{-15, -20}, 0, WHITE);
                        }
                        else if (i == 21){
                            DrawTexturePro(image_kn2, sourceRectKnight, *(pieces[i].dr), Vector2{-15, -20}, 0, WHITE);
                        }
                    }
                }break;

                case BISHOP:
                {
                    if(pieces[i].cp->isWhite){
                        if(i == 6){
                            DrawTexturePro(imageB1, sourceRectBishop, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                        }
                        else if (i == 7){
                            DrawTexturePro(imageB2, sourceRectBishop, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                        }
                    }
                    else {
                        if(i == 22){
                            DrawTexturePro(image_b1, sourceRectBishop, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                        }
                        else if (i == 23){
                            DrawTexturePro(image_b2, sourceRectBishop, *(pieces[i].dr), Vector2{-10, -10}, 0, WHITE);
                        }
                    }
                }break;

                case PAWN:
                {
                    if(pieces[i].cp->isWhite){
                        if(i > 7 && i < 17) {
                            DrawTexturePro(imageP, sourceRectPawn, *(pieces[i].dr), Vector2{-25, -20}, 0, WHITE);
                        }
                    }
                    else {
                        if(i > 23 && i < 32) {
                            DrawTexturePro(image_p, sourceRectPawn, *(pieces[i].dr), Vector2{-25, -20}, 0, WHITE);
                        }
                    }
                }break;
            }
        }
    }
}


int main() {
    InitWindow(W_WIDTH, W_HEIGHT, "Chess");
    SetTargetFPS(60);

    ChessBoard c = ChessBoard();

    InitTextures();
    /*
    Texture2D imageR1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    Texture2D imageR2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    Texture2D imageB1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    Texture2D imageB2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    Texture2D imageKn1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    Texture2D imageKn2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    Texture2D imageK = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_king_2x_ns.png");
    Texture2D imageQ = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    Texture2D imageP = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    Texture2D image_r1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    Texture2D image_r2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    Texture2D image_b1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    Texture2D image_b2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    Texture2D image_kn1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    Texture2D image_kn2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    Texture2D imageK2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_king_2x_ns.png");
    Texture2D imageQ2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    Texture2D image_p = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_pawn_2x_ns.png");


    Image rookWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    Image bishopWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    Image knightWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    Image kingWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_king_2x_ns.png");
    Image queenWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    Image pawnWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    Image rookBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    Image bishopBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    Image knightBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    Image kingBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_king_2x_ns.png");
    Image queenBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    Image pawnBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_pawn_2x_ns.png");

    Rectangle sourceRectKing = {0, 0, (float) kingWImage.width, (float) kingWImage.height};  // Entire image
    Rectangle sourceRectQueen = {0, 0, (float) queenWImage.width, (float) queenWImage.height};
    Rectangle sourceRectRook = {0, 0, (float) rookWImage.width, (float) rookWImage.height};
    Rectangle sourceRectBishop = {0, 0, (float) bishopWImage.width, (float) bishopWImage.height};
    Rectangle sourceRectKnight = {0, 0, (float) knightWImage.width, (float) knightWImage.height};
    Rectangle sourceRectPawn = {0, 0, (float) pawnWImage.width, (float) pawnWImage.height};
    */
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

    std :: vector<c_pieces> pieces = {
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
