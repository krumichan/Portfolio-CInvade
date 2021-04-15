#include "Special_Function.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Item.h"
#include "Wall.h"
#include "Shot.h"
#include "Collision.h"

void DrawLife()
{
	MoveCursor( 0, HEIGHT );
	printf("HP : ");

	int i;

	for( i=0; i<Player.Max_HP; i++ )
		printf("¢½");
	MoveCursor( 5, HEIGHT );
	for( i=0; i<Player.HP; i++ )
		printf("¢¾");

	MoveCursor( WIDTH/2, HEIGHT );
	printf("Score : %d", Player.Score );
}

int Check_End_Game()
{
	if( Player.LiveFlag == 0 ) {
		ClearScreen();
		MoveCursor( WIDTH/2-2, HEIGHT/2 );
		printf("Á×À½");
		Sleep(3000);
		return 1;
	}

	if( Check_Clear() ) {
		Stage_Count++;

		Player_Stage_Initial();
		Shot_Initial();
		Item_Initial();

		if( Stage_Count > MAX_STAGE ) {
			ClearScreen();
			MoveCursor( WIDTH/2-2, HEIGHT/2 );
			printf("²¢À½");
			Sleep(3000);
			return 1;
		}
		else {
			ClearScreen();
			MoveCursor( WIDTH/2-7, HEIGHT/2 );
			printf("Stage Clear!!");
			Sleep(2000);
			return 0;
		}

		return 0;
	}

	return 0;
}
int Check_Clear()
{
	int i;

	if( Stage_Count == 0 ) {
		for( i=0; i<MAX_ENEMY1_COUNT; i++ )
			if( Enemy1[i].LiveFlag ) return 0;
	}
	else if( Stage_Count == 1 ) {
		for( i=0; i<MAX_ENEMY2_COUNT; i++ )
			if( Enemy2[i].LiveFlag ) return 0;
	}
	else if( Stage_Count == 2 ) {
		if( Boss1.LiveFlag ) return 0;
	}
	else if( Stage_Count == 3 ) {
		if( Boss2.LiveFlag ) return 0;
	}

	return 1;
}

void Draw()
{
	int i;

	for( i=0; i<HEIGHT; i++ ) {
		memset(Screen[i],' ', WIDTH);
		Screen[i][WIDTH-1] = NULL;
	}

	Player_Draw();
	Shot_P_Draw();
	Item_Draw();

	if( Stage_Count == 0 ) {

		if( Stage_Flag[0] == 1 ) {
			Stage_Flag[0] = 0;
			ClearScreen();
			MoveCursor(WIDTH/2-2, HEIGHT/2);
			printf("Stage1");
			Sleep(1000);
		}

		Enemy1_Draw();
		Shot_E1_Draw();
	}
	else if( Stage_Count == 1 ) {

		if( Stage_Flag[1] == 1 ) {
			Stage_Flag[1] = 0;
			ClearScreen();
			MoveCursor(WIDTH/2-2, HEIGHT/2);
			printf("Stage2");
			Sleep(1000);
		}

		Enemy2_Draw();
		Shot_E2_Draw();
	}
	else if( Stage_Count == 2 ) {
		if( Stage_Flag[2] == 1 ) {
			Stage_Flag[2] = 0;
			ClearScreen();
			MoveCursor(WIDTH/2-2, HEIGHT/2);
			printf("Stage3");
			Sleep(1000);
		}
		
		Wall_Draw();
		Boss1_Draw();
		Shot_B_Draw();
	}
	else if( Stage_Count == 3 ) {
		if( Stage_Flag[3] == 1 ) {
			Stage_Flag[3] = 0;
			ClearScreen();
			MoveCursor(WIDTH/2-2, HEIGHT/2);
			printf("Stage4");
			Sleep(1000);
		}

		Boss2_Draw();
		Shot_B2_Draw();
	}

	for(i=0;i < HEIGHT;i++){
		MoveCursor(0, i);
		printf(Screen[i]);
	}
	
	DrawLife();
}

void Action() 
{
	Player_Action();
	Shot_P_Action();
	Item_Action();
	ItemCollision();

	if( Stage_Count == 0 ) {
		Enemy1_Action();
		Shot_E1_Action();

		P_E1_Collision();
		E1_P_Collision();
	}
	else if( Stage_Count == 1 ) {
		Enemy2_Action();
		Shot_E2_Action();

		P_E2_Collision();
		E2_P_Collision();
	}
	else if( Stage_Count == 2 ) {
		Boss1_Action();
		Wall_Action();

		WallCollision();
		P_B_Collision();

		Shot_B_Action();
		B_P_Collision();
	}
	else if( Stage_Count == 3 ) {
		Boss2_Action();
		Shot_B2_Action();

		P_B2_Collision();
		B2_P_Collision();
	}
}
void Object_Initial()
{
	int i;

	for( i=0; i<MAX_STAGE; i++ ) {
		Stage_Flag[i] = 1;
	}

	Shot_Initial();
	Item_Initial();
	Wall_Initial();

	Player_Initial();
	Enemy1_Initial();
	Enemy2_Initial();
	Boss1_Initial();
	Boss2_Initial();

}