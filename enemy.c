#include "raylib.h"
#include "enemy.h"

// store the texture for the enemy
Texture2D enemyTexture;

void initEnemy(struct Enemy *enemy)
{
    enemy->x = GetRandomValue(0, 800);
    enemy->y = 0;
    enemy->speed = 100;
    enemy->texture = enemyTexture;
}

void updateEnemy(struct Enemy *enemy)
{
    enemy->y += enemy->speed * GetFrameTime();
    if (enemy->y > 600)
    {
        enemy->active = false;
    }
}

void drawEnemy(struct Enemy *enemy)
{
    DrawTexture(enemy->texture, enemy->x, enemy->y, WHITE);
}

void initEnemies()
{
    enemyTexture = LoadTexture("resources/enemy.png");
    numEnemies = 0;
}

// Function to update all the enemies
void updateEnemies()
{
    // spawn a new enemy at random
    if (GetRandomValue(0, 100) < 2)
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

void drawEnemies()
{
    for (int i = 0; i < numEnemies; i++)
    {
        drawEnemy(&enemies[i]);
    }
}
