#include "Gameover.h"
#include <raylib.h>
#include "Screen.h"

namespace flappyBird
{
	void DrawGameOver()
	{
		const char* titleOne = "GAME OVER\n\n";
		float titleFontSize = 80.0f;

		Font defaultFont = GetFontDefault();
		float spacing = 1.0f;

		Vector2 titleSize = MeasureTextEx(
			defaultFont,
			titleOne,
			titleFontSize,
			spacing
		);

		float titleX = (static_cast<float>(screenWidth) / 2.0f) - (titleSize.x / 2.0f);
		float titleY = 230.0f;

		DrawTextEx(
			defaultFont,
			titleOne,
			{ titleX, titleY },
			titleFontSize,
			spacing,
			RED
		);

		const char* playerOneText = "Player 1 Score: \n\n";
		float playerOneFontSize = 60.0f;

		Vector2 playerOneTextSize = MeasureTextEx(
			defaultFont,
			titleOne,
			titleFontSize,
			spacing
		);

		float playerOneTextX = (static_cast<float>(screenWidth) / 4.0f) - (titleSize.x / 2.0f);
		float playerOneTextY = 350.0f;

		DrawTextEx(
			defaultFont,
			playerOneText,
			{ playerOneTextX, playerOneTextY },
			playerOneFontSize,
			spacing,
			WHITE
		);

		const char* playerTwoText = "Player 2 Score: \n\n";
		float playerTwoFontSize = 60.0f;

		Vector2 playerTwoTextSize = MeasureTextEx(
			defaultFont,
			titleOne,
			titleFontSize,
			spacing
		);

		float playerTwoTextX = (static_cast<float>(screenWidth) / 4.0f) - (titleSize.x / 2.0f);
		float playerTwoTextY = 430.0f;

		DrawTextEx(
			defaultFont,
			playerTwoText,
			{ playerTwoTextX, playerTwoTextY },
			playerTwoFontSize,
			spacing,
			WHITE
		);

	}
}