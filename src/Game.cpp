#include "Game.h"
#include <raylib.h>
#include "Screen.h"

namespace flappyBird
{
	void checkCollision(Player& player, Pipe& pipe)
	{
		if (player.position.x + player.size.x >= (pipe.position.x) &&
			player.position.x <= (pipe.position.x + pipe.size.x))
		{
			if (player.position.y + player.size.y >= (pipe.position.y) &&
				player.position.y <= (pipe.position.y + pipe.size.y))
			{
				player.isDead = true;
			}
		}
		else if (player.position.y + player.size.y > GetScreenHeight())
		{
			player.isDead = true;
		}
	}

	void checkCollision(Player& player, Obstacle obstacles[MAX_OBSTACLES])
	{
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				checkCollision(player, obstacles[i].pipes[j]);
			}
		}
	}

	void initGame(Player& playerOne, Player& playerTwo, Obstacle obstacles[MAX_OBSTACLES],
		ParallaxBackground& background, bool isMultiplayer)
	{
		playerOne = initPlayerOne();

		if (isMultiplayer)
		{
			playerTwo = initPlayerTwo();
		}
		
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			obstacles[i] = createObstacles(i);
		}

		if (background.back.id == 0)
		{
			background.back = LoadTexture("res/back.png");
		}
		if (background.mid.id == 0)
		{
			background.mid = LoadTexture("res/middle.png");
		}
		if (background.front.id == 0)
		{
			background.front = LoadTexture("res/front.png");
		}

		background.scrollingBack = 0.0f;
		background.scrollingMid = 0.0f;
		background.scrollingFore = 0.0f;
	}

	void playGame(Player& playerOne, Player& playerTwo, Obstacle obstacles[MAX_OBSTACLES],
		Screen& actualScreen, ParallaxBackground& background, Music gameplayMusic,
		bool isMultiplayer)
	{
		updatePlayer(playerOne, playerTwo, isMultiplayer);
		moveObstacles(obstacles);
		updateParallax(background);

		checkCollision(playerOne, obstacles);

		if (isMultiplayer)
		{
			checkCollision(playerTwo, obstacles);
		}

		checkIfObstacleLevedScreen(obstacles);

		if (!IsMusicStreamPlaying(gameplayMusic))
		{
			SetMusicVolume(gameplayMusic, 1.0f);
			PlayMusicStream(gameplayMusic);
		}
		else
		{
			UpdateMusicStream(gameplayMusic);
		}

		//CheckScore(pipe, playerOne);
		//CheckScore(pipe, playerTwo);

		checkIfPlayerDied(playerOne, actualScreen);

		if (isMultiplayer)
		{
			checkIfPlayerDied(playerTwo, actualScreen);
		}

		DrawGame(background, obstacles, playerOne, playerTwo, isMultiplayer);

		ClearBackground(BLACK);
	}

	void checkIfObstacleLevedScreen(Obstacle& obstacle)
	{
		float newPosX;
		if (obstacle.pipes[0].position.x + obstacle.pipes[0].size.x < 0)
		{
			newPosX = obstacle.pipes[0].position.x + (MAX_OBSTACLES * OBSTACLE_SPACING);
			obstacle.pipes[0] = initPipeTop(newPosX);
			obstacle.pipes[1] = initPipeBottom(newPosX, obstacle.pipes[0].position.y);
		}
	}

	void checkIfObstacleLevedScreen(Obstacle obstacles[MAX_OBSTACLES])
	{
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			checkIfObstacleLevedScreen(obstacles[i]);
		}
	}

	void checkIfPlayerDied(Player& player, Screen& actualScreen)
	{
		if (player.isDead)
		{
			actualScreen = Screen::GAMEOVER;
		}
	}

	void DrawGame(ParallaxBackground& background, Obstacle obstacles[MAX_OBSTACLES],
		Player& playerOne, Player& playerTwo, bool isMultiplayer)
	{
		drawParallax(background);
		drawObstacles(obstacles);
		drawPlayer(playerOne, playerTwo, isMultiplayer);
	}
	

	/*void PointsPlayer()
	{
		const char* titleOne = "Player 1 Score:\n\n";
	}*/
}