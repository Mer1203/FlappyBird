#include "Rules.h"
#include <raylib.h>
#include "Screen.h"
#include "Button.h"

namespace flappyBird
{
	void showRules(Screen& actualScreen)
	{
        const char* titleOne = "             FLAPPY BIRD\n\n";
        const char* rulesText =
            "Objective:\n"
            "Get the highest score possible!\n\n"
            "How to Play:\n"
            "Avoid the pipes by flying through the gaps.\n"
            "Each pipe passed gives you 1 point.\n\n"
            "Controls:\n"
            "Player 1: SPACE to fly upwards.\n"
            "Player 2: UP ARROW to fly upwards.\n\n"
            "Defeat Condition:\n"
            "You lose if your bird hits a pipe or the ground.\n\n"
            "Winner:\n"
            "The player with the highest score wins!";

        float titleFontSize = 35.0f;
        float rulesFontSize = 20.0f;
        float spacing = 1.0f;

        Font defaultFont = GetFontDefault();

        Vector2 titleSize = MeasureTextEx(
            defaultFont,
            titleOne,
            titleFontSize,
            spacing
        );

        Vector2 rulesSize = MeasureTextEx(
            defaultFont,
            rulesText,
            rulesFontSize,
            spacing
        );

        float titleX = (static_cast<float>(screenWidth) / 2.0f) - (titleSize.x / 2.0f);
        float titleY = 30.0f;

        float rulesX = (static_cast<float>(screenWidth) / 2.0f) - (rulesSize.x / 2.0f);
        float rulesY = 110.0f;

        Button exitButton;

        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = static_cast<int>((static_cast<float>(screenWidth) / 2.0f) - (exitButton.width / 2.0f));
        exitButton.y = screenHigh - 80;
        exitButton.text = "EXIT";

        if (onClick(exitButton))
        {
            actualScreen = Screen::MENU;
        }

        DrawTextEx(
            defaultFont,
            titleOne,
            { titleX, titleY },
            titleFontSize,
            spacing,
            RED
        );
        DrawTextEx(
            defaultFont,
            rulesText,
            { rulesX, rulesY },
            rulesFontSize,
            spacing,
            RAYWHITE
        );

        DrawRectangle(
            exitButton.x,
            exitButton.y,
            exitButton.width,
            exitButton.high,
            RED
        );

        float buttonFontSize = 20.0f;

        Vector2 exitTextSize = MeasureTextEx(
            defaultFont,
            exitButton.text.c_str(),
            buttonFontSize,
            spacing
        );

        DrawTextEx(
            defaultFont,
            exitButton.text.c_str(),
            {
                static_cast<float>(exitButton.x) + (static_cast<float>(exitButton.width) - exitTextSize.x) / 2.0f,
                static_cast<float>(exitButton.y) + (static_cast<float>(exitButton.high) - exitTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );
	}
}