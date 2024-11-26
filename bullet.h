#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

typedef struct
{
    float x;
    float y;
    float dx;
    float dy;
    float speed;
    bool active;
    Texture2D texture;
} Bullet;

void initBullet(Bullet *bullet);
void updateBullet(Bullet *bullet);
void drawBullet(Bullet *bullet);

// Function to update all the bullets
void initBullets(void);
void updateBullets(void);
void drawBullets(void);

// Define the bullets array
#define MAX_BULLETS 5
Bullet bullets[MAX_BULLETS];
int numBullets;

#endif // BULLET_H
