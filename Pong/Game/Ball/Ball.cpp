#include "Ball.h"


void initBall(createBall& ball,Vector2 screenSize, int rad)
{
    ball.collision1 = false;
    ball.collision2 = false;
    ball.Position = { screenSize.x / 2.0f, screenSize.y / 2.0f };
    ball.Speed = { 5.0f, 4.0f };
    ball.Radius = rad;
}