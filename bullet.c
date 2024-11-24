#include "raylib.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"

void initBullet(struct Bullet *bullet)
{
    bullet->active = true;
    bullet->speed = 800;
    bullet->texture = LoadTexture("resources/bullet.png");
}

void updateBullet(struct Bullet *bullet)
{
    if (bullet->active)
    {
        bullet->y -= bullet->speed * GetFrameTime();

        // check for collision with enemies
        for (int i = 0; i < numEnemies; i++)
        {
            if (CheckCollisionCircles(
                    (Vector2){bullet->x + bullet->texture.width / 2, bullet->y + bullet->texture.height / 2}, bullet->texture.width / 2,
                    (Vector2){enemies[i].x + enemies[i].texture.width / 2, enemies[i].y + enemies[i].texture.height / 2}, enemies[i].texture.width / 2))
            {
                bullet->active = false;
                enemies[i].active = false;
                score++;
            }
        }

        // check if bullet is out of bounds
        if (bullet->y + bullet->texture.height < 0)
        {
            bullet->active = false;
        }
    }
}

void drawBullet(struct Bullet *bullet)
{
    if (bullet->active)
    {
        DrawTexture(bullet->texture, bullet->x, bullet->y, WHITE);
    }
}

void initBullets()
{
    numBullets = 0;
}

void updateBullets()
{
    // reverse iterate and update bullets and remove inactive bullets
    for (int i = numBullets - 1; i >= 0; i--)
    {
        updateBullet(&bullets[i]);
        if (!bullets[i].active)
        {
            numBullets--;
            bullets[i] = bullets[numBullets];
        }
    }
}

void drawBullets()
{
    for (int i = 0; i < numBullets; i++)
    {
        drawBullet(&bullets[i]);
    }
}
