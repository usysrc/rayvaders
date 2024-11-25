#ifndef GAME_H
#define GAME_H

#include "ship.h"

// Define the game variables
int score;
float timer;

// Define the player ship instance
struct ship player;

// Define the gamestates
enum GameScreen
{
    GAMEPLAY,
    ENDING
} currentScreen;

// Define the functions
void initGame(void);
void updateGame(void);
void drawGame(void);

void initGameplay(void);
void updateGameplay(void);
void drawGameplay(void);

void initEnding(void);
void updateEnding(void);
void drawEnding(void);

#endif // GAME_H
