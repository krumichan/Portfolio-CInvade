#pragma once
#include "console.h"

typedef struct Enemy2Info {
	int x, y;
	int LiveFlag;
} ENEMY2;

#define ENEMY2_SIZE		3
extern char Enemy2Unit[ENEMY2_SIZE+1];

#define MAX_ENEMY2_COUNT		30
extern ENEMY2 Enemy2[MAX_ENEMY2_COUNT];
extern int X[MAX_ENEMY2_COUNT], Y[MAX_ENEMY2_COUNT];

void Enemy2_Initial();
void Enemy2_Draw();
void Enemy2_Action();