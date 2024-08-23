#include "player.h"


createPlayer::createPlayer()
{

}

createPlayer::~createPlayer()
{

}

void  createPlayer::initPlayer()
{
	size.x = screen.size.x / 26; size.y = screen.size.y / 4.5f;
	speed = 8;
}

void createPlayer::initPlayerRec()
{
	Rec = { position.x, position.y, size.x, size.y };
}

void createPlayer::up()
{
	if (Rec.y - speed > 0) Rec.y -= speed;
}

void createPlayer::down(Vector2 gameScreen)
{
	if (Rec.y + speed < (gameScreen.y - Rec.height)) Rec.y += speed;
}