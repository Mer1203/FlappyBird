#pragma once
#include "Player.h"
#include "Pipe.h"
#include "Screen.h"
#include "Background.h"
namespace flappyBird
{
    void initGame(Player& player, Obstacle obstacles[MAX_OBSTACLES], ParallaxBackground& bg);
    void playGame(Player& player, Obstacle obstacles[MAX_OBSTACLES], Screen& actualScreen, ParallaxBackground& bg);

    void checkCollision(Player& player, Pipe& pipe);
    void checkCollision(Player& player, Obstacle obstacles[MAX_OBSTACLES]);
    void checkIfObstacleLevedScreen(Obstacle& obstacle);
    void checkIfObstacleLevedScreen(Obstacle obstacles[MAX_OBSTACLES]);
    void checkIfPlayerDied(Player& player, Screen& actualScreen);
}
