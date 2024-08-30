#pragma once
#include "raylib.h"

struct createPlayer
{
	Vector2 size;
	Vector2 position;
	float speed;
	int life;

	Rectangle Rec;
};

void  initPlayer(createPlayer& player, int lives, float speed, Vector2 screenSize);


void playerUp(createPlayer& player);

void playerDown(createPlayer& player, Vector2 Screen);

