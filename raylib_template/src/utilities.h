//
// Created by agupt on 19/11/2023.
//
#pragma once

#include "raylib.h"
#include "ChessPiece.h"
#include <vector>
#include <iostream>
using namespace ChessPiece_N;

namespace Utilities_N{

    #define W_WIDTH 800
    #define W_HEIGHT 800

    #define tile_size 100

    typedef struct piece {
        ChessPiece* cp;
        Rectangle* dr;
    } c_pieces;

    extern ChessPiece* selectedPiece;
    extern std::vector<c_pieces> pieces;
    extern int index;
    extern int turnCount;

    inline Texture2D imageR1;
    inline Texture2D imageR2;
    inline Texture2D imageB1;
    inline Texture2D imageB2;
    inline Texture2D imageKn1;
    inline Texture2D imageKn2;
    inline Texture2D imageK;
    inline Texture2D imageQ;
    inline Texture2D imageP;

    inline Texture2D image_r1;
    inline Texture2D image_r2;
    inline Texture2D image_b1;
    inline Texture2D image_b2;
    inline Texture2D image_kn1;
    inline Texture2D image_kn2;
    inline Texture2D imageK2;
    inline Texture2D imageQ2;
    inline Texture2D image_p;

    inline Image rookWImage;
    inline Image bishopWImage;
    inline Image knightWImage;
    inline Image kingWImage;
    inline Image queenWImage;
    inline Image pawnWImage;

    inline Image rookBImage;
    inline Image bishopBImage;
    inline Image knightBImage;
    inline Image kingBImage;
    inline Image queenBImage;
    inline Image pawnBImage;

    inline Rectangle sourceRectKing;
    inline Rectangle sourceRectQueen;
    inline Rectangle sourceRectRook;
    inline Rectangle sourceRectBishop;
    inline Rectangle sourceRectKnight;
    inline Rectangle sourceRectPawn;

    void boardColorsSet(std::vector<std::vector<Color>>& boardColors);
    void RenderChessBoard();
    void InitTextures();
    void UnloadTextures();
    bool IsSameColor(std::vector<c_pieces> pieces, ChessPiece* selectedPiece, Position dest);
    int SetCapturedIndices(std::vector<c_pieces> pieces, Position dest);
    void CheckMoveValidityForSelectedPiece(std::vector<c_pieces>& pieces, Position dest);
    bool WhenButtonPressed(std::vector<c_pieces> pieces, int i, Vector2 offset, Vector2 mousePosition);
    void HandleChessPieceSelection(std::vector<c_pieces>& pieces, Vector2 offset);
    void RenderChessPieceImage(const std::vector<c_pieces>& pieces);
    std::vector<c_pieces> returnPieces();

}

