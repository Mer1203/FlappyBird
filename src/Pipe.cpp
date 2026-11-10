#include "Pipe.h"

#include <iostream>

namespace flappyBird
{
	Pipe initPipeTop(float posX)
	{
		Pipe pipe;

		int screenHeight = GetScreenHeight();
		int minHeight = screenHeight / 6;
		int maxHeight = screenHeight / 2;

		pipe.posX = posX;
		pipe.height = static_cast<float>(minHeight + (rand() % (maxHeight - minHeight)));
		pipe.posY = 0;
		pipe.width = 60;

		return pipe;
	}

	Pipe initPipeBottom(float posX, float lastTopPipeHeight)
	{
		Pipe pipe;

		pipe.posX = posX;
		pipe.posY = lastTopPipeHeight + PIPE_OFFSET;
		pipe.height = static_cast<float>(GetScreenHeight()) - pipe.posY;
		pipe.width = 60;

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
					obstacles.pipes[i - 1].height);
			}
		}

		return obstacles;
	}

	void movePipe(Pipe& pipe)
	{
		pipe.posX -= (PIPE_VEL)*GetFrameTime();
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
		DrawRectangle(static_cast<int>(pipe.posX), static_cast<int>(pipe.posY),
			static_cast<int>(pipe.width), static_cast<int>(pipe.height), RED);
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

}