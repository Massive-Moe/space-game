#include "player.h"
#include "game.h"
#include "bullets.h"
#include "utils.h"

#include "math.h"
#define PLAYER_SIZE_MULTIPLYER 10
#define PLAYER_RUN_SPEED 50

Player player;
Bullet bullets[MAX_BULLETS] = {0};

void InitPlayer()
{
    player.position = (Vector2){SCREEN_WIDTH/2,SCREEN_HEIGHT/2};
    player.rotation = 0;
    player.speed = (Vector2){0,0};
}

void UpdatePlayer()
{
    player.speed.x += (IsKeyDown(KEY_D) - IsKeyDown(KEY_A)) * PLAYER_RUN_SPEED * GetFrameTime();
    player.speed.y += (IsKeyDown(KEY_S) - IsKeyDown(KEY_W)) * PLAYER_RUN_SPEED * GetFrameTime();
    player.speed.x *= 0.9f;
    player.speed.y *= 0.9f;

    player.position.x += player.speed.x;
    player.position.y += player.speed.y;
    player.position.x = Cycle(-15, SCREEN_WIDTH+15, player.position.x);
    player.position.y = Cycle(-15, SCREEN_HEIGHT+15, player.position.y);

    player.rotation = atan2(GetMouseY() - player.position.y, GetMouseX() - player.position.x) - PI/2; //Have to subtract half pi to make rotations correct

    UpdateBullet();

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        ShootBullet(player.position,player.rotation);

}

void DrawPlayer()
{
    Vector2 finalPoints[4];

    for (int i = 0; i < 4; i++)
    {
        //Setup positions without rotation
        finalPoints[i] = {player.position.x + (player.points[i].x * PLAYER_SIZE_MULTIPLYER),
                          player.position.y + (player.points[i].y * PLAYER_SIZE_MULTIPLYER)};
        //Adding rotation
        finalPoints[i] = {player.position.x + cosf(player.rotation) * (finalPoints[i].x - player.position.x) - sinf(player.rotation) * (finalPoints[i].y - player.position.y),
                          player.position.y + sinf(player.rotation) * (finalPoints[i].x - player.position.x) + cosf(player.rotation) * (finalPoints[i].y - player.position.y)};
    }
    DrawTriangleFan(finalPoints,4,WHITE);
    //DrawRectangle(player.position.x-2, player.position.y-2-PLAYER_SIZE_MULTIPLYER,4,4,BLUE);
    DrawBullet();
}