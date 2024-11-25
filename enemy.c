#include "raylib.h"
#include "enemy.h"
#include "game.h"

// store the texture for the enemy
Texture2D enemyTexture;

void initEnemy(struct Enemy *enemy)
{
    enemy->dx = 0;
    enemy->dy = 1;
    enemy->x = GetRandomValue(0, 800);
    enemy->y = -50;
    enemy->acceleration = 50;
    enemy->speed = 0;
    enemy->maxSpeed = 200 + GetRandomValue(-50, 50);

    // have a chance of being a very fast enemy, spawned left or right of the player
    // but only start after while to give the player a chance
    if ((timer > 3) && (GetRandomValue(0, 5) == 0))
    {
        enemy->acceleration = 200;
        enemy->maxSpeed = 500 + GetRandomValue(-100, 100);
        enemy->y = player.y;
        enemy->dy = 0;
        if (GetRandomValue(0, 1) == 0)
        {
            enemy->dx = 1;
            enemy->x = -50;
        }
        else
        {
            enemy->dx = -1;
            enemy->x = GetScreenWidth() + 50;
        }
    }
    enemy->texture = enemyTexture;
}

void updateEnemy(struct Enemy *enemy)
{
    if (enemy->speed < enemy->maxSpeed)
    {
        enemy->speed += enemy->acceleration * GetFrameTime();
    }
    enemy->x += enemy->dx * enemy->speed * GetFrameTime();
    enemy->y += enemy->dy * enemy->speed * GetFrameTime();
    if (enemy->y > 600 || enemy->x < -50 || enemy->x > GetScreenWidth() + 50)
    {
        enemy->active = false;
    }
}

void drawEnemy(struct Enemy *enemy)
{
    // draw enemy from the center
    DrawTexturePro(enemy->texture, (Rectangle){0, 0, enemy->texture.width, enemy->texture.height},
                   (Rectangle){enemy->x, enemy->y, enemy->texture.width, enemy->texture.height},
                   (Vector2){enemy->texture.width / 2, enemy->texture.height / 2}, 0, WHITE);
}

void initEnemies(void)
{
    enemyTexture = LoadTexture("resources/enemy.png");
    numEnemies = 0;
}

// Function to update all the enemies
void updateEnemies(void)
{
    // spawn a new enemy at random
    if ((GetRandomValue(0, 100) < 2) || (numEnemies < MAX_ENEMIES / 2))
    {
        if (numEnemies >= MAX_ENEMIES)
            return;
        struct Enemy *enemy = &enemies[numEnemies];
        initEnemy(enemy);
        enemy->active = true;
        numEnemies++;
    }

    // reverse iterate, update enemies and remove inactive enemies
    for (int i = numEnemies - 1; i >= 0; i--)
    {
        updateEnemy(&enemies[i]);
        if (!enemies[i].active)
        {
            numEnemies--;
            enemies[i] = enemies[numEnemies];
        }
    }
}

void drawEnemies(void)
{
    for (int i = 0; i < numEnemies; i++)
    {
        drawEnemy(&enemies[i]);
    }
}
