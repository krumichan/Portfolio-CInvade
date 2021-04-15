#include "Boss2.h"
#include "Shot.h"

void Boss2_Initial()
{
	Boss2.x = WIDTH/2;
	Boss2.y = 5;
	Boss2.Max_HP = 80;
	Boss2.HP = 80;
	Boss2.LiveFlag = 1;

	B2_X = 0;
	B2_Y = 0;
	
	Count = 0;
}
void Boss2_Draw()
{
	if( !Boss2.LiveFlag ) return;

	int i, j;
	int x = Boss2.x;
	int y = Boss2.y;

	for( i=0; i<3; i++ ) {
		for( j=0; j<5; j++ ) {
			Screen[ y+i ][ x+j ] = Boss2Unit[i][j];

		}
	}
}
void Boss2_Action()
{
	if( !Boss2.LiveFlag ) return;
	
	int Ren = rand()%8;

	Boss2.x+=B2_X; 
	Boss2.y+=B2_Y;
	Count++;

	if( Count == 3 ) {
		if( Ren == 0 ) { B2_X=1; B2_Y=1; }
		else if( Ren == 1 ) { B2_X=-1; B2_Y=1; }
		else if( Ren == 2 ) { B2_X=1; B2_Y=-1; }
		else if( Ren == 3 ) { B2_X=-1; B2_Y=-1; }
		else if( Ren == 4 ) { B2_X=0; B2_Y=1; }
		else if( Ren == 5 ) { B2_X=2; B2_Y=0; }
		else if( Ren == 6 ) { B2_X=-2; B2_Y=0; }
		else if( Ren == 7 ) { B2_X=0; B2_Y=-1; }
		Count = 0;
	}

	if( Boss2.x >= (WIDTH-2)-5 )
		B2_X = -B2_X;
	if( Boss2.x < 2 )
		B2_X = -B2_X;
	if( Boss2.y >= HEIGHT/2-2 )
		B2_Y = -B2_Y;
	if( Boss2.y < 2 )
		B2_Y = -B2_Y;

	if( rand()%10 < 2 ) Shot_Create( BOSS2_SHOT, Boss2.x+2, Boss2.y+1 );
}