#pragma once

#include <raylib.h>
#include "Player.h"

namespace flappyBird
{
	const int NUMB_OF_PIPES = 2;
	const int MAX_PIPES = 30;
	const int PIPE_SPAWN_OFFSET = 40;
	const float PIPE_VEL = 100;
	const int MAX_OBSTACLES = 30;
	const float OBSTACLE_SPACING = 450.0f;
	const int PIPE_OFFSET = 140;
	const float startX = 1024;
	struct Pipe
	{
		Vector2 position;
		Vector2 size;
	};

	struct Obstacle
	{
		Pipe pipes[2];

		bool scoredPlayerOne = false;
		bool scoredPlayerTwo = false;
	};

	Pipe initPipeTop(float posX);

	Pipe initPipeBottom(float posX, float lastTopPipeHeight);

	Obstacle createObstacles(int index);

	void movePipe(Pipe& pipe);

	void moveObstacles(Obstacle obstacles[MAX_OBSTACLES]);

	void drawPipe(Pipe pipe);

	void drawObstacles(Obstacle obstacles[MAX_OBSTACLES]);

	void CheckScore(Obstacle obstacles[MAX_OBSTACLES],
		Player& player, bool isPlayerTwo);
}