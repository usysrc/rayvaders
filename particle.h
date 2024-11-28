#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"

typedef struct
{
    float x;
    float y;
    float dx;
    float dy;
    float life;
    float alive;
    float speed;
    bool active;
    Texture2D texture;
} Particle;

void initParticle(Particle *particle);
void updateParticle(Particle *particle);
void drawParticle(Particle *particle);

// Function to update all the particles
void initParticles(void);
void updateParticles(void);
void drawParticles(void);
void particleBust(float x, float y);

// Define the bullets array
#define MAX_PARTICLES 1000
Particle particles[MAX_PARTICLES];
int numParticles;

#endif // PARTICLE_H
