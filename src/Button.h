#pragma once

#include <iostream>
namespace flappyBird
{
	const int fontButtons = 20;
	const int buttonsOffset = 20;

	struct Button
	{
		int x;
		int y;
		int width;
		int high;
		std::string text;
	};

	bool onClick(Button button);
}