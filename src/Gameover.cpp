#include "Gameover.h"
#include <raylib.h>
#include "Screen.h"
#include "Button.h"

namespace flappyBird
{
	void DrawGameOver(Screen& actualScreen, bool isMultiplayer,
		Player& playerOne, Player& playerTwo)
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

		const char* playerOneText = TextFormat(
			"Player 1 Score: %i",
			(int)playerOne.score
		);

		float playerFontSize = 35.0f;

		Vector2 playerOneTextSize = MeasureTextEx(
			defaultFont,
			playerOneText,
			playerFontSize,
			spacing
		);

		float playerOneTextX;

		if (isMultiplayer)
		{
			playerOneTextX = (screenWidth / 4.0f) -
				(playerOneTextSize.x / 2.0f);
		}
		else
		{
			playerOneTextX = (screenWidth / 2.0f) -
				(playerOneTextSize.x / 2.0f);
		}

		float playerTextY = 380.0f;

		DrawTextEx(
			defaultFont,
			playerOneText,
			{ playerOneTextX, playerTextY },
			playerFontSize,
			spacing,
			WHITE
		);

		if (isMultiplayer)
		{
			const char* playerTwoText = TextFormat(
				"Player 2 Score: %i",
				(int)playerTwo.score
			);

			Vector2 playerTwoTextSize = MeasureTextEx(
				defaultFont,
				playerTwoText,
				playerFontSize,
				spacing
			);

			float playerTwoTextX =
				(3.0f * screenWidth / 4.0f) -
				(playerTwoTextSize.x / 2.0f);

			DrawTextEx(
				defaultFont,
				playerTwoText,
				{ playerTwoTextX, playerTextY },
				playerFontSize,
				spacing,
				WHITE
			);
		}


		Button tryAgainButton;
		Button returnMenuButton;

		tryAgainButton.width = 200;
		tryAgainButton.high = 50;
		tryAgainButton.x = (screenWidth / 2) - tryAgainButton.width - 15;
		tryAgainButton.y = 550;
		tryAgainButton.text = "TRY AGAIN";

		returnMenuButton.width = 200;
		returnMenuButton.high = 50;
		returnMenuButton.x = (screenWidth / 2) + 15;
		returnMenuButton.y = 550;
		returnMenuButton.text = "RETURN TO MENU";

		if (onClick(tryAgainButton))
		{
			actualScreen = Screen::PLAY;
		}
		else if (onClick(returnMenuButton))
		{
			actualScreen = Screen::MENU;
		}

		float button1FontSize = 30.0f;
		float button2FontSize = 22.0f;

		DrawRectangle(
			tryAgainButton.x,
			tryAgainButton.y,
			tryAgainButton.width,
			tryAgainButton.high,
			RED
		);

		Vector2 tryAgainTextSize = MeasureTextEx(
			defaultFont,
			tryAgainButton.text.c_str(),
			button1FontSize,
			spacing
		);

		DrawTextEx(
			defaultFont,
			tryAgainButton.text.c_str(),
			{
				static_cast<float>(tryAgainButton.x) +
				(tryAgainButton.width - tryAgainTextSize.x) / 2.0f,

				static_cast<float>(tryAgainButton.y) +
				(tryAgainButton.high - tryAgainTextSize.y) / 2.0f
			},
			button1FontSize,
			spacing,
			RAYWHITE
		);

		DrawRectangle(
			returnMenuButton.x,
			returnMenuButton.y,
			returnMenuButton.width,
			returnMenuButton.high,
			RED
		);

		Vector2 returnMenuTextSize = MeasureTextEx(
			defaultFont,
			returnMenuButton.text.c_str(),
			button2FontSize,
			spacing
		);

		DrawTextEx(
			defaultFont,
			returnMenuButton.text.c_str(),
			{
				static_cast<float>(returnMenuButton.x) +
				(returnMenuButton.width - returnMenuTextSize.x) / 2.0f,

				static_cast<float>(returnMenuButton.y) +
				(returnMenuButton.high - returnMenuTextSize.y) / 2.0f
			},
			button2FontSize,
			spacing,
			RAYWHITE
		);

	}
}