#ifndef SHIP_H
#define SHIP_H

#include "raylib.h"

typedef struct
{
    float x;
    float y;
    float speed;
} ship;

void initShip(ship *ship);
void updateShip(ship *ship);
void drawShip(ship *ship);

#endif // SHIP_H
