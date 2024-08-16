#pragma once
#include "../BaseGame.h"
#include "../Screen/Screen.h"


struct createPlayer
{

public:
	Vector2 size;
	Vector2 position;
	string name;
	float speed;

	Rectangle Rec;

	void up()
	{
		if (Rec.y - speed > 0) Rec.y -= speed;
	}
	void down(Vector2 gameScreen)
	{
		if (Rec.y + speed < (gameScreen.y - Rec.height)) Rec.y += speed;
	}

};


