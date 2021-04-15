#pragma once
#include "console.h"

#define MAX_STAGE	3
extern int Stage_Count;
extern int Stage_Flag[MAX_STAGE+1];

void DrawLife();
int Check_End_Game();
int Check_Clear();
void Draw();
void Action();
void Object_Initial();