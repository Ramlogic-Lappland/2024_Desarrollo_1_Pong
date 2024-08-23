#include "SceneManager.h"
#include "BaseGame.h"
#include "Menu.h"

int run(void)
{
    init();

    while (!WindowShouldClose())
    {
        update();

        draw();
    }

    close();

    return 0;
}

void init()
{
    screen.size = { 1200.0f , 800.0f };
    CurrentScreen currentScreen = menu;

    initMenu();

    InitWindow(screen.size.x, screen.size.y, screen.name);

}

void update()
{
    switch (currentScreen)
    {
    case menu:
        updateMenu();
        break;
    case game:
        updateGame();
        break;
    default:
        break;
    }
}

void draw()
{
    BeginDrawing();
    ClearBackground(LIGHTGRAY);

    if (currentScreen == menu)
    {
        drawMenu();
    }
    else if (currentScreen == game)
    {
        drawGame();
    }

    EndDrawing();
}

void close()
{
    CloseWindow();
    closeGame();
}