#include "raylib.h"
#include "particle.h"

Texture2D particleTexture;

void initParticle(struct Particle *particle)
{
    particle->life = 0.25;
    particle->alive = 0;
    particle->dx = GetRandomValue(-10, 10);
    particle->dy = GetRandomValue(-10, 10);
    particle->speed = 100;
    particle->active = true;
    particle->texture = particleTexture;
}

void updateParticle(struct Particle *particle)
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

void drawParticle(struct Particle *particle)
{
    if (particle->active)
    {
        // set alpha to fade out the particle
        float alpha = 1 - particle->alive / particle->life;
        Color color = {255, 255, 255, 255 * alpha};
        DrawTexture(particle->texture, particle->x, particle->y, color);
    }
}

void particleBust(float x, float y)
{
    int maxParticles = 5;
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        if (!particles[i].active)
        {
            maxParticles--;
            particles[i].x = x;
            particles[i].y = y;
            initParticle(&particles[i]);
            if (maxParticles <= 0)
            {
                break;
            }
        }
    }
}

void initParticles(void)
{
    numParticles = 0;
    particleTexture = LoadTexture("resources/particle.png");
}

void updateParticles(void)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        updateParticle(&particles[i]);
    }
}

void drawParticles(void)
{
    for (int i = 0; i < MAX_PARTICLES; i++)
    {
        drawParticle(&particles[i]);
    }
}
