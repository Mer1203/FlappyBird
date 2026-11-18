#include "Player.h"

#include <iostream>

#include <raylib.h>

namespace flappyBird
{
	Player initPlayerOne()
	{
		Player playerOne;

		playerOne.position.x = 100;
		playerOne.position.y = 200;
		playerOne.size.x = 40;
		playerOne.size.y = 40;
		playerOne.jumpForce = 300.0f;
		playerOne.velocity = 0.0f;
		playerOne.isDead = false;
		playerOne.Bird = LoadTexture("res/Bird1.png");

		return playerOne;
	}

	Player initPlayerTwo()
	{
		Player playerTwo;

		playerTwo.position.x = 100;
		playerTwo.position.y = 200;
		playerTwo.size.x = 40;
		playerTwo.size.y = 40;
		playerTwo.jumpForce = 300.0f;
		playerTwo.velocity = 0.0f;
		playerTwo.isDead = false;
		playerTwo.Bird = LoadTexture("res/Bird2.png");

		return playerTwo;
	}

	void updatePlayer(Player& playerOne, Player& playerTwo, bool isMultiplayer)
	{
		playerMovement(playerOne, KEY_SPACE);

		if (isMultiplayer)
		{
			playerMovement(playerTwo, KEY_UP);
		}
	}

	void drawPlayer(Player playerOne, Player playerTwo, bool isMultiplayer)
	{
		Vector2 drawPositionOne = { playerOne.position.x - 40, playerOne.position.y - 40 };
		DrawTextureEx(playerOne.Bird, drawPositionOne, 0, 0.1f, WHITE);

		if (isMultiplayer)
		{
			Vector2 drawPositionTwo = { playerTwo.position.x - 40, playerTwo.position.y - 40 };
			DrawTextureEx(playerTwo.Bird, drawPositionTwo, 0, 0.1f, WHITE);
		}

#ifdef _DEBUG
		DrawRectangleV(playerOne.position, playerOne.size, BLUE);

		if (isMultiplayer)
		{
			DrawRectangleV(playerTwo.position, playerTwo.size, VIOLET);
		}
#endif
	}

	void playerMovement(Player& player, KeyboardKey key)
	{
		if (IsKeyPressed(key))
		{
			if (player.velocity < -player.jumpForce)
			{
				player.velocity = -player.jumpForce;
			}

			player.velocity -= player.jumpForce;
		}
		else
		{
			if (player.velocity > VELOCITY_LIMIT)
			{
				player.velocity = VELOCITY_LIMIT;
			}

			player.velocity += gravity * GetFrameTime();
			player.position.y += (player.velocity) * GetFrameTime();
		}

		if (player.position.y < 0)
		{
			player.position.y = 0;
			player.velocity = 0;
		}
	}
}