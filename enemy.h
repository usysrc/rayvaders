#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

typedef struct
{
    float x;
    float y;
    float dx;
    float dy;
    float acceleration;
    float maxSpeed;
    float speed;
    bool active;
    Texture2D texture;
} Enemy;

void initEnemy(Enemy *enemy);
void updateEnemy(Enemy *enemy);
void drawEnemy(Enemy *enemy);

// Function to update all the enemies
void initEnemies(void);
void updateEnemies(void);
void drawEnemies(void);

// Define the bullets array
#define MAX_ENEMIES 10
Enemy enemies[MAX_ENEMIES];
int numEnemies;

#endif // ENEMY_H
