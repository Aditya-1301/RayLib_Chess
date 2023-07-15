cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(raylib_template/include)
include_directories(raylib_template/src)

add_executable(Chess
        raylib_template/include/raylib.h
        raylib_template/src/bishop.cpp
        raylib_template/src/chessBoard.cpp
        raylib_template/src/chessPiece.cpp
        raylib_template/src/headers.h
        raylib_template/src/king.cpp
        raylib_template/src/knight.cpp
        raylib_template/src/main.cpp
        raylib_template/src/main_logic.cpp
        raylib_template/src/pawn.cpp
        raylib_template/src/queen.cpp
        raylib_template/src/rook.cpp)
