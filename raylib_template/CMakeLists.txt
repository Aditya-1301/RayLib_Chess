cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(raylib_template/include)

add_executable(Chess
        raylib_template/include/raylib.h
        raylib_template/src/main.cpp
        raylib_template/src/chessBoard.cpp
        raylib_template/src/chessPiece.cpp
        raylib_template/src/rook.cpp
        raylib_template/src/king.cpp
        raylib_template/src/queen.cpp
        raylib_template/src/pawn.cpp
        raylib_template/src/knight.cpp
        raylib_template/src/bishop.cpp
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


