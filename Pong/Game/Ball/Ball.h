#pragma once
#include "../BaseGame.h"

class  createBall {
public:
    createBall();

    ~createBall();

    bool collision1;
    bool collision2;
    Vector2 Position;
    Vector2 Speed;
    int Radius;
};

