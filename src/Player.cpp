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
		playerOne.velY = PLAYER_SPEED;
		playerOne.width = 40;
		playerOne.height = 40;
		playerOne.jumpForce = 300.0f;
		playerOne.verticalVel = 0.0f;
		playerOne.isDead = false;

		return playerOne;
	}

	Player initPlayerTwo()
	{
		Player playerTwo;

		playerTwo.posX = 100;
		playerTwo.posY = 200;
		playerTwo.velY = PLAYER_SPEED;
		playerTwo.width = 40;
		playerTwo.height = 40;
		playerTwo.jumpForce = 300.0f;
		playerTwo.verticalVel = 0.0f;
		playerTwo.isDead = false;

		return playerTwo;
	}

	void movePlayer(Player& playerOne, Player& playerTwo)
	{
		float aux;

		if (IsKeyPressed(KEY_SPACE))
		{ 
			if (playerOne.verticalVel < -playerOne.jumpForce)
			{
				playerOne.verticalVel = -playerOne.jumpForce;
			}
			
			if (playerTwo.verticalVel < -playerTwo.jumpForce)
			{
				playerTwo.verticalVel = -playerTwo.jumpForce;
			}

			playerOne.verticalVel -= playerOne.jumpForce;
			playerTwo.verticalVel -= playerTwo.jumpForce;
		}
		else
		{
			if (playerOne.verticalVel > 350)
			{
				playerOne.verticalVel = 350;
			}
			
			playerOne.verticalVel += gravity * GetFrameTime();
			playerOne.posY += (playerOne.verticalVel) * GetFrameTime();

			aux = playerOne.verticalVel;

			std::cout << playerOne.verticalVel << std::endl;
		}

		if (playerOne.posY < 0)
		{
			playerOne.posY = 0;
		}
	}

	void drawPlayer(Player player)
	{
		DrawRectangle(static_cast<int>(player.posX), static_cast<int>(player.posY),
			static_cast<int>(player.width), static_cast<int>(player.height), BLUE);
	}
}