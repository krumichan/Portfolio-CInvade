#include "Boss1.h"
#include "Shot.h"

void Boss1_Initial()
{
	Boss1.x = rand()%60 + 15;
	Boss1.y = -1;
	Boss1.LiveFlag = 1;
	Boss1.Time = 0;
	Boss1.Max_HP = 50;
	Boss1.HP = 50;
}
void Boss1_Draw()
{
	if( !Boss1.LiveFlag ) return;

	int i, j;
	int x;

	for( i=2; i>= 2-Boss1.y; i-- ) {
		x = Boss1.x - 2;

		for( j=0; j<5; j++ ) {
			Screen[2-i][x] = Boss1Unit[i][j];
			x++;
		}
	}
}
void Boss1_Action()
{
	if( !Boss1.LiveFlag ) return;

	if( Boss1.Time == 0 )
		Boss1.y++;

	if( Boss1.y != 0 && Boss1.Time == 30 )
		Boss1.y--;
	else if( Boss1.y == 0 && Boss1.Time == 30 ) {
		Boss1.Time = 0;
		Boss1.x = rand()%30 + 30;
	}
	
	if( Boss1.y == 2 ) {
		Boss1.Time++;
		if( rand()%5 < 2 ) Shot_Create( BOSS1_SHOT, Boss1.x, Boss1.y );
	}
}