#include "raylib.h"
#include "game.h"
#include "ship.h"
#include "bullet.h"
#include "enemy.h"

// Define the player ship instance
struct ship player;

void initGame()
{
    SetRandomSeed(GetTime());
    initShip(&player);
    initBullets();
    initEnemies();
}

void updateGame()
{
    updateShip(&player);
    updateBullets();
    updateEnemies();
}

void drawGame()
{
    ClearBackground(BLACK);
    drawShip(&player);
    drawBullets();
    drawEnemies();
    DrawText("Score:", 0, 0, 20, WHITE);
    DrawText(TextFormat("%i/%i", numBullets, numEnemies), 0, 32, 20, WHITE);
}