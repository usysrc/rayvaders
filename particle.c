#include "raylib.h"
#include "particle.h"
#include <math.h>

Texture2D particleTexture;

void initParticle(Particle *particle)
{
    particle->life = 0.5;
    particle->alive = 0;
    particle->dx = GetRandomValue(-10, 10);
    particle->dy = GetRandomValue(-10, 10);
    particle->speed = 300;
    particle->active = true;
}

void updateParticle(Particle *particle)
{
    if (!particle->active)
        return;
    particle->alive += GetFrameTime();
    if (particle->alive >= particle->life)
    {
        particle->active = false;
        return;
    }
    particle->x += particle->dx * particle->speed * GetFrameTime();
    particle->y += particle->dy * particle->speed * GetFrameTime();
}

void drawParticle(Particle *particle)
{
    if (particle->active)
    {
        // set alpha to fade out the particle
        float alpha = 1 - particle->alive / particle->life;
        Color color = {255, 255, 255, 255 * alpha};
        DrawTexturePro(particleTexture, (Rectangle){0, 0, particleTexture.width, particleTexture.height}, (Rectangle){particle->x, particle->y, particleTexture.width, particleTexture.height}, (Vector2){particleTexture.width / 2, particleTexture.height / 2}, 0, color);
    }
}

void particleBust(float x, float y)
{
    int maxParticles = GetRandomValue(10, 20);
    for (int i = 0; i < maxParticles; i++)
    {
        if (numParticles >= MAX_PARTICLES)
            return;
        particles[numParticles].x = x;
        particles[numParticles].y = y;
        initParticle(&particles[numParticles]);
        // distribute the particles in a circle
        particles[numParticles].dx = cos(i * 2 * PI / maxParticles);
        particles[numParticles].dy = sin(i * 2 * PI / maxParticles);
        particles[numParticles].speed = 300 + GetRandomValue(-100, 100);
        numParticles++;
    }
}

void initParticles(void)
{
    numParticles = 0;
    particleTexture = LoadTexture("resources/particle.png");
}

void updateParticles(void)
{

    // reverse iterate, update enemies and remove inactive enemies
    for (int i = numParticles - 1; i >= 0; i--)
    {
        updateParticle(&particles[i]);
        if (!particles[i].active)
        {
            numParticles--;
            particles[i] = particles[numParticles];
        }
    }
}

void drawParticles(void)
{
    for (int i = 0; i < numParticles; i++)
    {
        drawParticle(&particles[i]);
    }
}
