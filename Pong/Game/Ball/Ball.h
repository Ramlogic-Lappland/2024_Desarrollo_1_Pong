#pragma once
#include "raylib.h"

struct  createBall
{
    bool collision1;
    bool collision2;
    Vector2 Position;
    Vector2 Speed;
    int Radius;
};

void initBall(createBall& ball, Vector2 screenSize, int rad);
