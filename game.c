#include "raylib.h"
#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "enemy.h"
#include "particle.h"

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

Texture2D backgroundTexture;

void initGameplay()
{
    // Initialize the score
    score = 0;
    // Initialize the timer
    timer = 0;

    // Load the background texture
    backgroundTexture = LoadTexture("resources/background.png");

    // Initialize the player ship
    initShip(&player);
    // Initialize the bullets
    initBullets();
    // Initialize the enemies
    initEnemies();
    // Initialize the particles
    initParticles();
}

void updateGameplay()
{
    // Update the timer
    timer += GetFrameTime();

    // Update the entities
    updateShip(&player);
    updateBullets();
    updateEnemies();
    updateParticles();
}

void drawGameplay()
{
    ClearBackground(BLACK);
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    drawShip(&player);
    drawBullets();
    drawEnemies();
    drawParticles();
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