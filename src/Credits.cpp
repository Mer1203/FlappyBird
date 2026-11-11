#include "Credits.h"
#include <raylib.h>
#include "Button.h"
namespace flappyBird
{
	void showCredits(Screen& actualScreen)
	{
        const char* titleOne = "      Original Made By:\n Santino Giuffrida Castillo"; // Cambia este texto si prefieres otro formato
        const char* titleTwo = "         Finished By:\n Mercedes Ramirez Diaz"; // Cambia este texto si prefieres otro formato
        float titleFontSize = 35.0f;
        float spacing = 1.0f;

        // Usa las variables globales directas convirtiéndolas a float para medir
        Font defaultFont = GetFontDefault();

        Vector2 titleSizeOne = MeasureTextEx(
            defaultFont,
            titleOne,
            titleFontSize,
            spacing
        );

        Vector2 titleSizeTwo = MeasureTextEx(
            defaultFont,
            titleTwo,
            titleFontSize,
            spacing
        );

        // Centra el título horizontalmente (usando static_cast para evitar advertencias)
        float titleXOne = (static_cast<float>(screenWidth) / 2.0f) - (titleSizeOne.x / 2.0f);
        float titleYOne = static_cast<float>(screenHigh) / 5.0f;

        float titleXTwo = (static_cast<float>(screenWidth) / 2.0f) - (titleSizeOne.x / 2.0f);
        float titleYTwo = static_cast<float>(screenHigh) / 3.0f;

        // 2. Configuración del botón EXIT
        Button exitButton;
        // Si width/high son int en struct Button, convertimos el resultado a int
        exitButton.width = 200;
        exitButton.high = 50;
        exitButton.x = static_cast<int>((static_cast<float>(screenWidth) / 2.0f) - (exitButton.width / 2.0f));
        exitButton.y = static_cast<int>((static_cast<float>(screenHigh) / 2.0f) + 50.0f);
        exitButton.text = "EXIT";

        // Comprueba si se hizo clic en el botón EXIT
        if (onClick(exitButton))
        {
            actualScreen = Screen::MAIN_MENU;
        }

        // 3. Dibujado de los elementos en pantalla

        // Dibuja el botón EXIT
        DrawRectangle(
            exitButton.x,
            exitButton.y,
            exitButton.width,
            exitButton.high,
            RED
        );

        // Calcula y centra el texto del botón SALIR
        float buttonFontSize = 20.0f;
        Vector2 exitTextSize = MeasureTextEx(defaultFont, exitButton.text.c_str(), buttonFontSize, spacing);

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

        // Dibuja tu nombre como título
        DrawTextEx(
            defaultFont,
            titleOne,
            {titleXOne, titleYOne},
            titleFontSize,
            spacing,
            RED
        );

        DrawTextEx(
            defaultFont,
            titleTwo,
            {titleXTwo, titleYTwo},
            titleFontSize,
            spacing,
            RED
        );
    }
}
