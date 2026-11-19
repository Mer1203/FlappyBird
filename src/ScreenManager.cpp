#include "ScreenManager.h"

#include <raylib.h>

#include "MainMenu.h"
#include "Credits.h"
#include "Game.h"
#include "Rules.h"
#include "Pipe.h"
#include "Gameover.h"

namespace flappyBird
{
	void showScreen()
	{
		InitWindow(1024, 768, "Floppy:El Pajaro que Vuela Remaster Editon");
		InitAudioDevice();

		Screen actualScreen = Screen::MENU;
		Player playerOne = {};
		Player playerTwo = {};

		bool inGame = true;
		bool isMultiplayer = false;
		bool gameNeedsInit = true;

		Obstacle obstacles[MAX_OBSTACLES];
		ParallaxBackground backGround = { 0 };
		Texture2D blackBackground = LoadTexture("res/Black_Background.png");

		//MUSICA:
		Music menuMusic = LoadMusicStream("res/Sounds/musica-elevador-short.mp3");
		Music gameplayMusic = LoadMusicStream("res/Sounds/po-pi-po-2.mp3");

		//SONIDO:
		Sound playButtonSound = LoadSound("res/Sounds/mercadopago-transferencia-ok.mp3");
		Sound creditsButtonSound = LoadSound("res/Sounds/anime-wow-sound-effect.mp3");
		Sound rulesButtonSound = LoadSound("res/Sounds/discord-user-joined-sound-effect.mp3");
		Sound exitButtonSound = LoadSound("res/Sounds/y2mate_VKI8qDn.mp3");
		Sound gameoverSound = LoadSound("res/Sounds/metal-pipe-clang.mp3");

		initGame(playerOne, playerTwo, obstacles, backGround, isMultiplayer);

		while (!WindowShouldClose() && inGame)
		{
			SetMasterVolume(0.3f);

			BeginDrawing();
			if (actualScreen == Screen::MENU)
			{
				ClearBackground(BLACK);
				showMainMenu(actualScreen, menuMusic, playButtonSound,
					rulesButtonSound, creditsButtonSound, exitButtonSound);

			}
			else if (actualScreen == Screen::PLAY)
			{
				if (gameNeedsInit || playerOne.isDead ||
					(isMultiplayer && playerTwo.isDead))
				{
					initGame(playerOne, playerTwo, obstacles, backGround, isMultiplayer);

					gameNeedsInit = false;
				}

				playGame(playerOne, playerTwo, obstacles, actualScreen,
					backGround, gameplayMusic, isMultiplayer, gameoverSound);
			}
			else if (actualScreen == Screen::CREDITS)
			{
				ClearBackground(BLACK);
				showCredits(actualScreen);
			}
			else if (actualScreen == Screen::RULES)
			{
				ClearBackground(BLACK);
				showRules(actualScreen, isMultiplayer);

				if (actualScreen == Screen::PLAY)
				{
					gameNeedsInit = true;
				}
			}
			else if (actualScreen == Screen::GAMEOVER)
			{
				DrawGame(backGround, obstacles, playerOne, playerTwo, isMultiplayer);
				DrawTexture(blackBackground, 0, 0, WHITE);

				DrawGameOver(actualScreen, isMultiplayer, playerOne, playerTwo);
			}
			else if (actualScreen == Screen::PAUSE)
			{
				DrawGame(backGround, obstacles, playerOne, playerTwo, isMultiplayer);
				DrawTexture(blackBackground, 0, 0, WHITE);

			}
			else if (actualScreen == Screen::EXIT)
			{
				inGame = false;
			}

			EndDrawing();
		}

		UnloadMusicStream(menuMusic);
		UnloadMusicStream(gameplayMusic);
		UnloadSound(playButtonSound);
		UnloadSound(creditsButtonSound);
		UnloadSound(rulesButtonSound);
		UnloadSound(gameoverSound);
		unloadBackground(backGround);

		UnloadTexture(playerOne.Bird);
		UnloadTexture(playerTwo.Bird);

		CloseAudioDevice();

		CloseWindow();
	}
}