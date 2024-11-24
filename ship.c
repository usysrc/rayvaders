#include "raylib.h"
#include "ship.h"
#include "bullet.h"

void initShip(struct ship *ship)
{
    ship->x = 400;
    ship->y = 400;
    ship->speed = 500;
    ship->texture = LoadTexture("resources/ship.png");
}

void updateShip(struct ship *ship)
{
    if (IsKeyDown(KEY_RIGHT))
    {
        ship->x += ship->speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_LEFT))
    {
        ship->x -= ship->speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_UP))
    {
        ship->y -= ship->speed * GetFrameTime();
    }
    if (IsKeyDown(KEY_DOWN))
    {
        ship->y += ship->speed * GetFrameTime();
    }
    if (IsKeyPressed(KEY_SPACE))
    {
        if (numBullets >= MAX_BULLETS)
            return;
        struct Bullet *bullet = &bullets[numBullets];
        initBullet(bullet);
        bullet->x = ship->x + ship->texture.width / 2 - bullet->texture.width / 2;
        bullet->y = ship->y - bullet->texture.height;
        numBullets++;
    }
}

void drawShip(struct ship *ship)
{
    DrawTexture(ship->texture, ship->x, ship->y, WHITE);
}