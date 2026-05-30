#include "Renderer.h"


void Renderer::DrawCell(int col, int row, Color color) const
{
    int x = col * CELL_SIZE;
    int y = row * CELL_SIZE;

    DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, color);
    DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
}

void Renderer::DrawBoard(const Board& board) const
{
    const Grid& grid = board.GetGrid();

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            int cell = grid[row][col];

            if (cell == 0)
            DrawRectangleLines(col * CELL_SIZE, row * CELL_SIZE, CELL_SIZE, CELL_SIZE, LIGHTGRAY);
            else
            DrawCell(col, row, COLORS[cell - 1]);
        }
    }
}

void Renderer::DrawTetromino(const Tetromino& piece) const
{
    Color color = COLORS[static_cast<int>(piece.type)];

    for (auto& [col, row] : piece.GetCells())
        DrawCell(col, row, color);
}

void Renderer::DrawUI(int score, int level) const
{
    int panelX = COLS * CELL_SIZE + 20;

    DrawText("SCORE", panelX, 20, 18, DARKGRAY);
    DrawText(TextFormat("%d", score), panelX, 45, 22, BLACK);

    DrawText("LEVEL", panelX, 90, 18, DARKGRAY);
    DrawText(TextFormat("%d", level), panelX, 115, 22, BLACK);
}