#pragma once
#include <raylib.h>
#define MAX_BULLETS 10

typedef struct Bullet
{
    Vector2 position;
    Vector2 speed;
    float rotation;
    bool active;
} Bullet;

extern Bullet bullets[];

void ShootBullet(Vector2 position, float rotation);
void UpdateBullet();
void DrawBullet();