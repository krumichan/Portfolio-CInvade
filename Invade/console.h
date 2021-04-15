#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <windows.h>

#define WIDTH	101 // 콘솔창 가로길이 + 1(NULL) -> 문자열을 출력할때 NULL을 만날때까지 출력하기 때문에 NULL 추가
#define HEIGHT	30 // 콘솔창 세로길이 - 1 -> 커서가 26으로 내려가 화면이 흔들리는 현상을 막기 위함

extern char Screen[HEIGHT][WIDTH];

void Initial(); //API기반으로 만들어진 것(지금은 그냥 생각하기) - 초기화(커서를 안보이게 하는 역할), 처음 한번만 호출 하면 됨
void MoveCursor(int x, int y); //커서를 임의의 원하는 위치로 이동
void ClearScreen(); //화면을 깨끗이 지움 - 공백문자로 다 채워버림