#include "colors.h"
#include "game.h"
#include <iostream>
#include <raylib.h>

double lastUpdateTime = 0;
bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	constexpr int screenWidth = 1000;
	constexpr int screenHeight = 1050;

	InitWindow(screenWidth, screenHeight, "Raylib Tetris");
	SetTargetFPS(60);

	Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

	Game game = Game();

	while (WindowShouldClose() == false)
	{
		game.HandleInput();
		if (EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(darkBlue);

		// Positions
		int scoreBoxX = 680, scoreBoxY = 90, scoreBoxWidth = 150, scoreBoxHeight = 60;
		int nextBoxX = 650, nextBoxY = 250, nextBoxWidth = 220, nextBoxHeight = 220;

		// Score Label
		Vector2 scoreLabelSize = MeasureTextEx(font, "Score", 40, 2);
		DrawTextEx(font, "Score", { scoreBoxX + (scoreBoxWidth - scoreLabelSize.x) / 2, 50 }, 40, 2, WHITE);
		// Score Box
		DrawRectangleRounded({ (float)scoreBoxX, (float)scoreBoxY, (float)scoreBoxWidth, (float)scoreBoxHeight }, 0.3, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, "%d", game.score);
		Vector2 scoreTextSize = MeasureTextEx(font, scoreText, 38, 2);
		DrawTextEx(font, scoreText, { scoreBoxX + (scoreBoxWidth - scoreTextSize.x) / 2, scoreBoxY + (scoreBoxHeight - scoreTextSize.y) / 2 }, 38, 2, BLACK);

		// Next Label
		Vector2 nextLabelSize = MeasureTextEx(font, "Next", 40, 2);
		DrawTextEx(font, "Next", { nextBoxX + (nextBoxWidth - nextLabelSize.x) / 2, 200 }, 40, 2, WHITE);
		// Next Box
		DrawRectangleRounded({ (float)nextBoxX, (float)nextBoxY, (float)nextBoxWidth, (float)nextBoxHeight }, 0.3, 6, lightBlue);

		// Game Over Text
		if (game.gameOver)
		{
			const char* gameOverText = "GAME OVER";
			const char* restartText = "Press Any Key to Restart";
			Vector2 gameOverTextSize = MeasureTextEx(font, gameOverText, 38, 2);
			Vector2 restartTextSize = MeasureTextEx(font, restartText, 30, 2);

			float centerX = (scoreBoxX + nextBoxX + nextBoxWidth) / 2;

			DrawTextEx(font, gameOverText, { centerX - gameOverTextSize.x / 2, 800 }, 38, 2, WHITE);
			DrawTextEx(font, restartText, { centerX - restartTextSize.x / 2, 850 }, 30, 2, WHITE);
		}

		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}