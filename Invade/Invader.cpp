#include "console.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Boss1.h"
#include "Boss2.h"
#include "Item.h"
#include "Wall.h"
#include "Shot.h"
#include "Collision.h"
#include "Special_Function.h"

char Screen[HEIGHT][WIDTH];
int Stage_Count = 0;
int Stage_Flag[MAX_STAGE+1] = { 1, 1, 1, 1 };

// 플레이어 비행기 관련 
char PlayerUnit[PLAYER_SIZE+1] = "$=^=$";
PLAYER Player;

// 적 비행기 관련 
ENEMY1 Enemy1[MAX_ENEMY1_COUNT];
char Enemy1Unit[ENEMY1_SIZE+1] = "@-@";

ENEMY2 Enemy2[MAX_ENEMY2_COUNT];
int X[MAX_ENEMY2_COUNT], Y[MAX_ENEMY2_COUNT];
char Enemy2Unit[ENEMY2_SIZE+1] = "$-$";

BOSS1 Boss1;
char Boss1Unit[3][5] = { {' ', ' ', '@', ' ', ' '},
						 {' ', '@', '@', '@', ' '},
						 {'@', '@', '@', '@', '@'} };

BOSS2 Boss2;
char Boss2Unit[3][5] = { { ' ', 'O', 'O', 'O', ' ' },
						 { 'O', ' ', 'O', ' ', 'O' },
						 { ' ', 'O', 'O', 'O', ' ' } };
int Count;
int B2_X, B2_Y;


// 총알 관련
SHOT E1_Shot[MAX_SHOT_ENEMY1];
char E1_Shot_Image = '*';

SHOT E2_Shot[MAX_SHOT_ENEMY2];
char E2_Shot_Image = '*';

SHOT B_Shot[LINE_SHOT_BOSS][MAX_SHOT_BOSS];
char B_Shot_Image = 'V';

BOSS2SHOT B2_Shot[MAX_SHOT_BOSS2];

SHOT SP_Shot[MAX_SHOT_PLAYER];
SHOT MP_Shot[LINE_SHOT_PLAYER][MAX_SHOT_PLAYER];
char SP_Shot_Image = '|';
char MP_Shot_Image = '^';

//벽 관련
WALL Wall[HEIGHT];

//아이템 관련
ITEM Item[MAX_ITEM_COUNT];
char H_Item_Image = 'H';
char G_Item_Image = 'G';
char Z_Item_Image = 'Z';

void main()
{
	Initial();
	Object_Initial();
	srand((unsigned int)time(NULL));

	while(1) {

		Action();
		Draw();

		if( Check_End_Game() ) break;

		Sleep(50);
	}
}