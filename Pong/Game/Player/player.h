#pragma once
#include "../SceneManager.h"
#include "../Screen/Screen.h"


struct createPlayer
{
	
public:

	createPlayer();
	~createPlayer();

	Vector2 size;
	Vector2 position;
	string name;
	float speed;
	int life;

	Rectangle Rec;

	void initPlayer();

	void initPlayerRec();

	void up();

	void down(Vector2 gameScreen);

private:

};


