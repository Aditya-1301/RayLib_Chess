#include "utilities.h"

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
    imageR1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    imageR2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    imageB1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    imageB2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    imageKn1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    imageKn2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    imageK = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_king_2x_ns.png");
    imageQ = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    imageP = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    image_r1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    image_r2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    image_b1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    image_b2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    image_kn1 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    image_kn2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    imageK2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_king_2x_ns.png");
    imageQ2 = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    image_p = LoadTexture("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_pawn_2x_ns.png");


    rookWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_rook_2x_ns.png");
    bishopWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_bishop_2x_ns.png");
    knightWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_knight_2x_ns.png");
    kingWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_king_2x_ns.png");
    queenWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_queen_2x_ns.png");
    pawnWImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\w_pawn_2x_ns.png");

    rookBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_rook_2x_ns.png");
    bishopBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_bishop_2x_ns.png");
    knightBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_knight_2x_ns.png");
    kingBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_king_2x_ns.png");
    queenBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_queen_2x_ns.png");
    pawnBImage = LoadImage("D:\\RayLib\\Chess_CPP\\raylib_template\\src\\res\\b_pawn_2x_ns.png");

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

std :: vector<c_pieces> returnPieces(){
    return pieces;
}