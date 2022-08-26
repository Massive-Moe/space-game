#include "bullets.h"
#include "game.h"
#include "math.h"

#define BULLET_SPEED 500

void ShootBullet(Vector2 p_position, float p_rotation)
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if(!bullets[i].active)
        {
            bullets[i].position.x = p_position.x;
            bullets[i].position.y = p_position.y;
            bullets[i].active = true;
            bullets[i].speed.x = sin(p_rotation)*BULLET_SPEED;
            bullets[i].speed.y = cos(p_rotation)*BULLET_SPEED;
            bullets[i].rotation = p_rotation;
            break;
        }
    }
}

void UpdateBullet()
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if(bullets[i].active)
        {
            bullets[i].rotation += 5;
            bullets[i].position.x -= bullets[i].speed.x * GetFrameTime();
            bullets[i].position.y += bullets[i].speed.y * GetFrameTime();

            if(bullets[i].position.x > SCREEN_WIDTH || bullets[i].position.x < 0)
                bullets[i].active = false;
            if(bullets[i].position.y > SCREEN_HEIGHT || bullets[i].position.y < 0)
                bullets[i].active = false;
        }
    }
}

void DrawBullet()
{
    for(int i = 0; i < MAX_BULLETS; i++)
    {
        if(bullets[i].active){
            DrawPolyLinesEx((Vector2){bullets[i].position.x+10,bullets[i].position.y+10},3,10,bullets[i].rotation,5,GRAY);
            DrawPolyLinesEx(bullets[i].position,3,10,bullets[i].rotation,5,WHITE);
        }
    }
}

