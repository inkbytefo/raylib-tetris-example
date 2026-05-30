#pragma once
#include "raylib.h"
#include <vector>


enum class TetrominoType { I, O, T, S, Z, J, L, COUNT };

struct Tetromino 
{
    TetrominoType type;
    int x, y;
    int rotation;

    /* Aktif rotasyonun hücre listesini döndürür */
    /* Her eleman { col_offset, row_offset } */

    std::vector<std::pair<int,int>> GetCells() const;

    void RotateCW(); // Saat yönünde döndürür
    void RotateCCW(); // Saat yönünün tersine döndürür
};

// parça şekilleri
extern const std::vector<std::vector<std::vector<std::pair<int,int>>>> SHAPES;

// parça renkleri

extern const Color COLORS[];