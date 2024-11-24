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
            if (CheckCollisionCircles((Vector2){bullet->x, bullet->y}, 5,
                                      (Vector2){enemies[i].x, enemies[i].y}, 20))

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
        // draw bullet from the center
        DrawTexturePro(bullet->texture, (Rectangle){0, 0, bullet->texture.width, bullet->texture.height},
                       (Rectangle){bullet->x, bullet->y, bullet->texture.width, bullet->texture.height},
                       (Vector2){bullet->texture.width / 2, bullet->texture.height / 2}, 0, WHITE);
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
