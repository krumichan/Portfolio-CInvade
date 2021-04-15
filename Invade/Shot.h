#pragma once
#include "console.h"

typedef struct ShotInfo {
	int x, y;
	int Type;
	int UseFlag;
} SHOT;

#define ENEMY1_SHOT			0
#define MAX_SHOT_ENEMY1		30
extern SHOT E1_Shot[MAX_SHOT_ENEMY1];
extern char E1_Shot_Image;

#define ENEMY2_SHOT			1
#define MAX_SHOT_ENEMY2		30
extern SHOT E2_Shot[MAX_SHOT_ENEMY2];
extern char E2_Shot_Image;

#define BOSS1_SHOT			2
#define LINE_SHOT_BOSS		5
#define MAX_SHOT_BOSS		15
extern SHOT B_Shot[LINE_SHOT_BOSS][MAX_SHOT_BOSS];
extern char B_Shot_Image;

#define PLAYER_SHOT			3
#define LINE_SHOT_PLAYER	3
#define MAX_SHOT_PLAYER		30
extern SHOT SP_Shot[MAX_SHOT_PLAYER];
extern char SP_Shot_Image;
extern SHOT MP_Shot[LINE_SHOT_PLAYER][MAX_SHOT_PLAYER];
extern char MP_Shot_Image;

typedef struct B2_InShot {
	int x, y;
	int UseFlag;
} INSHOT;

typedef struct Boss2_Shot {
	INSHOT B2_XY[3][3];
	int UseFlag;
} BOSS2SHOT;

#define BOSS2_SHOT			4
#define MAX_SHOT_BOSS2		30
extern BOSS2SHOT B2_Shot[MAX_SHOT_BOSS2];

void Shot_Initial();
void Shot_Create( int _TYPE, int _X, int _Y );
void Shot_P_Draw();
void Shot_E1_Draw();
void Shot_E2_Draw();
void Shot_B_Draw();
void Shot_B2_Draw();
void Shot_P_Action();
void Shot_E1_Action();
void Shot_E2_Action();
void Shot_B_Action();
void Shot_B2_Action();