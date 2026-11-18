#include "MainMenu.h"
#include <raylib.h>
#include "Button.h"

namespace flappyBird
{
	void showMainMenu(Screen& actualScreen, Music menuMusic, Sound playButtonSound)
	{
		// 1. Obtener la fuente por defecto de Raylib
		Font defaultFont = GetFontDefault();

		// 2. Configuración de botones
		Button playButton;
		Button creditsButton;
		Button exitButton;

		float sw = static_cast<float>(GetScreenWidth());

		if (!IsMusicStreamPlaying(menuMusic))
		{
			SetMusicVolume(menuMusic, 0.5f);
			PlayMusicStream(menuMusic);
		}
		else
		{
			UpdateMusicStream(menuMusic);
		}

		const char* title = "FLOPPY: EL PAJARO QUE VUELA";
		const char* title2 = "REMASTER EDITION";
		float titleFontSize = 40.0f;
		float title2FontSize = 30.0f;
		float spacing = 1.0f;

		Vector2 titleSize = MeasureTextEx(defaultFont, title, titleFontSize, spacing);
		float titleX = (sw / 2.0f) - (titleSize.x / 2.0f);
		float titleY = 30.0f;

		Vector2 title2Size = MeasureTextEx(defaultFont, title2, title2FontSize, spacing);
		float title2X = (sw / 2.0f) - (title2Size.x / 2.0f);
		float title2Y = titleY + titleSize.y + 10.0f;

		ButtonInit(playButton, creditsButton, exitButton);

		if (onClick(playButton))
		{
			if (!playButton.isSoundPlaying)
			{
				if (!IsSoundPlaying(playButtonSound))
				{
					SetSoundVolume(playButtonSound, 8.0f);
					PlaySound(playButtonSound);
					playButton.isSoundPlaying = true;
				}
			}
			else
			{
				playButton.isSoundPlaying = false;
			}

			actualScreen = Screen::PLAY;
		}
		else if (onClick(creditsButton))
		{
			actualScreen = Screen::CREDITS;
		}
		else if (onClick(exitButton))
		{
			actualScreen = Screen::EXIT;
		}

		float buttonFontSize = 20.0f;

		DrawRectangle(playButton.x, playButton.y, playButton.width, playButton.high, RED);
		Vector2 playTextSize = MeasureTextEx(defaultFont, playButton.text.c_str(), buttonFontSize, spacing);
		DrawTextEx(
			defaultFont,
			playButton.text.c_str(),
			{
				static_cast<float>(playButton.x) + (playButton.width - playTextSize.x) / 2.0f,
				static_cast<float>(playButton.y) + (playButton.high - playTextSize.y) / 2.0f
			},
			buttonFontSize,
			spacing,
			RAYWHITE
		);

		DrawRectangle(creditsButton.x, creditsButton.y, creditsButton.width, creditsButton.high, RED);
		Vector2 creditsTextSize = MeasureTextEx(defaultFont, creditsButton.text.c_str(), buttonFontSize, spacing);
		DrawTextEx(
			defaultFont,
			creditsButton.text.c_str(),
			{
				static_cast<float>(creditsButton.x) + (creditsButton.width - creditsTextSize.x) / 2.0f,
				static_cast<float>(creditsButton.y) + (creditsButton.high - creditsTextSize.y) / 2.0f
			},
			buttonFontSize,
			spacing,
			RAYWHITE
		);

		DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
		Vector2 exitTextSize = MeasureTextEx(defaultFont, exitButton.text.c_str(), buttonFontSize, spacing);
		DrawTextEx(
			defaultFont,
			exitButton.text.c_str(),
			{
				static_cast<float>(exitButton.x) + (exitButton.width - exitTextSize.x) / 2.0f,
				static_cast<float>(exitButton.y) + (exitButton.high - exitTextSize.y) / 2.0f
			},
			buttonFontSize,
			spacing,
			RAYWHITE
		);


		DrawTextEx(defaultFont, title, { titleX, titleY }, titleFontSize, spacing, RED);
		DrawTextEx(defaultFont, title2, { title2X, title2Y }, title2FontSize, spacing, YELLOW);

		DrawText("v0.4", 20, 20, 30, WHITE);
	}
}