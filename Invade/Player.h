#pragma once
#include "console.h"

typedef struct PlayerInfo {
	int x, y;
	int LiveFlag;
	int HP;
	int Max_HP;
	int Score;
	int ShotState;
} PLAYER;

#define PLAYER_SIZE		5
extern char PlayerUnit[PLAYER_SIZE+1];
extern PLAYER Player;

void Player_Initial();
void Player_Stage_Initial();
void Player_Draw();
void Player_Action();