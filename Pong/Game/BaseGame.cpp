#include "BaseGame.h"

int main(void)
{
    // Initialization
    Screen gameScreen;
    gameScreen.name = "Pong";
    gameScreen.size.x = 1200.0f;
    gameScreen.size.y = 800.0f;

    InitWindow(gameScreen.size.x, gameScreen.size.y, gameScreen.name);

    //Declare player1 and player2 and ball
    createPlayer player1;
    createPlayer player2;
    createBall ball;

    //Player 1 size
    player1.size.x = gameScreen.size.x / 26; player1.size.y = gameScreen.size.y / 4.5f;
    //Player 2 size
    player2.size.x = gameScreen.size.x / 26; player2.size.y = gameScreen.size.y / 4.5f;

    //Player 1 Position
    player1.position.x = 0 + (player1.size.x);
    player1.position.y = (gameScreen.size.y / 2) - (player1.size.y / 2);
    //Player 2 Position
    player2.position.x = gameScreen.size.x - (player2.size.x * 2);
    player2.position.y = (gameScreen.size.y / 2) - (player2.size.y / 2);

    //players speed
    player1.speed = 8;
    player2.speed = 8;

    player1.Rec = { player1.position.x, player1.position.y, player1.size.x, player1.size.y };
    player2.Rec = { player2.position.x, player2.position.y, player2.size.x, player2.size.y };

    //ball
    ball.Position = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f }; // ball 
    ball.Speed = { 5.0f, 4.0f };
    ball.Radius = 20;

    bool pause = false;
    bool collision1 = false;
    bool collision2 = false;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    cout << "size: " << player1.Rec.height;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
    
        if (IsKeyDown(KEY_W)) player1.up();
        if (IsKeyDown(KEY_S)) player1.down(gameScreen.size);
        if (IsKeyDown(KEY_UP)) player2.up();
        if (IsKeyDown(KEY_DOWN)) player2.down(gameScreen.size);
     
        ball.Position.x += ball.Speed.x;
        ball.Position.y += ball.Speed.y;

        // Check walls collision for bouncing
        if ((ball.Position.x >= (GetScreenWidth() - ball.Radius)) || (ball.Position.x <= ball.Radius)) ball.Speed.x *= -1.0f;
        if ((ball.Position.y >= (GetScreenHeight() - ball.Radius)) || (ball.Position.y <= ball.Radius)) ball.Speed.y *= -1.0f;

        collision1 = CheckCollisionCircleRec(ball.Position, ball.Radius, player1.Rec);
        collision2 = CheckCollisionCircleRec(ball.Position, ball.Radius, player2.Rec);
        if (collision1) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;
        if (collision2) ball.Speed.x *= -1.0, ball.Speed.y *= -1.0f;
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(LIGHTGRAY);


        DrawRectangleRec(player1.Rec, WHITE);
        DrawRectangleRec(player2.Rec, WHITE);
        DrawCircleV(ball.Position, (float)ball.Radius, MAROON);
        DrawText("Congrats! You created your first window!", 190, 200, 20, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}