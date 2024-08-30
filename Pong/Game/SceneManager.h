#pragma once
#include "raylib.h"

int run(void);
void init();
void update();
void draw();
void close();

struct Screen {
	const char* name;
	Vector2 size;
};

enum CurrentScreen
{
    menu,
    game,
};

extern Screen screen;
extern CurrentScreen currentScreen;


