#pragma once
#include "Board.h"
#include "Tetromino.h"

class Renderer 
{
private:
    void DrawCell(int col, int row, Color color) const;
public:
    void DrawBoard(const Board& board) const;
    void DrawTetromino(const Tetromino& piece) const;
    void DrawUI(int score, int level) const;
};