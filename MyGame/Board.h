#pragma once 
#include "Tetromino.h"
#include <array>


constexpr int COLS = 10;
constexpr int ROWS = 20;
constexpr int CELL_SIZE = 30;

using Grid = std::array<std::array<int, COLS>, ROWS>;

class Board 
{
private:
    Grid grid;
    
    bool IsInsideBounds(int col, int row) const;
    bool IsCellOccupied(int col, int row) const;
public:
    Board();

    void Clear();

    bool IsValidPosition(const Tetromino& piece) const;

    void PlacePiece(const Tetromino& piece);

    int ClearLines();

    const Grid& GetGrid() const { return grid; }
};