#include "raylib.h"
#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "enemy.h"

void initGame()
{
    currentScreen = GAMEPLAY;
    switch (currentScreen)
    {
    case GAMEPLAY:
        initGameplay();
        break;
    case ENDING:
        initEnding();
        break;
    }
}

void updateGame()
{
    switch (currentScreen)
    {
    case GAMEPLAY:
        updateGameplay();
        break;
    case ENDING:
        updateEnding();
        break;
    }
}

void drawGame()
{
    switch (currentScreen)
    {
    case GAMEPLAY:
        drawGameplay();
        break;
    case ENDING:
        drawEnding();
        break;
    }
}

void initGameplay()
{
    // Initialize the player ship
    initShip(&player);
    // Initialize the bullets
    initBullets();
    // Initialize the enemies
    initEnemies();
}

void updateGameplay()
{
    updateShip(&player);
    updateBullets();
    updateEnemies();
}

void drawGameplay()
{
    ClearBackground(BLACK);
    drawShip(&player);
    drawBullets();
    drawEnemies();
    DrawText(TextFormat("Score: %i", score), 0, 0, 20, WHITE);
}

void initEnding()
{
    // Nothing to do here
}

void updateEnding()
{
    if (IsKeyPressed(KEY_ENTER))
    {
        initGame();
    }
}

void drawEnding()
{
    ClearBackground(BLACK);
    DrawText("Game Over!", GetScreenWidth() / 2 - MeasureText("Game Over!", 40) / 2, GetScreenHeight() / 2 - 20, 40, WHITE);
    DrawText(TextFormat("Score: %i", score), GetScreenWidth() / 2 - MeasureText(TextFormat("Score: %i", score), 20) / 2, GetScreenHeight() / 2 + 20, 20, WHITE);
    DrawText("Press [ENTER] to play again", GetScreenWidth() / 2 - MeasureText("Press [ENTER] to play again", 20) / 2, GetScreenHeight() / 2 + 50, 20, WHITE);
}