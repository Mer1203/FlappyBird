#pragma once
#include "Screen.h"
#include <raylib.h>
namespace flappyBird
{
	void showMainMenu(Screen& actualScreen, Music menuMusic, 
		Sound playButtonSound, Sound creditButtonSound);
}