#pragma once
#include "console.h"

typedef struct Wall {
	int LeftX, RightX;
	int MoveFlag;
	char Wall_Image;
} WALL;

extern WALL Wall[HEIGHT];

void Wall_Initial();
void Wall_Draw();
void Wall_Action();