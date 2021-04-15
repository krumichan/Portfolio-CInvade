#include "Enemy1.h"
#include "Shot.h"

void Enemy1_Initial()
{
	int i;
	int x = WIDTH/2 - 23, y=1;

	for( i=0; i<MAX_ENEMY1_COUNT; i++ ) {
		
		if( i%10 == 0 ) { 
			x = WIDTH/2 - 23;
			y++;
		}

		Enemy1[i].x = x;
		Enemy1[i].y = y;
		Enemy1[i].LiveFlag = 1;
		Enemy1[i].MoveFlag = 1;
		Enemy1[i].StartX = x;

		x+= 5;
	}
}

void Enemy1_Draw()
{
	int i, j;

	for( i=0; i< MAX_ENEMY1_COUNT; i++ ) {
		
		if( !Enemy1[i].LiveFlag ) continue;

		int x = Enemy1[i].x - ENEMY1_SIZE/2;
		int y = Enemy1[i].y;

		if( y<0 && y>= HEIGHT-1 ) continue;

		for( j=0; j< ENEMY1_SIZE; j++ ) {
			if( x>=0 && x< WIDTH-2 ) Screen[y][x] = Enemy1Unit[j];
			x++;
		}
	}
}

void Enemy1_Action() 
{
	int i;

	for( i=0; i< MAX_ENEMY1_COUNT; i++ ) {
		if( !Enemy1[i].LiveFlag ) continue;

		if( Enemy1[i].MoveFlag ) Enemy1[i].x++;
		else Enemy1[i].x--;

		if( abs(Enemy1[i].StartX - Enemy1[i].x) > WIDTH/2-26 ) {
			Enemy1[i].y++;
			Enemy1[i].MoveFlag = !Enemy1[i].MoveFlag;
		}

		if( rand()%100 < 2 ) Shot_Create( ENEMY1_SHOT, Enemy1[i].x, Enemy1[i].y );
	}
}