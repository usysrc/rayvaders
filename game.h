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
void initGame();
void updateGame();
void drawGame();

void initGameplay();
void updateGameplay();
void drawGameplay();

void initEnding();
void updateEnding();
void drawEnding();

#endif // GAME_H