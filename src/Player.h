#pragma once
namespace flappyBird
{
	const float PLAYER_SPEED = 100;

	struct Player
	{
		float posX;
		float posY;
		float width;
		float height;
		float velY;
		float jumpForce;
		float verticalVel;
		bool isDead;
	};

	const float gravity = 800.0f;

	Player initPlayerOne();
	Player initPlayerTwo();
	void movePlayer(Player& player, Player& playerTwo);
	void drawPlayer(Player player);
}