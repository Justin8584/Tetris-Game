#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
	Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;

private:
	std::vector<Block> GetAllBlocks();
	Block GetRandomBlock();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockUp();
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFix();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	std::vector<Block> blocks;
	Grid grid;
	Block currentBlock;
	Block nextBlock;
};
