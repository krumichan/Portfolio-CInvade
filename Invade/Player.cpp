#include "Player.h"
#include "Shot.h"

void Player_Initial()
{
	Player.x = WIDTH/2 - PLAYER_SIZE/2;
	Player.y = HEIGHT-3;
	Player.LiveFlag = 1;
	Player.Max_HP = 6;
	Player.HP = 6;
	Player.Score = 0;
	Player.ShotState = 0; // 0 Single, 1 Multi
}

void Player_Stage_Initial()
{
	Player.x = WIDTH/2 - PLAYER_SIZE/2;
	Player.y = HEIGHT-3;

	int i, j;

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		SP_Shot[i].UseFlag = 0;
		
		for( j=0; j<LINE_SHOT_PLAYER; j++ )
			MP_Shot[j][i].UseFlag = 0;
	}
}

void Player_Draw() 
{
	int i;
	int x = Player.x - PLAYER_SIZE/2;
	int y = Player.y;

	if( y<0 || y>=HEIGHT ) return;

	for( i=0; i<PLAYER_SIZE; i++ ) {
		if( x>= 0 && x< WIDTH ) Screen[y][x] = PlayerUnit[i];
		x++;
	}
}

void Player_Action()
{
	if( GetAsyncKeyState(VK_UP) ) {
		Player.y--;
		if( Player.y< 0 ) Player.y = 0;
	}
	if( GetAsyncKeyState(VK_DOWN) ) {
		Player.y++;
		if( Player.y>= HEIGHT ) Player.y = HEIGHT-1;
	}
	if( GetAsyncKeyState(VK_LEFT) ) {
		Player.x-= 2;
		if( Player.x < PLAYER_SIZE / 2 ) Player.x = PLAYER_SIZE / 2;
	}
	if( GetAsyncKeyState(VK_RIGHT) ) {
		Player.x+= 2;
		if( Player.x>= WIDTH-2 - PLAYER_SIZE/2 ) Player.x = WIDTH-2 - PLAYER_SIZE/2;
	}
	if( GetAsyncKeyState(VK_CONTROL) ) Shot_Create( PLAYER_SHOT, Player.x, Player.y );
}