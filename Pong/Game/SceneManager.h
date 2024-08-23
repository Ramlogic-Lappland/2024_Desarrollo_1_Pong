#pragma once
#include "Main.h"
#include "Menu.h"
#include "Screen/Screen.h"

int run(void);
void init();
void update();
void draw();
void close();


enum CurrentScreen
{
    menu,
    game,
};

extern Screen screen;
extern CurrentScreen currentScreen;


