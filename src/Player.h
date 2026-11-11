#pragma once
#include <raylib.h>
namespace flappyBird
{
	struct Player
	{
		float posX;
		float posY;
		float width;
		float height;
		float velY;
		float jumpForce;
		float velocity;
		bool isDead;
	};

	const float gravity = 600.0f;
	const float VELOCITY_LIMIT = 280.0f;

	Player initPlayerOne();
	Player initPlayerTwo();
	void updatePlayer(Player& player, Player& playerTwo);
	void playerMovement(Player& player, KeyboardKey key);
	void drawPlayer(Player player, Player playerTwo);
}