#pragma once
#include "console.h"

typedef struct Enemy1_Info {
	int x, y;
	int LiveFlag;
	int MoveFlag;
	int StartX;
} ENEMY1;

#define ENEMY1_SIZE		3
extern char Enemy1Unit[ENEMY1_SIZE+1];

#define MAX_ENEMY1_COUNT		30
extern ENEMY1 Enemy1[MAX_ENEMY1_COUNT];

void Enemy1_Initial();
void Enemy1_Draw();
void Enemy1_Action();