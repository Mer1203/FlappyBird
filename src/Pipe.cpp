#include "Pipe.h"

#include <iostream>
#include "Player.h"

namespace flappyBird
{
	Pipe initPipeTop(float posX)
	{
		Pipe pipe;

		int screenHeight = GetScreenHeight();
		int minHeight = screenHeight / 6;
		int maxHeight = screenHeight / 2;

		pipe.position.x = posX;
		pipe.size.y = static_cast<float>(minHeight + (rand() % (maxHeight - minHeight)));
		pipe.position.y = 0;
		pipe.size.x = 80;
		//pipe.pipe = LoadTexture("res/Pipe.png");

		return pipe;
	}

	Pipe initPipeBottom(float posX, float lastTopPipeHeight)
	{
		Pipe pipe;

		pipe.position.x = posX;
		pipe.position.y = lastTopPipeHeight + PIPE_OFFSET;
		pipe.size.y = static_cast<float>(GetScreenHeight()) - pipe.position.y;
		pipe.size.x = 80;
		//pipe.pipe = LoadTexture("res/Pipe.png");

		return pipe;
	}

	Obstacle createObstacles(int index)
	{
		Obstacle obstacles;

		for (int i = 0; i < 2; i++)
		{
			if (i % 2 == 0)
			{
				obstacles.pipes[i] = initPipeTop(startX + (index * OBSTACLE_SPACING));
			}
			else
			{
				obstacles.pipes[i] = initPipeBottom(startX + (index * OBSTACLE_SPACING),
					obstacles.pipes[i - 1].size.y);
			}
		}

		return obstacles;
	}

	void movePipe(Pipe& pipe)
	{
		pipe.position.x -= (PIPE_VEL)*GetFrameTime();
	}

	void moveObstacles(Obstacle obstacles[MAX_OBSTACLES])
	{
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				movePipe(obstacles[i].pipes[j]);
			}
		}
	}

	void drawPipe(Pipe pipe)
	{
		DrawRectangleV(pipe.position, pipe.size, ORANGE);
		/*Vector2 drawPosition = { pipe.position.x - 120, pipe.position.y - 100 };

		DrawTextureEx(pipe.pipe, drawPosition, 0, 0.5f, WHITE);*/
	}

	void drawObstacles(Obstacle obstacles[MAX_OBSTACLES])
	{
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				drawPipe(obstacles[i].pipes[j]);
			}
		}
	}

	void CheckScore(Obstacle obstacles[MAX_OBSTACLES],
		Player& player, bool isPlayerTwo)
	{
		for (int i = 0; i < MAX_OBSTACLES; i++)
		{
			bool alreadyScored = false;

			if (isPlayerTwo)
			{
				alreadyScored = obstacles[i].scoredPlayerTwo;
			}
			else
			{
				alreadyScored = obstacles[i].scoredPlayerOne;
			}

			if (!alreadyScored &&
				obstacles[i].pipes[0].position.x +
				obstacles[i].pipes[0].size.x < player.position.x)
			{
				player.score += 1;

				if (isPlayerTwo)
				{
					obstacles[i].scoredPlayerTwo = true;
				}
				else
				{
					obstacles[i].scoredPlayerOne = true;
				}
			}
		}
	}
}