#include "BaseGame.h"


//Declare player1 and player2 and ball
static createPlayer player1;
static createPlayer player2;
static createBall ball;

bool pause = false;

void initGame()
{
    static string thisScreenName = "Pong";
    screen.name = thisScreenName.c_str();

    player1.initPlayer();
    player2.initPlayer();

    //Player 1 Position
    player1.position.x = 0 + (player1.size.x);
    player1.position.y = (screen.size.y / 2) - (player1.size.y / 2);
    //Player 2 Position
    player2.position.x = screen.size.x - (player2.size.x * 2);
    player2.position.y = (screen.size.y / 2) - (player2.size.y / 2);

    player1.initPlayerRec();
    player2.initPlayerRec();
}


void updateGame()
{
    if (IsKeyDown(KEY_W)) player1.up();
    if (IsKeyDown(KEY_S)) player1.down(screen.size);
    if (IsKeyDown(KEY_UP)) player2.up();
    if (IsKeyDown(KEY_DOWN)) player2.down(screen.size);

    ball.Position.x += ball.Speed.x;
    ball.Position.y += ball.Speed.y;

    // Check walls collision for bouncing
    if ((ball.Position.x >= (GetScreenWidth() - ball.Radius)) || (ball.Position.x <= ball.Radius)) ball.Speed.x *= -1.0f;
    if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius)) ball.Speed.y *= -1.0f;


    ball.collision1 = CheckCollisionCircleRec(ball.Position, ball.Radius, player1.Rec); //player 1 collision
    if (ball.collision1) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;
    ball.collision2 = CheckCollisionCircleRec(ball.Position, ball.Radius, player2.Rec); //player 2 collision
    if (ball.collision2) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;

}


void drawGame()
{
    DrawRectangleRec(player1.Rec, WHITE);
    DrawRectangleRec(player2.Rec, WHITE);
    DrawCircleV(ball.Position, (float)ball.Radius, MAROON);
    DrawText("Player 1 vs Player 2!", (screen.size.x / 2) - MeasureText("PLAYER 1 VS PLAYER 2!", 40), 200, 40, DARKGRAY);
}

void closeGame()
{
    player1.~createPlayer();
    player2.~createPlayer();
}