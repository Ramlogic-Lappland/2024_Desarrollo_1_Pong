#include "raylib.h"
#include <iostream>
using namespace std;

#include "BaseGame.h"


//Declare player1 and player2 and ball
static createPlayer player1;
static createPlayer player2;
static createBall ball;
static int framesCounter = 0;

bool pause = 0;
bool defeat = 0;

void initGame()
{
   
    initPlayer(player1, 3, 5, screen.size);
    initPlayer(player2, 3, 5, screen.size);

    player1.position = { 0 + (player1.size.x) , (screen.size.y / 2) - (player1.size.y / 2) }; //Player 1 Position
    player2.position = { screen.size.x - (player2.size.x * 2) , (screen.size.y / 2) - (player2.size.y / 2) }; //Player  Position


    initPlayerRec(player1);
    initPlayerRec(player2);

    //init ball
    initBall(ball, screen.size, 20);
}


void updateGame()
{
    if (IsKeyPressed(KEY_P)) pause = !pause;
    if (player1.life < 1) defeat = true;
    if (player2.life < 1) defeat = true;

    if (!pause && !defeat)
    {
    if (IsKeyDown(KEY_W)) playerUp(player1);;
    if (IsKeyDown(KEY_S)) playerDown(player1, screen.size);
    if (IsKeyDown(KEY_UP)) playerUp(player2);
    if (IsKeyDown(KEY_DOWN)) playerDown(player2, screen.size);

    ball.Position.x += ball.Speed.x;
    ball.Position.y += ball.Speed.y;

    // Check walls collision for bouncing
    if ((ball.Position.x >= (GetScreenWidth() - ball.Radius)) || (ball.Position.x <= ball.Radius)) ball.Speed.x *= -1.0f;
    if (ball.Position.x >= (GetScreenWidth() - ball.Radius)) player2.life -= 1;
    if (ball.Position.x <= ball.Radius) player1.life -= 1;

    if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius)) ball.Speed.y *= -1.0f;


    ball.collision1 = CheckCollisionCircleRec(ball.Position, ball.Radius, player1.Rec); //player 1 collision
    if (ball.collision1) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;
    ball.collision2 = CheckCollisionCircleRec(ball.Position, ball.Radius, player2.Rec); //player 2 collision
    if (ball.collision2) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;
    }
    else framesCounter++;
}


void drawGame()
{
    DrawRectangleRec(player1.Rec, WHITE);
    DrawRectangleRec(player2.Rec, WHITE);
    DrawCircleV(ball.Position, (float)ball.Radius, MAROON);
    DrawText("Player 1 vs Player 2!", (screen.size.x / 2) - MeasureText("Player 1 vs Player 2!", 20), 60, 40, DARKGRAY);
    DrawText(TextFormat("Player 1 lives:%i", player1.life), 40, 80, 40, RED);
    DrawText(TextFormat("Player 2 lives:%i", player2.life), screen.size.x - MeasureText("Player 2 lives: % i", 40), 80, 40, RED);

    if (pause && ((framesCounter / 30) % 2)) DrawText("GAME IS PAUSED", (screen.size.x / 2) -MeasureText("GAME IS PAUSED", 15), 200, 30, RED);

    if (defeat && ((framesCounter / 30) % 2)) DrawText("GAME OVER", (screen.size.x / 2) - MeasureText("GAME OVER", 30), 200, 60, RED);
    if (defeat) { 
        if(player1.life > 0) DrawText("PLAYER 1 WINS", (screen.size.x / 2) - MeasureText("PLAYER 1 WINS", 30), 270, 60, RED);
        else
        DrawText("PLAYER 2 WINS", (screen.size.x / 2) - MeasureText("PLAYER 2 WINS", 30), 270, 60, RED);
    };
}

void initGameAssets()
{

}

void deInitGameAssets()
{

}