#include "Game.h"
#include <raylib.h>
#include "Screen.h"
namespace flappyBird
{

	void checkCollision(Player& player, Pipe& pipe)
	{
		if (player.posX + player.width >= (pipe.posX) && player.posX <= (pipe.posX + pipe.width))
		{
			if (player.posY + player.height >= (pipe.posY) && player.posY <= (pipe.posY + pipe.height))
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

	void initGame(Player& player, Obstacle obstacles[MAX_OBSTACLES], ParallaxBackground& bg)
	{
		player = initPlayer();

		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			obstacles[i] = createObstacles(i);
		}


		if (bg.back.id == 0)
		{
			bg.back = LoadTexture("res/back.png");
		}
		if (bg.mid.id == 0)
		{
			bg.mid = LoadTexture("res/middle.png");
		}
		if (bg.front.id == 0)
		{
			bg.front = LoadTexture("res/front.png");
		}

		bg.scrollingBack = 0.0f;
		bg.scrollingMid = 0.0f;
		bg.scrollingFore = 0.0f;
	}

	void playGame(Player& player, Obstacle obstacles[MAX_OBSTACLES], Screen& actualScreen, ParallaxBackground& bg)
	{
		movePlayer(player);
		moveObstacles(obstacles);
		updateParallax(bg); 
		checkCollision(player, obstacles);
		checkIfObstacleLevedScreen(obstacles);
		checkIfPlayerDied(player, actualScreen);

		ClearBackground(BLACK);

		drawParallax(bg);     
		drawObstacles(obstacles);
		drawPlayer(player);

	}

	void checkIfObstacleLevedScreen(Obstacle& obstacle)
	{
		float newPosX;
		if (obstacle.pipes[0].posX + obstacle.pipes[0].width < 0)
		{
			newPosX = obstacle.pipes[0].posX + (MAX_OBSTACLES * OBSTACLE_SPACING);
			obstacle.pipes[0] = initPipe(newPosX);
			obstacle.pipes[1] = initPipe(newPosX, obstacle.pipes[0].height);
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