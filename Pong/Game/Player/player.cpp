#include "player.h"


void  initPlayer(createPlayer& player, int lives, float speed, Vector2 screenSize)
{

	player.life = lives;
	player.speed = speed;

	player.size.x = screenSize.x / 26;
	player.size.y = screenSize.y / 5;


	player.Rec = { player.position.x, player.position.y, player.size.x, player.size.y };
	
}

void playerUp(createPlayer& player)
{
	if (player.Rec.y - player.speed > 0) player.Rec.y -= player.speed;
}

void playerDown(createPlayer& player, Vector2 Screen)
{
	if (player.Rec.y + player.speed < (Screen.y - player.Rec.height)) player.Rec.y += player.speed;
}