#include "raylib.h"
#include "game.h"

#define no_args void

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT);
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(60);
    InitWindow(800, 600, "RAYVADERS");
    InitAudioDevice();
    initGame();

    while (!WindowShouldClose())
    {
        updateGame();
        BeginDrawing();
        drawGame();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
