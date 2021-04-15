#include "console.h"

HANDLE hConsole;

void Initial()
{
	CONSOLE_CURSOR_INFO Cursor;

	Cursor.bVisible = FALSE; // 커서 안보이게
	Cursor.dwSize	= 1; // 커서 작게

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &Cursor); // 커서의 정보를 집어 넣어라 (Set <-> Get)
}

void MoveCursor(int x, int y)
{
	COORD Coord; // 좌표점을 제공하는 구조체
	Coord.X = x;
	Coord.Y = y;

	SetConsoleCursorPosition(hConsole, Coord);
}

void ClearScreen()
{
	int x, y;

	for(y=0;y < HEIGHT;y++) {
		MoveCursor(0, y);
		for(x=0;x < WIDTH; x++) {
			printf("%c", ' ');
		}
	}
}