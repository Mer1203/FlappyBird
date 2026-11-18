#pragma once
#include "Player.h"
#include "Pipe.h"
#include "Screen.h"
#include "Background.h"

namespace flappyBird
{
    void initGame(Player& playerOne, Player& playerTwo, Obstacle obstacles[MAX_OBSTACLES],
        ParallaxBackground& background, Music gameplayMusic);
    void playGame(Player& player, Player& playerTwo, Obstacle obstacles[MAX_OBSTACLES],
        Screen& actualScreen, ParallaxBackground& background);

    void DrawGame(ParallaxBackground& background, Obstacle obstacles[MAX_OBSTACLES],
        Player& playerOne, Player& playerTwo);

    void checkCollision(Player& player, Pipe& pipe);
    void checkCollision(Player& player, 
        Obstacle obstacles[MAX_OBSTACLES]);
   
    void checkIfObstacleLevedScreen(Obstacle& obstacle);
    void checkIfObstacleLevedScreen(Obstacle obstacles[MAX_OBSTACLES]);
    void checkIfPlayerDied(Player& player, Screen& actualScreen);
}
