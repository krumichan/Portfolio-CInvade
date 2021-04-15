#include "Enemy2.h"
#include "Shot.h"

void Enemy2_Initial()
{
	int i, Ren;

	for( i=0; i< MAX_ENEMY2_COUNT; i++ ) {
		Enemy2[i].x = rand()%(WIDTH-7);
		Enemy2[i].y = rand()%(HEIGHT-8);
		Enemy2[i].LiveFlag = 1;

		Ren = rand()%4;

		if( Ren == 0 ) {
			X[i] = 1;
			Y[i] = 1;
		}
		else if( Ren == 1 ) {
			X[i] = 1;
			Y[i] = -1;
		}
		else if( Ren == 2 ) {
			X[i] = -1;
			Y[i] = 1;
		}
		else if( Ren == 3 ) {
			X[i] = -1;
			Y[i] = -1;
		}
	}
}

void Enemy2_Draw()
{
	int i, j;

	for( i=0; i< MAX_ENEMY2_COUNT; i++ ) {

		if( !Enemy2[i].LiveFlag ) continue;

		int x = Enemy2[i].x - ENEMY2_SIZE/2;
		int y = Enemy2[i].y;

		if( y<0 || y>=HEIGHT ) continue;

		for( j=0; j<ENEMY2_SIZE; j++ ) {
			if( x>=0 && x<WIDTH-2 ) Screen[y][x] = Enemy2Unit[j];
			x++;
		}
	}
}

void Enemy2_Action()
{
	int i;

	for( i=0; i<MAX_ENEMY2_COUNT; i++ ) {
		if( !Enemy2[i].LiveFlag ) continue;

		Enemy2[i].x += X[i];
		Enemy2[i].y += Y[i];

		if( Enemy2[i].x >= WIDTH-2-ENEMY2_SIZE/2 || Enemy2[i].x < 1+ENEMY2_SIZE/2 )
			X[i] = -X[i];
		if( Enemy2[i].y < 1 || Enemy2[i].y >= HEIGHT-8 )
			Y[i] = -Y[i];

		if( rand()%100 < 2 ) Shot_Create( ENEMY2_SHOT, Enemy2[i].x, Enemy2[i].y );
	}
}