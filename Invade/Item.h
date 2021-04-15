#pragma once
#include "console.h"

typedef struct Item {
	int x, y;
	int LiveFlag;
	int Type;
} ITEM;

#define HP_Item		0
#define GUN_Item	1
#define ZERO_Item	2

extern char H_Item_Image;
extern char G_Item_Image;
extern char Z_Item_Image;

#define MAX_ITEM_COUNT		10
extern ITEM Item[MAX_ITEM_COUNT];

void Item_Initial();
void Item_Create( int _X, int _Y );
void Item_Draw();
void Item_Action();
void Zero_Shot();