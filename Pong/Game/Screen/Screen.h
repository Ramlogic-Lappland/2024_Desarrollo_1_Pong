#pragma once
#include "../BaseGame.h"

struct Screen {
	string nameS;
	const char* name = nameS.c_str();
	Vector2 size; 
};

