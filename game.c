#include "raylib.h"
#include "game.h"
#include "ship.h"
#include "bullet.h"

// Define the player ship instance
struct ship player;

void initGame()
{
    initShip(&player);
    numBullets = 0;
}

void updateGame()
{
    updateShip(&player);
    updateBullets();
}

void drawGame()
{
    ClearBackground(BLACK);
    drawShip(&player);
    drawBullets();
    DrawText("Score:", 0, 0, 20, WHITE);
    DrawText(TextFormat("%i", numBullets), 0, 32, 20, WHITE);
}