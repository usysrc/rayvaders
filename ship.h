#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"

struct ship
{
    float x;
    float y;
    float speed;
    Texture2D texture;
};

void initShip(struct ship *ship);
void updateShip(struct ship *ship);
void drawShip(struct ship *ship);

#endif // SHIP_H
