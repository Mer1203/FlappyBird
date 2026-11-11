#include "MainMenu.h"
#include <raylib.h>
#include "Button.h"

namespace flappyBird
{
    void showMainMenu(Screen& actualScreen)
    {
        // 1. Obtener la fuente por defecto de Raylib
        Font defaultFont = GetFontDefault();

        // 2. Configuración de botones
        Button playButton;
        Button creditsButton;
        Button exitButton;

        float sw = static_cast<float>(GetScreenWidth());
        float sh = static_cast<float>(GetScreenHeight());


        const char* title = "FLOPPY: EL PAJARO QUE VUELA";
        const char* title2 = "REMASTER EDITION";
        float titleFontSize = 40.0f;
        float title2FontSize = 30.0f;
        float spacing = 1.0f;

        Vector2 titleSize = MeasureTextEx(defaultFont, title, titleFontSize, spacing);
        float titleX = (sw / 2.0f) - (titleSize.x / 2.0f);
        float titleY = 30.0f;

        Vector2 title2Size = MeasureTextEx(defaultFont, title2, title2FontSize, spacing);
        float title2X = (sw / 2.0f) - (title2Size.x / 2.0f); 
        float title2Y = titleY + titleSize.y + 10.0f;          

        playButton.width = 200;
        playButton.high = 50;
        playButton.x = static_cast<int>(sw / 2.0f - playButton.width / 2.0f);
        playButton.y = static_cast<int>(sh / 3.0f);
        playButton.text = "PLAY";


        creditsButton.width = 200;
        creditsButton.high = 50;
        creditsButton.x = static_cast<int>(sw / 2.0f - creditsButton.width / 2.0f);
        creditsButton.y = static_cast<int>(playButton.y + playButton.high + buttonsOffset);
        creditsButton.text = "CREDITS";


        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = static_cast<int>(sw / 2.0f - exitButton.width / 2.0f);
        exitButton.y = static_cast<int>(creditsButton.y + creditsButton.high + buttonsOffset);
        exitButton.text = "EXIT";


        if (onClick(playButton))
        {
            actualScreen = Screen::PLAY;
        }
        else if (onClick(creditsButton))
        {
            actualScreen = Screen::CREDITS;
        }
        else if (onClick(exitButton))
        {
            actualScreen = Screen::EXIT;
        }

        float buttonFontSize = 20.0f;

        DrawRectangle(playButton.x, playButton.y, playButton.width, playButton.high, RED);
        Vector2 playTextSize = MeasureTextEx(defaultFont, playButton.text.c_str(), buttonFontSize, spacing);
        DrawTextEx(
            defaultFont,
            playButton.text.c_str(),
            {
                static_cast<float>(playButton.x) + (playButton.width - playTextSize.x) / 2.0f,
                static_cast<float>(playButton.y) + (playButton.high - playTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        DrawRectangle(creditsButton.x, creditsButton.y, creditsButton.width, creditsButton.high, RED);
        Vector2 creditsTextSize = MeasureTextEx(defaultFont, creditsButton.text.c_str(), buttonFontSize, spacing);
        DrawTextEx(
            defaultFont,
            creditsButton.text.c_str(),
            {
                static_cast<float>(creditsButton.x) + (creditsButton.width - creditsTextSize.x) / 2.0f,
                static_cast<float>(creditsButton.y) + (creditsButton.high - creditsTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );

        DrawRectangle(exitButton.x, exitButton.y, exitButton.width, exitButton.high, RED);
        Vector2 exitTextSize = MeasureTextEx(defaultFont, exitButton.text.c_str(), buttonFontSize, spacing);
        DrawTextEx(
            defaultFont,
            exitButton.text.c_str(),
            {
                static_cast<float>(exitButton.x) + (exitButton.width - exitTextSize.x) / 2.0f,
                static_cast<float>(exitButton.y) + (exitButton.high - exitTextSize.y) / 2.0f
            },
            buttonFontSize,
            spacing,
            RAYWHITE
        );


        DrawTextEx(defaultFont, title, { titleX, titleY }, titleFontSize, spacing, RED);
        DrawTextEx(defaultFont, title2, { title2X, title2Y }, title2FontSize, spacing, YELLOW);

        DrawText("v0.4", 20, 20, 30, WHITE);
    }
}