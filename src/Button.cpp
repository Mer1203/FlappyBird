#include "Button.h"
#include <raylib.h>
namespace flappyBird
{
	bool onClick(Button button)
	{
		int mouseX = 0;
		int mouseY = 0;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			mouseX = GetMouseX();
			mouseY = GetMouseY();
			if (mouseX >= (button.x) && mouseX <= (button.x + button.width))
			{
				if (mouseY >= (button.y) && mouseY <= (button.y + button.high))
				{
					return true;
				}
			}
		}
		return false;
	}

	void ButtonInit(Button& playButton, Button& creditsButton, Button& exitButton)
	{
		float sw = static_cast<float>(GetScreenWidth());
		float sh = static_cast<float>(GetScreenHeight());

		playButton.width = 200;
		playButton.high = 50;
		playButton.x = static_cast<int>(sw / 2.0f - playButton.width / 2.0f);
		playButton.y = static_cast<int>(sh / 3.0f);
		playButton.text = "PLAY";
		playButton.isSoundPlaying = false;

		creditsButton.width = 200;
		creditsButton.high = 50;
		creditsButton.x = static_cast<int>(sw / 2.0f - creditsButton.width / 2.0f);
		creditsButton.y = static_cast<int>(playButton.y + playButton.high + buttonsOffset);
		creditsButton.text = "CREDITS";
		creditsButton.isSoundPlaying = false;

		exitButton.width = 200;
		exitButton.high = 50;
		exitButton.x = static_cast<int>(sw / 2.0f - exitButton.width / 2.0f);
		exitButton.y = static_cast<int>(creditsButton.y + creditsButton.high + buttonsOffset);
		exitButton.text = "EXIT";
		exitButton.isSoundPlaying = false;
	}

}