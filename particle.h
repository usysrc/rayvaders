#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"

struct Particle
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
};

void initParticle(struct Particle *particle);
void updateParticle(struct Particle *particle);
void drawParticle(struct Particle *particle);

// Function to update all the particles
void initParticles(void);
void updateParticles(void);
void drawParticles(void);
void particleBust(float x, float y);

// Define the bullets array
#define MAX_PARTICLES 100
struct Particle particles[MAX_PARTICLES];
int numParticles;

#endif // PARTICLE_H
