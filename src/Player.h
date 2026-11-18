#pragma once
#include <raylib.h>
namespace flappyBird
{
	struct Player
	{
		Vector2 position;
		Vector2 size;
		float velY;
		float jumpForce;
		float velocity;
		float score;
		bool isDead;
		Texture2D Bird;
	};

	const float gravity = 600.0f;
	const float VELOCITY_LIMIT = 280.0f;

	Player initPlayerOne();
	Player initPlayerTwo();
	void updatePlayer(Player& player, Player& playerTwo);
	void playerMovement(Player& player, KeyboardKey key);
	void drawPlayer(Player player, Player playerTwo);
}