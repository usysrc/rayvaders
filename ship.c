#include "raylib.h"
#include "ship.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"

Sound laserSound;

void initShip(struct ship *ship)
{
    laserSound = LoadSound("resources/laser.wav");
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

    if (ship->x < 0)
        ship->x = 0;
    if (ship->x > 800)
        ship->x = 800;
    if (ship->y < 0)
        ship->y = 0;
    if (ship->y > 600)
        ship->y = 600;

    if (IsKeyPressed(KEY_SPACE))
    {
        if (numBullets >= MAX_BULLETS)
            return;
        struct Bullet *bullet = &bullets[numBullets];
        initBullet(bullet);
        bullet->x = ship->x;
        bullet->y = ship->y;
        numBullets++;
        PlaySound(laserSound);
    }

    // check collision with enemies
    for (int i = 0; i < numEnemies; i++)
    {
        if (CheckCollisionCircles((Vector2){ship->x, ship->y}, 20,
                                  (Vector2){enemies[i].x, enemies[i].y}, 20))
        {
            currentScreen = ENDING;
        }
    }
}

void drawShip(struct ship *ship)
{
    // draw ship from the center
    DrawTexturePro(ship->texture, (Rectangle){0, 0, ship->texture.width, ship->texture.height},
                   (Rectangle){ship->x, ship->y, ship->texture.width, ship->texture.height},
                   (Vector2){ship->texture.width / 2, ship->texture.height / 2}, 0, WHITE);
}
