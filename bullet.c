#include "raylib.h"
#include "bullet.h"

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
