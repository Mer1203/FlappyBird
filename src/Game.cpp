#include "Game.h"
#include <raylib.h>
#include "Screen.h"

namespace flappyBird
{
	void checkCollision(Player& player, Pipe& pipe)
	{
		if (player.posX + player.width >= (pipe.posX) && 
			player.posX <= (pipe.posX + pipe.width))
		{
			if (player.posY + player.height >= (pipe.posY) && 
				player.posY <= (pipe.posY + pipe.height))
			{
				player.isDead = true;
			}
		}
		else if (player.posY + player.height > GetScreenHeight())
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
		ParallaxBackground& background)
	{
		playerOne = initPlayerOne();
		playerTwo = initPlayerTwo();

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
		Screen& actualScreen, ParallaxBackground& background)
	{
		updatePlayer(playerOne, playerTwo);
		moveObstacles(obstacles);
		updateParallax(background);
		checkCollision(playerOne, obstacles);
		checkIfObstacleLevedScreen(obstacles);
		checkIfPlayerDied(playerOne, actualScreen);

		ClearBackground(BLACK);

		drawParallax(background);
		drawObstacles(obstacles);
		drawPlayer(playerOne, playerTwo);
	}

	void checkIfObstacleLevedScreen(Obstacle& obstacle)
	{
		float newPosX;
		if (obstacle.pipes[0].posX + obstacle.pipes[0].width < 0)
		{
			newPosX = obstacle.pipes[0].posX + (MAX_OBSTACLES * OBSTACLE_SPACING);
			obstacle.pipes[0] = initPipeTop(newPosX);
			obstacle.pipes[1] = initPipeBottom(newPosX, obstacle.pipes[0].height);
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
			actualScreen = Screen::MAIN_MENU;
		}
	}
}