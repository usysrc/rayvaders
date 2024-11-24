#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"

struct Bullet
{
    float x;
    float y;
    float dx;
    float dy;
    float speed;
    bool active;
    Texture2D texture;
};

void initBullet(struct Bullet *bullet);
void updateBullet(struct Bullet *bullet);
void drawBullet(struct Bullet *bullet);

// Function to update all the bullets
void updateBullets();
void drawBullets();

// Define the bullets array
#define MAX_BULLETS 5
struct Bullet bullets[MAX_BULLETS];
int numBullets;

#endif // BULLET_H