#include <raylib.h>
#include "game.h"

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Astro Assault");
    SetTargetFPS(60);

    InitGame();

    GAME_SCREEN currentScreen = GAMEPLAY;

    while (!WindowShouldClose())
    {
        switch (currentScreen)
        {
        case TITLE:
            break;

        case GAMEPLAY:
                UpdateGame();
                DrawGame();
            break;
        
        default:
            break;
        }
    }

    CloseWindow();
    return 0;
}

