#pragma once
#include <raylib.h>
#include "Screen.h"
#include "Player.h"

namespace flappyBird
{
	void DrawGameOver(Screen& actualScreen, bool isMultiplayer,
		Player& playerOne, Player& playerTwo);
}