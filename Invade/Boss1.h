#pragma once
#include "console.h"

typedef struct Boss1Info {
	int x, y;
	int LiveFlag;
	int Time;
	int HP;
	int Max_HP;
} BOSS1;

extern char Boss1Unit[3][5];
extern BOSS1 Boss1;

void Boss1_Initial();
void Boss1_Draw();
void Boss1_Action();