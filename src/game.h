#pragma once
#include <raylib.h>

static const int SCREEN_WIDTH  = 640;
static const int SCREEN_HEIGHT = 480;

typedef enum GAME_SCREEN{TITLE = 0, GAMEPLAY} GAME_SCREEN;

void UpdateGame(void);
void DrawGame(void);
void InitGame(void);
