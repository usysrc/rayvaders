#include "raylib.h"
#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include "particle.h"

Sound explosionSound;
Texture2D bulletTexture;

void initBullet(struct Bullet *bullet)
{
    bullet->active = true;
    bullet->speed = 1000;
    bullet->texture = bulletTexture;
}

void updateBullet(struct Bullet *bullet)
{
    if (bullet->active)
    {
        float prevY = bullet->y;
        bullet->y -= bullet->speed * GetFrameTime();

        float bulletWidth = 20.0f;
        Rectangle bulletRect = {bullet->x, bullet->y, bulletWidth, prevY - bullet->y};

        // check for collision with enemies
        for (int i = 0; i < numEnemies; i++)
        {
            struct Enemy *enemy = &enemies[i];
            if (!enemy->active)
                continue;

            // Check for collision along the vertical path of the bullet
            Vector2 enemyPos = {enemy->x, enemy->y};
            float enemyRadius = 20.0f;

            if (CheckCollisionCircleRec(enemyPos, enemyRadius, bulletRect))
            {
                bullet->active = false;
                enemies[i].active = false;
                score++;
                PlaySound(explosionSound);
                particleBust(enemies[i].x, enemies[i].y);
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

void initBullets(void)
{
    // Initialize the bullets array
    numBullets = 0;
    // Load resources
    explosionSound = LoadSound("resources/explosion.wav");
    bulletTexture = LoadTexture("resources/bullet.png");
}

void updateBullets(void)
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

void drawBullets(void)
{
    for (int i = 0; i < numBullets; i++)
    {
        drawBullet(&bullets[i]);
    }
}
