#pragma once
#include <raylib.h>

typedef struct Player
{
    const Vector2 points[4] = {(Vector2){ 0,-1},
                               (Vector2){-2,-2},
                               (Vector2){ 0, 2},
                               (Vector2){ 2,-2}};
    Vector2 position;
    float rotation;
    Vector2 speed;
} Player;

extern Player player;

void InitPlayer();
void UpdatePlayer();
void DrawPlayer();
