#pragma once
#include "Board.h"
#include "Tetromino.h"
#include "Renderer.h"

class Game {
private:
    Board board;
    Tetromino current;
    Renderer renderer;

    int score;
    int level;
    float dropTimer;     // son düşüşten bu yana geçen süre
    float dropInterval;  // kaç saniyede bir düşsün
    bool isGameOver;

    void SpawnPiece();
    void HandleInput();
    void DropPiece();    // her tick'te bir aşağı indir
    void LockPiece();    // yere yapış, yeni parça üret
    void UpdateLevel();

public:
    Game();

    void Update();
    void Draw() const;
};