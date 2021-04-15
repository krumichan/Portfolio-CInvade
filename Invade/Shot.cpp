#include "Boss1.h"
#include "Boss2.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Player.h"
#include "Shot.h"

void Shot_Initial()
{
	int i, j;

	for( i=0; i<MAX_SHOT_ENEMY1; i++ )
		E1_Shot[i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_ENEMY2; i++ )
		E2_Shot[i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_BOSS; i++ )
		for( j=0; j<LINE_SHOT_BOSS; j++ )
			B_Shot[j][i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_PLAYER; i++ )
		for( j=0; j<LINE_SHOT_PLAYER; j++ )
			MP_Shot[j][i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_PLAYER; i++ )
		SP_Shot[i].UseFlag = 0;

	for( i=0; i<MAX_SHOT_BOSS2; i++ ) {
		B2_Shot[i].UseFlag = 0;

		for( j=0; j<3; j++ ) 
			for( int k=0; k<3; k++ ) 
				B2_Shot[i].B2_XY[j][k].UseFlag = 0;
	}
}

void Shot_Create( int _TYPE, int _X, int _Y )
{
	int i, j, k;

	if( _TYPE == 0 ) {
		for( i=0; i<MAX_SHOT_ENEMY1; i++ ) {
			if( E1_Shot[i].UseFlag ) continue;

			E1_Shot[i].Type = _TYPE;
			E1_Shot[i].UseFlag = 1;
			E1_Shot[i].x = _X;
			E1_Shot[i].y = _Y;

			return;
		}
	}
	else if( _TYPE == 1 ) {
		for( i=0; i<MAX_SHOT_ENEMY2; i++ ) {
			if( E2_Shot[i].UseFlag ) continue;

			E2_Shot[i].Type = _TYPE;
			E2_Shot[i].UseFlag = 1;
			E2_Shot[i].x = _X;
			E2_Shot[i].y = _Y;

			return;
		}
	}
	else if( _TYPE == 2 ) {
		for( i=0; i<MAX_SHOT_BOSS; i++ ) {
			for( j=0; j<LINE_SHOT_BOSS; j++ ) {
				if( B_Shot[j][i].UseFlag ) break;

				B_Shot[j][i].Type = _TYPE;
				B_Shot[j][i].UseFlag = 1;
				B_Shot[j][i].x = _X;
				B_Shot[j][i].y = _Y;

				if( j == LINE_SHOT_BOSS-1 ) return;
			}
		}
	}
	else if( _TYPE == 3) {
		if( Player.ShotState == 0 ) {
			for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
				if( SP_Shot[i].UseFlag ) continue;

				SP_Shot[i].Type = _TYPE;
				SP_Shot[i].UseFlag = 1;
				SP_Shot[i].x = _X;
				SP_Shot[i].y = _Y;
				
				return;
			}
		}
		else {
			for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
				for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
					if( MP_Shot[j][i].UseFlag ) break;

					MP_Shot[j][i].Type = _TYPE;
					MP_Shot[j][i].UseFlag = 1;
					MP_Shot[j][i].x = (_X-1) + j;
					MP_Shot[j][i].y = _Y;

					if( j == LINE_SHOT_PLAYER-1 ) return;
				}
			}
		}
	}
	else if( _TYPE = 4 ) {
		for( i=0; i<MAX_SHOT_BOSS2; i++ ) {
			if( B2_Shot[i].UseFlag ) continue;

			B2_Shot[i].UseFlag = 1;

			for( j=0; j<3; j++ ) 
				for( k=0; k<3; k++ ) {
					if( j==0 || j==2 || k==0 || k==2 ) {
						B2_Shot[i].B2_XY[j][k].x = _X;
						B2_Shot[i].B2_XY[j][k].y = _Y;
						B2_Shot[i].B2_XY[j][k].UseFlag = 1;
					}
				}
			return;
		}
	}
}
void Shot_P_Draw()
{
	int i, j;

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		if( !SP_Shot[i].UseFlag ) continue;
			
		Screen[ SP_Shot[i].y ][ SP_Shot[i].x ] = SP_Shot_Image;
	}
	
	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) break;

			Screen[ MP_Shot[j][i].y ][ MP_Shot[j][i].x ] = MP_Shot_Image;
		}
	}
}
void Shot_E1_Draw() 
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY1; i++ ) {
		if( !E1_Shot[i].UseFlag ) continue;

		Screen[ E1_Shot[i].y ][ E1_Shot[i].x ] = E1_Shot_Image;
	}
}
void Shot_E2_Draw()
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY2; i++ ) {
		if( !E2_Shot[i].UseFlag ) continue;

		Screen[ E2_Shot[i].y ][ E2_Shot[i].x ] = E2_Shot_Image;
	}
}
void Shot_B_Draw() 
{
	int i, j;

	for( i=0; i<MAX_SHOT_BOSS; i++ ) {
		for( j=0; j<LINE_SHOT_BOSS; j++ ) {
			if( !B_Shot[j][i].UseFlag ) continue;

			Screen[ B_Shot[j][i].y ][ B_Shot[j][i].x ] = B_Shot_Image;
		}
	}
}

void Shot_B2_Draw()
{
	int i, j, k;

	for( i=0; i<MAX_SHOT_BOSS2; i++ ) {
		if( !B2_Shot[i].UseFlag ) continue;

		for( j=0; j<3; j++ ) 
			for( k=0; k<3; k++ ) {
				if( !B2_Shot[i].B2_XY[j][k].UseFlag ) continue;
				Screen[ B2_Shot[i].B2_XY[j][k].y ][ B2_Shot[i].B2_XY[j][k].x ] = 'X';
			}
	}
}

void Shot_P_Action()
{
	int i, j;

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		if( !SP_Shot[i].UseFlag ) continue;

		SP_Shot[i].y--;

		if( SP_Shot[i].y < 0 ) SP_Shot[i].UseFlag = 0;
	}


	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) break;

			MP_Shot[j][i].y--;

			if( MP_Shot[j][i].y < 0 ) MP_Shot[j][i].UseFlag = 0;
		}
	}
}
void Shot_E1_Action()
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY1; i++ ) {
		if( !E1_Shot[i].UseFlag ) continue;

		E1_Shot[i].y++;

		if( E1_Shot[i].y > HEIGHT-1 ) E1_Shot[i].UseFlag = 0;
	}
}
void Shot_E2_Action()
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY2; i++ ) {
		if( !E2_Shot[i].UseFlag ) continue;

		E2_Shot[i].y++;

		if( E2_Shot[i].y > HEIGHT-1 ) E2_Shot[i].UseFlag = 0;
	}
}
void Shot_B_Action()
{
	int i, j;

	for( i=0; i<MAX_SHOT_BOSS; i++ ) {
		for( j=0; j<LINE_SHOT_BOSS; j++ ) {
			if( !B_Shot[j][i].UseFlag ) continue;
			if( j == 0 ) B_Shot[j][i].x-=2;
			else if( j == 1 ) B_Shot[j][i].x--;
			else if( j == 3 ) B_Shot[j][i].x++;
			else if( j == 4 ) B_Shot[j][i].x+=2;

			B_Shot[j][i].y++;

			if( B_Shot[j][i].y > HEIGHT-1 ||
			   (B_Shot[j][i].x < 0 || B_Shot[j][i].x > WIDTH-2) )
				B_Shot[j][i].UseFlag = 0;
		}
	}
}
void Shot_B2_Action()
{
	int i, j, k;
	int Num=0;

	for( i=0; i<MAX_SHOT_BOSS2; i++ ) {
		if( !B2_Shot[i].UseFlag ) continue;

		for( j=0; j<3; j++ )
			for( k=0; k<3; k++ ) {
				if( !B2_Shot[i].B2_XY[j][k].UseFlag ) continue;

				if( j==0 && k==0 ) { B2_Shot[i].B2_XY[j][k].x--; B2_Shot[i].B2_XY[j][k].y--; }
				else if( j==0 && k==2 ) { B2_Shot[i].B2_XY[j][k].x++; B2_Shot[i].B2_XY[j][k].y--; }
				else if( j==2 && k==0 ) { B2_Shot[i].B2_XY[j][k].x--; B2_Shot[i].B2_XY[j][k].y++; }
				else if( j==2 && k==2 ) { B2_Shot[i].B2_XY[j][k].x++; B2_Shot[i].B2_XY[j][k].y++; }
				else if( j== 0 ) { B2_Shot[i].B2_XY[j][k].y--; }
				else if( j== 2 ) { B2_Shot[i].B2_XY[j][k].y++; }
				else if( k== 0 ) { B2_Shot[i].B2_XY[j][k].x--; }
				else if( k== 2 ) { B2_Shot[i].B2_XY[j][k].x++; }

				if( B2_Shot[i].B2_XY[j][k].x < 0 || B2_Shot[i].B2_XY[j][k].x > WIDTH-2 ||
					B2_Shot[i].B2_XY[j][k].y < 0 || B2_Shot[i].B2_XY[j][k].y > HEIGHT-1 ) {
						B2_Shot[i].B2_XY[j][k].UseFlag = 0;
				}
			}
		for( j=0; j<3; j++ )
			for( k=0; k<3; k++ ) {
				if( B2_Shot[i].B2_XY[j][k].UseFlag ) break;
				Num++;
			}

		if( Num == 9 ) {
			B2_Shot[i].UseFlag = 0;
			Num = 0;
		}
		else { Num = 0; }
	}
}