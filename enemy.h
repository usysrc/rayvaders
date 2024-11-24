#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

struct Enemy
{
    float x;
    float y;
    float dx;
    float dy;
    float speed;
    bool active;
    Texture2D texture;
};

void initEnemy(struct Enemy *enemy);
void updateEnemy(struct Enemy *enemy);
void drawEnemy(struct Enemy *enemy);

// Function to update all the enemies
void initEnemies();
void updateEnemies();
void drawEnemies();

// Define the bullets array
#define MAX_ENEMIES 10
struct Enemy enemies[MAX_ENEMIES];
int numEnemies;

#endif // ENEMY_H