#include "Wall.h"



void Wall_Initial()
{
	int i;

	for( i=0; i<HEIGHT; i++ ) {
		if( i<HEIGHT/2 )
			Wall[i].LeftX = WIDTH/6 + 2*i;
		else
			Wall[i].LeftX = WIDTH/6 + 2*(HEIGHT-i);

		Wall[i].RightX = Wall[i].LeftX + WIDTH/2;
		Wall[i].Wall_Image = '+';
		Wall[i].MoveFlag = 1;
	}
}
void Wall_Draw()
{
	int i;
	int L_X, L_Y;

	for( i=0; i<HEIGHT; i++ ) {
		L_X = Wall[i].LeftX;
		L_Y = Wall[i].RightX;

		if( L_X >= 0 && L_Y <= WIDTH-2 ) {
			Screen[i][L_X] = Wall[i].Wall_Image;
			Screen[i][L_Y] = Wall[i].Wall_Image;
		}
	}
}
void Wall_Action()
{
	int i;

	for( i=0; i<HEIGHT; i++ ) {
		if( Wall[i].LeftX<=0 || Wall[i].RightX >= WIDTH-2 )
			Wall[i].MoveFlag = !Wall[i].MoveFlag;

		if( Wall[i].MoveFlag ) {
			Wall[i].LeftX+=2;
			Wall[i].RightX+=2;
		}
		else {
			Wall[i].LeftX-=2;
			Wall[i].RightX-=2;
		}
	}
}