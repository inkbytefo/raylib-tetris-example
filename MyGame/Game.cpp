#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game()
    : score(0), level(1), dropTimer(0.0f), dropInterval(0.8f), isGameOver(false)
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    SpawnPiece();
}

void Game::SpawnPiece()
{
	int randomType = std::rand() % static_cast<int>(TetrominoType::COUNT);

	current.type 		= static_cast<TetrominoType>(randomType);
	current.x 			= COLS / 2 - 2; // başlangıçta ortalayarak
	current.y 			= 0;
	current.rotation 	= 0;

	if (!board.IsValidPosition(current))
		isGameOver = true; // Yeni parça yerleştirilemiyorsa oyun biter
}

void Game::HandleInput()
{
    if (isGameOver) return;

    // Yatay hareket
    if (IsKeyPressed(KEY_LEFT))
    {
        current.x--;
        if (!board.IsValidPosition(current))
            current.x++;
    }

    if (IsKeyPressed(KEY_RIGHT))
    {
        current.x++;
        if (!board.IsValidPosition(current))
            current.x--;
    }

    // Hızlı düşüş
    if (IsKeyPressed(KEY_DOWN))
    {
        current.y++;
        if (!board.IsValidPosition(current))
        {
            current.y--;
            LockPiece();
        }
    }

    // Rotasyon
    if (IsKeyPressed(KEY_UP))
    {
        current.RotateCW();
        if (!board.IsValidPosition(current))
            current.RotateCCW(); // geri al
    }

    // Hard drop (space)
    if (IsKeyPressed(KEY_SPACE))
    {
        while (board.IsValidPosition(current))
            current.y++;

        current.y--; // son geçerli pozisyona geri dön
        LockPiece();
    }
}

void Game::DropPiece()
{
    if (isGameOver) return;

    dropTimer += GetFrameTime();

    if (dropTimer >= dropInterval)
    {
        dropTimer = 0.0f;
        current.y++;

        if (!board.IsValidPosition(current))
        {
            current.y--;
            LockPiece();
        }
    }
}

void Game::LockPiece()
{
    board.PlacePiece(current);

    int cleared = board.ClearLines();

    // Skor: klasik Tetris puanlama
    const int points[] = {0, 100, 300, 500, 800};
    score += points[cleared] * level;

    UpdateLevel();
    SpawnPiece();
}

void Game::UpdateLevel()
{
    level = score / 1000 + 1;
    dropInterval = 0.8f - (level - 1) * 0.07f;

    if (dropInterval < 0.1f)
        dropInterval = 0.1f; // minimum hız sınırı
}

void Game::Update()
{
    if (isGameOver) return;

    HandleInput();
    DropPiece();
}

void Game::Draw() const
{
    renderer.DrawBoard(board);

    if (!isGameOver)
        renderer.DrawTetromino(current);
    else
        DrawText("GAME OVER", COLS * CELL_SIZE / 2 - 60, ROWS * CELL_SIZE / 2, 24, RED);

    renderer.DrawUI(score, level);
}