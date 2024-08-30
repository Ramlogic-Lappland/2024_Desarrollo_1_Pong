#include <iostream>
#include "raylib.h"
using namespace std;

#include "Menu.h"
#include "BaseGame.h"

void initMenu()
{
    static string thisScreenName =  "Menu - Screen";

    screen.name = thisScreenName.c_str();
}

void updateMenu()
{
    if (IsKeyDown(KEY_SPACE))
    {
        initGame();
        currentScreen = game;
    }       
}

void drawMenu()
{
    DrawText("MENU!", (screen.size.x / 2) - MeasureText("MENU!", 40), 200, 40, BLUE);

    DrawText("PRESS SPACE TO START!", (screen.size.x / 2) - MeasureText("PRESS SPACE TO START!", 40), 300, 40, BLUE);
}