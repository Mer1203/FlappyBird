#include "ScreenManager.h"

#include <raylib.h>

#include "MainMenu.h"
#include "Credits.h"
#include "Game.h"

namespace flappyBird
{
	void showScreen()
	{
		InitWindow(1024, 768, "Floppy:El Pajaro que Vuela Remaster Editon");
		InitAudioDevice();

		Screen actualScreen = Screen::MAIN_MENU;
		Player playerOne;
		Player playerTwo;
		bool inGame = true;
		Obstacle obstacles[MAX_OBSTACLES];
		ParallaxBackground backGround = { 0 };

		//MUSICA:
		Music menuMusic = LoadMusicStream("res/Sounds/musica-elevador-short.mp3");

		initGame(playerOne, playerTwo, obstacles, backGround);

		while (!WindowShouldClose() && inGame)
		{
			BeginDrawing();
			if (actualScreen == Screen::MAIN_MENU)
			{
				ClearBackground(BLACK);
				showMainMenu(actualScreen, menuMusic);
			}
			else if (actualScreen == Screen::PLAY)
			{
				if (playerOne.isDead || playerTwo.isDead)
				{
					initGame(playerOne, playerTwo, obstacles, backGround);
				}

				playGame(playerOne, playerTwo, obstacles, actualScreen, backGround);
			}
			else if (actualScreen == Screen::CREDITS)
			{
				ClearBackground(BLACK);
				showCredits(actualScreen);
			}
			else if (actualScreen == Screen::EXIT)
			{
				inGame = false;
			}
		
			EndDrawing();
		}

		CloseAudioDevice();
		UnloadMusicStream(menuMusic);
		unloadBackground(backGround);
		UnloadTexture(playerOne.Bird);
		UnloadTexture(playerTwo.Bird);
		CloseWindow();
	}
}