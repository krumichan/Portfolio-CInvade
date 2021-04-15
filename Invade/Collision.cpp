#include "Collision.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Item.h"
#include "Wall.h"
#include "Shot.h"

void WallCollision()
{
	int i;

	for( i=0; i<HEIGHT; i++ ) {
		if( Player.y != i ) continue;

		if( Player.x-PLAYER_SIZE/2 <= Wall[i].LeftX ) {
			
			Player.x = Wall[i].LeftX+1+PLAYER_SIZE/2;

			if( Player.HP > 1 )
				Player.HP--;

			return;
		}
		else if( Player.x+PLAYER_SIZE/2 >= Wall[i].RightX ) {

			Player.x = Wall[i].RightX-1-PLAYER_SIZE/2;

			if( Player.HP > 1 )
				Player.HP--;

			return;
		}
	}
}
void ItemCollision()
{
	int i;

	for( i=0; i<MAX_ITEM_COUNT; i++ ) {
		if( !Item[i].LiveFlag ) continue;

		if( Item[i].y == Player.y &&
			Item[i].x >= Player.x-PLAYER_SIZE/2 &&
			Item[i].x <= Player.x+PLAYER_SIZE/2 ) {

			if( Item[i].Type == HP_Item ) {
				if( Player.HP < 6 ) {
					Player.HP++;
					Item[i].LiveFlag = 0;
				}
				else { 
					Player.Score += 50;
					Item[i].LiveFlag = 0;
				}
			}
			else if( Item[i].Type == GUN_Item ) {
				if( Player.ShotState == 0 ) {
					Player.ShotState = 1;
					Item[i].LiveFlag = 0;
				}
				else {
					Player.Score += 50;
					Item[i].LiveFlag = 0;
				}
			}
			else if( Item[i].Type == ZERO_Item ) {
				Zero_Shot();
				Item[i].LiveFlag = 0;
			}
		}
	}
}

void P_E1_Collision()
{
	int i, j, k;


	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		if( !SP_Shot[i].UseFlag ) continue;

		for( j=0; j<MAX_ENEMY1_COUNT; j++ ) {
			if( !Enemy1[j].LiveFlag ) continue;

			if( SP_Shot[i].y == Enemy1[j].y &&
				SP_Shot[i].x >= Enemy1[j].x-ENEMY1_SIZE/2 &&
				SP_Shot[i].x <= Enemy1[j].x+ENEMY1_SIZE/2 ) {
				Enemy1[j].LiveFlag = 0;
				SP_Shot[i].UseFlag = 0;
				Player.Score+=100;

				if( rand()%20 <= 1 ) Item_Create( Enemy1[j].x, Enemy1[j].y );
				break;
			}
		}
	}


	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) continue;

			for( k=0; k<MAX_ENEMY1_COUNT; k++ ) {
				if( !Enemy1[k].LiveFlag ) continue;

				if( MP_Shot[j][i].y == Enemy1[k].y &&
					MP_Shot[j][i].x >= Enemy1[k].x-ENEMY1_SIZE/2 &&
					MP_Shot[j][i].x <= Enemy1[k].x+ENEMY1_SIZE/2 ) {
					Enemy1[k].LiveFlag = 0;
					MP_Shot[j][i].UseFlag = 0;
					Player.Score+=100;

					if( rand()%20 <= 1 ) Item_Create( Enemy1[k].x, Enemy1[k].y );
					break;
				}
			}
		}
	}
}
void P_E2_Collision()
{
	int i, j, k;


	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		if( !SP_Shot[i].UseFlag ) continue;

		for( j=0; j<MAX_ENEMY2_COUNT; j++ ) {
			if( !Enemy2[j].LiveFlag ) continue;

			if( SP_Shot[i].y == Enemy2[j].y &&
				SP_Shot[i].x >= Enemy2[j].x-ENEMY2_SIZE/2 &&
				SP_Shot[i].x <= Enemy2[j].x+ENEMY2_SIZE/2 ) {
				Enemy2[j].LiveFlag = 0;
				SP_Shot[i].UseFlag = 0;
				Player.Score+=100;

				if( rand()%20 <= 1 ) Item_Create( Enemy2[j].x, Enemy2[j].y );
				break;
			}
		}
	}


	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) continue;

			for( k=0; k<MAX_ENEMY1_COUNT; k++ ) {
				if( !Enemy2[k].LiveFlag ) continue;

				if( MP_Shot[j][i].y == Enemy2[k].y &&
					MP_Shot[j][i].x >= Enemy2[k].x-ENEMY2_SIZE/2 &&
					MP_Shot[j][i].x <= Enemy2[k].x+ENEMY2_SIZE/2 ) {
					Enemy2[k].LiveFlag = 0;
					MP_Shot[j][i].UseFlag = 0;
					Player.Score+=100;

					if( rand()%20 <= 1 ) Item_Create( Enemy2[k].x, Enemy2[k].y );
					break;
				}
			}
		}
	}
}
void P_B_Collision()
{
	int i, j;

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
			
		if( !SP_Shot[i].UseFlag ) continue;
			
		if( Boss1.y == 0 ) {
			if( SP_Shot[i].x == Boss1.x ) {
				SP_Shot[i].UseFlag = 0;
				Boss1.HP--;
				Player.Score+=10;

				if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

				if( rand()%20 < 1 ) Item_Create( rand()%15+40, 1 );
				continue;
			}
		}
		else if( Boss1.y == 1 ) {
			if(( SP_Shot[i].y == 0 &&
			    (SP_Shot[i].x == Boss1.x-1 || SP_Shot[i].x == Boss1.x+1) ) ||
			   ( SP_Shot[i].y == 1 &&
			    (SP_Shot[i].x == Boss1.x ) ) ) {
					SP_Shot[i].UseFlag = 0;
					Boss1.HP--;
					Player.Score+=10;

					if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

					if( rand()%20 < 1 ) Item_Create( rand()%15+40, 1 );
					continue;

			}
		}
		else if( Boss1.y == 2 ){
			if(( SP_Shot[i].y == 0 &&
				(SP_Shot[i].x == Boss1.x-2 || SP_Shot[i].x == Boss1.x+2) ) ||
			   ( SP_Shot[i].y == 1 &&
			    (SP_Shot[i].x == Boss1.x-1 || SP_Shot[i].x == Boss1.x+1) ) ||
			   ( SP_Shot[i].y == 2 &&
			    (SP_Shot[i].x == Boss1.x) ) ) {
				 SP_Shot[i].UseFlag = 0;
				 Boss1.HP--;
				 Player.Score+=10;

				 if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

				 if( rand()%20 < 1 ) Item_Create( rand()%15+40, 1 );
				 continue;
			}
		}
	}

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) continue;

			if( Boss1.y == 0 ) {
				if( MP_Shot[j][i].x == Boss1.x ) {
					MP_Shot[j][i].UseFlag = 0;
					Boss1.HP--;
					Player.Score += 10;

					if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

					if( rand()%20 < 2 ) Item_Create( rand()%15+40, 1 );
					break;
				}
			}
			else if( Boss1.y == 1 )  {
				if( ( MP_Shot[j][i].y == 0 &&
						(MP_Shot[j][i].x == Boss1.x-1 || MP_Shot[j][i].x == Boss1.x+1) ) ||
					( MP_Shot[i][j].y == 1 &&
						(MP_Shot[j][i].x == Boss1.x) ) ) {
							MP_Shot[j][i].UseFlag = 0;
							Boss1.HP--;
							Player.Score+=10;

							if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

							if( rand()%20 < 2 ) Item_Create( rand()%15+40, 1 );
							continue;
				}
			}
			else if( Boss1.y == 2 ) {
				if( ( MP_Shot[j][i].y == 2 &&
						(MP_Shot[j][i].x == Boss1.x-2 || MP_Shot[j][i].x == Boss1.x+2 ) ) ||
					( MP_Shot[j][i].y == 1 &&
						(MP_Shot[j][i].x == Boss1.x-1 || MP_Shot[j][i].x == Boss1.x+1 ) ) ||
					( MP_Shot[j][i].y == 0 &&
						(MP_Shot[j][i].x == Boss1.x) ) ) {
						MP_Shot[j][i].UseFlag = 0;
						Boss1.HP--;
						Player.Score+=10;

						if( Boss1.HP == 0 ) Boss1.LiveFlag = 0;

						if( rand()%20 < 2 ) Item_Create( rand()%15+40, 1 );
				}
			}
		}
	}
}

void P_B2_Collision()
{
	int i, j;

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		if( !SP_Shot[i].UseFlag ) continue;

		if( ( SP_Shot[i].y == Boss2.y+2 &&
			 (SP_Shot[i].x == Boss2.x+1 || SP_Shot[i].x == Boss2.x+2 || SP_Shot[i].x == Boss2.x+3 ) ) ||
			( SP_Shot[i].y == Boss2.y+1 &&
			 (SP_Shot[i].x == Boss2.x || SP_Shot[i].x == Boss2.x+4) ) ) {
			SP_Shot[i].UseFlag = 0;
			Boss2.HP--;
			Player.Score+=100;

			if( Boss2.HP == 0 ) Boss2.LiveFlag = 0;

			if( rand()%20 < 2 ) Item_Create ( rand()%15+40, 5 );
		}
	}

	for( i=0; i<MAX_SHOT_PLAYER; i++ ) {
		for( j=0; j<LINE_SHOT_PLAYER; j++ ) {
			if( !MP_Shot[j][i].UseFlag ) continue;

			if( ( MP_Shot[j][i].y == Boss2.y+2 &&
				 (MP_Shot[j][i].x == Boss2.x+1 || MP_Shot[j][i].x == Boss2.x+2 || MP_Shot[j][i].x == Boss2.x+3 ) ) ||
				( MP_Shot[j][i].y == Boss2.y+1 &&
				 (MP_Shot[j][i].x == Boss2.x || MP_Shot[j][i].x == Boss2.x+4) ) ) {
				MP_Shot[j][i].UseFlag = 0;
				Boss2.HP--;
				Player.Score+=100;

				if( Boss2.HP == 0 ) Boss2.LiveFlag = 0;

				if( rand()%20 < 2 ) Item_Create ( rand()%15+40, 5 );
			}
		}
	}
}

void E1_P_Collision()
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY1; i++ ) {
		if( !E1_Shot[i].UseFlag ) continue;

		if( E1_Shot[i].y == Player.y &&
			E1_Shot[i].x >= Player.x-PLAYER_SIZE/2 &&
			E1_Shot[i].x <= Player.x+PLAYER_SIZE/2 ) {
			E1_Shot[i].UseFlag = 0;
			Player.HP--;
			Player.ShotState = 0;
			
			if( Player.HP == 0 ) Player.LiveFlag = 0;

			continue;
		}
	}
}

void E2_P_Collision()
{
	int i;

	for( i=0; i<MAX_SHOT_ENEMY2; i++ ) {
		if( !Enemy2[i].LiveFlag ) continue;

		if( Enemy2[i].y == Player.y &&
			Enemy2[i].x >= Player.x-PLAYER_SIZE/2 &&
			Enemy2[i].x <= Player.x+PLAYER_SIZE/2 ) {
			Enemy2[i].LiveFlag = 0;
			Player.HP--;
			Player.ShotState = 0;
			
			if( Player.HP == 0 ) Player.LiveFlag = 0;

			return;
		}
	}
}
void B_P_Collision()
{
	int i, j;

	for( i=0; i<MAX_SHOT_BOSS; i++ ) {
		for( j=0; j<LINE_SHOT_BOSS; j++ ) {
			if( B_Shot[j][i].y == Player.y &&
				B_Shot[j][i].x >= Player.x-PLAYER_SIZE/2 &&
				B_Shot[j][i].x <= Player.x+PLAYER_SIZE/2 ) {
					Player.HP--;
					Player.ShotState = 0;
					
					if( Player.HP == 0 ) Player.LiveFlag = 0;
					continue;
			}
		}
	}
}
void B2_P_Collision()
{
	int i, j, k;

	for( i=0; i<MAX_SHOT_BOSS2; i++ ) {
		if( !B2_Shot[i].UseFlag ) continue;

		for( j=0; j<3; j++ ) {
			for( k=0; k<3; k++ ) {
				if( !B2_Shot[i].B2_XY[j][k].UseFlag ) continue;

				if( B2_Shot[i].B2_XY[j][k].y == Player.y &&
					B2_Shot[i].B2_XY[j][k].x >= Player.x-PLAYER_SIZE/2 &&
					B2_Shot[i].B2_XY[j][k].x <= Player.x+PLAYER_SIZE/2 ) {
					B2_Shot[i].B2_XY[j][k].UseFlag = 0;
					Player.HP--;
					Player.ShotState = 0;

					if( Player.HP == 0 ) Player.LiveFlag = 0;
					continue;
				}
			}
		}
	}
}