//
// Created by agupt on 19/11/2023.
//
#pragma once

#include "raylib.h"
#include "ChessPiece.h"
#include <vector>
#include <iostream>

#define W_WIDTH 800 //500
#define W_HEIGHT 800 //500

#define tile_size 100

#ifndef CHESS_CPP_UTILITIES_H
#define CHESS_CPP_UTILITIES_H

typedef struct piece{
    ChessPiece * cp;
    Rectangle * dr;
} c_pieces;

ChessPiece * selectedPiece = nullptr;
std :: vector<c_pieces> pieces;
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

void boardColorsSet(std::vector<std::vector<Color>>& boardColors);
void RenderChessBoard();
void InitTextures();
void UnloadTextures();
bool IsSameColor(std::vector<c_pieces> pieces, ChessPiece * selectedPiece, Position dest);
int SetCapturedIndices(std::vector<c_pieces> pieces, Position dest);
void CheckMoveValidityForSelectedPiece(std::vector<c_pieces>& pieces, Position dest);
bool WhenButtonPressed(std::vector<c_pieces> pieces, int i, Vector2 offset, Vector2 mousePosition);
void HandleChessPieceSelection(std::vector<c_pieces>& pieces, Vector2 offset);
void RenderChessPieceImage(const std::vector<c_pieces>& pieces);
std :: vector<c_pieces> returnPieces();

#endif //CHESS_CPP_UTILITIES_H
