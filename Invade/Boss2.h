#pragma once
#include "console.h"

typedef struct Boss2 {
	int x, y;
	int LiveFlag;
	int HP;
	int Max_HP;
} BOSS2;

extern int Count;
extern int B2_X, B2_Y;

extern BOSS2 Boss2;
extern char Boss2Unit[3][5];

void Boss2_Initial();
void Boss2_Draw();
void Boss2_Action();