cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(raylib_template/include)

add_executable(Chess
        raylib_template/include/raylib.h
        raylib_template/src/main.cpp
        raylib_template/src/ChessBoard.cpp
        raylib_template/src/ChessPiece.cpp
        raylib_template/src/Rook.cpp
        raylib_template/src/King.cpp
        raylib_template/src/Queen.cpp
        raylib_template/src/Pawn.cpp
        raylib_template/src/Knight.cpp
        raylib_template/src/Bishop.cpp
        raylib_template/src/utilities.cpp
)

# Link your executable with raylib
# Find and set the appropriate library path for your platform (e.g., raylib.lib for Windows, libraylib.a for macOS/Linux)
if(WIN32)
    find_library(RAYLIB_LIBRARY raylib "${CMAKE_SOURCE_DIR}/raylib_template/lib")
elseif(APPLE)
    find_library(RAYLIB_LIBRARY raylib "${CMAKE_SOURCE_DIR}/raylib_template/lib")
else()
    find_library(RAYLIB_LIBRARY raylib "${CMAKE_SOURCE_DIR}/raylib_template/lib")
endif()

# Make sure the library is found
if(NOT RAYLIB_LIBRARY)
    message(FATAL_ERROR "raylib library not found!")
endif()

# Add raylib-specific flags for Windows to avoid undefined references
if(WIN32)
    target_link_libraries(Chess PUBLIC ${RAYLIB_LIBRARY} -static -lwinmm -lgdi32)
else()
    target_link_libraries(Chess PUBLIC ${RAYLIB_LIBRARY})
endif()


