#include "raylib.h"
#include "game.h"

int main(void)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
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