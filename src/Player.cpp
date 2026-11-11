#include "Player.h"

#include <iostream>

#include <raylib.h>

namespace flappyBird
{
	Player initPlayerOne()
	{
		Player playerOne;

		playerOne.posX = 100;
		playerOne.posY = 200;
		playerOne.width = 40;
		playerOne.height = 40;
		playerOne.jumpForce = 300.0f;
		playerOne.velocity = 0.0f;
		playerOne.isDead = false;

		return playerOne;
	}

	Player initPlayerTwo()
	{
		Player playerTwo;

		playerTwo.posX = 100;
		playerTwo.posY = 200;
		playerTwo.width = 40;
		playerTwo.height = 40;
		playerTwo.jumpForce = 300.0f;
		playerTwo.velocity = 0.0f;
		playerTwo.isDead = false;

		return playerTwo;
	}

	void updatePlayer(Player& playerOne, Player& playerTwo)
	{
		playerMovement(playerOne, KEY_SPACE);
		playerMovement(playerTwo, KEY_UP);
	}

	void drawPlayer(Player playerOne, Player playerTwo)
	{
		DrawRectangle(static_cast<int>(playerOne.posX), static_cast<int>(playerOne.posY),
			static_cast<int>(playerOne.width), static_cast<int>(playerOne.height), BLUE);

		DrawRectangle(static_cast<int>(playerTwo.posX), static_cast<int>(playerTwo.posY),
			static_cast<int>(playerTwo.width), static_cast<int>(playerTwo.height), VIOLET);
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
			player.posY += (player.velocity) * GetFrameTime();
		}

		if (player.posY < 0)
		{
			player.posY = 0;
			player.velocity = 0;
		}
	}
}