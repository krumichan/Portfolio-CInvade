#include "console.h"

HANDLE hConsole;

void Initial()
{
	CONSOLE_CURSOR_INFO Cursor;

	Cursor.bVisible = FALSE; // Ŀ�� �Ⱥ��̰�
	Cursor.dwSize	= 1; // Ŀ�� �۰�

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hConsole, &Cursor); // Ŀ���� ������ ���� �־�� (Set <-> Get)
}

void MoveCursor(int x, int y)
{
	COORD Coord; // ��ǥ���� �����ϴ� ����ü
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