#include "game.h"
#include "player.h"

void InitGame(void)
{
    InitPlayer();
}

void UpdateGame(void)
{
    UpdatePlayer();
}

void DrawGame(void)
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawPlayer();
    DrawFPS(10,10);

    EndDrawing();
}