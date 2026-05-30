#include "Board.h"
#include <algorithm>

Board::Board() 
{
    Clear();
}

void Board::Clear() 
{
    for (auto& row : grid) {
        row.fill(0);
    }
}

bool Board::Board::IsInsideBounds(int col, int row) const 
{
    return col >= 0 && col < COLS && row >= 0 && row < ROWS;
}

bool Board::IsCellOccupied(int col, int row) const 
{
    return grid[row][col] != 0;
}

bool Board::IsValidPosition(const Tetromino& piece) const 
{
    for (auto& [col, row] : piece.GetCells())
    {
        if (!IsInsideBounds(col, row)) return false;
        if (IsCellOccupied(col, row)) return false;
    }
    return true;
}

void Board::PlacePiece(const Tetromino& piece)
{
    int colorIndex = static_cast<int>(piece.type) + 1; // 0 boş

    for (auto& [col, row] : piece.GetCells())
    grid[row][col] = colorIndex;
}

int Board::ClearLines()
{
    int cleared = 0;

    for (int row = ROWS - 1; row >= 0; row--)
    {
        bool full = std::all_of(grid[row].begin(), grid[row].end(),
                                [](int cell){ return cell != 0; });
        if (!full) continue;

        // Dolu satırı sil: üstündeki her şeyi bir aşağı kaydır
        for (int r = row; r > 0; r--)
            grid[r] = grid[r - 1];

        grid[0].fill(0); // en üst satırı temizle
        cleared++;
        row++; // aynı satırı tekrar kontrol et (kayma oldu)
    }

    return cleared;
}
