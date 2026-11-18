#include "Rules.h"
#include <raylib.h>
#include "Screen.h"
#include "Button.h"

namespace flappyBird
{
    void showRules(Screen& actualScreen, bool& isMultiplayer)
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

        Button singlePlayerButton;
        Button multiPlayerButton;
        Button exitButton;

        singlePlayerButton.width = 200;
        singlePlayerButton.high = 50;
        singlePlayerButton.x = (screenWidth / 2) - singlePlayerButton.width - 15;
        singlePlayerButton.y = screenHigh - 150;
        singlePlayerButton.text = "SINGLEPLAYER";
        singlePlayerButton.isSoundPlaying = false;

        multiPlayerButton.width = 200;
        multiPlayerButton.high = 50;
        multiPlayerButton.x = (screenWidth / 2) + 15;
        multiPlayerButton.y = screenHigh - 150;
        multiPlayerButton.text = "MULTIPLAYER";
        multiPlayerButton.isSoundPlaying = false;

        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = (screenWidth / 2) - (exitButton.width / 2);
        exitButton.y = screenHigh - 80;
        exitButton.text = "EXIT";
        exitButton.isSoundPlaying = false;

        if (onClick(singlePlayerButton))
        {
            isMultiplayer = false;
            actualScreen = Screen::PLAY;
        }
        else if (onClick(multiPlayerButton))
        {
            isMultiplayer = true;
            actualScreen = Screen::PLAY;
        }
        else if (onClick(exitButton))
        {
            actualScreen = Screen::MENU;
        }

        float buttonFontSize = 20.0f;

        DrawRectangle(
            singlePlayerButton.x,
            singlePlayerButton.y,
            singlePlayerButton.width,
            singlePlayerButton.high,
            RED
        );

        Vector2 singleTextSize = MeasureTextEx(
            defaultFont,
            singlePlayerButton.text.c_str(),
            buttonFontSize,
            spacing
        );

        DrawTextEx(
            defaultFont,
            singlePlayerButton.text.c_str(),
            {
                static_cast<float>(singlePlayerButton.x) +
                (singlePlayerButton.width - singleTextSize.x) / 2.0f,

                static_cast<float>(singlePlayerButton.y) +
                (singlePlayerButton.high - singleTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        DrawRectangle(
            multiPlayerButton.x,
            multiPlayerButton.y,
            multiPlayerButton.width,
            multiPlayerButton.high,
            RED
        );

        Vector2 multiTextSize = MeasureTextEx(
            defaultFont,
            multiPlayerButton.text.c_str(),
            buttonFontSize,
            spacing
        );

        DrawTextEx(
            defaultFont,
            multiPlayerButton.text.c_str(),
            {
                static_cast<float>(multiPlayerButton.x) +
                (multiPlayerButton.width - multiTextSize.x) / 2.0f,

                static_cast<float>(multiPlayerButton.y) +
                (multiPlayerButton.high - multiTextSize.y) / 2.0f
            },
            buttonFontSize,
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
                static_cast<float>(exitButton.x) +
                (exitButton.width - exitTextSize.x) / 2.0f,

                static_cast<float>(exitButton.y) +
                (exitButton.high - exitTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

	}
}