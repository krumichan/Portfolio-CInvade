#include "Item.h"
#include "Shot.h"

void Item_Initial()
{
	int i;

	for( i=0; i<MAX_ITEM_COUNT; i++ )
		Item[i].LiveFlag = 0;
}

void Item_Create( int _X, int _Y )
{
	int i;

	for( i=0; i<MAX_ITEM_COUNT; i++ ) {
		if( Item[i].LiveFlag ) continue;

		Item[i].x = _X;
		Item[i].y = _Y;
		Item[i].LiveFlag = 1;
		Item[i].Type = rand()%3;

		return;
	}
}
void Item_Draw()
{
	int i;

	for( i=0; i<MAX_ITEM_COUNT; i++ ) {
		if( !Item[i].LiveFlag ) continue;

		if( Item[i].Type == 0 )
			Screen[ Item[i].y ][ Item[i].x ] = H_Item_Image;
		else if( Item[i].Type == 1 ) 
			Screen[ Item[i].y ][ Item[i].x ] = G_Item_Image;
		else if( Item[i].Type == 2 )
			Screen[ Item[i].y ][ Item[i].x ] = Z_Item_Image;
	}
}
void Item_Action()
{
	int i;

	for( i=0; i<MAX_ITEM_COUNT; i++ ) {
		if( !Item[i].LiveFlag ) continue;

		Item[i].y++;

		if( Item[i].y > HEIGHT-1 ) Item[i].LiveFlag = 0;
	}
}

void Zero_Shot()
{
	int i, j;

	for( i=0; i<MAX_SHOT_ENEMY1; i++ )
		E1_Shot[i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_ENEMY2; i++ )
		E2_Shot[i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_BOSS; i++ )
		for( j=0; j<LINE_SHOT_BOSS; j++ )
			B_Shot[j][i].UseFlag = 0;

}