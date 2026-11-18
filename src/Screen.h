#pragma once
namespace flappyBird
{
	const int screenWidth = 1024;
	const int screenHigh = 768;

	enum class Screen
	{
		none = 0,
		MENU,
		PLAY,
		RULES,
		CREDITS,
		GAMEOVER,
		PAUSE,
		EXIT
	};
}