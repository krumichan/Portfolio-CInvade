#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <windows.h>

#define WIDTH	101 // �ܼ�â ���α��� + 1(NULL) -> ���ڿ��� ����Ҷ� NULL�� ���������� ����ϱ� ������ NULL �߰�
#define HEIGHT	30 // �ܼ�â ���α��� - 1 -> Ŀ���� 26���� ������ ȭ���� ��鸮�� ������ ���� ����

extern char Screen[HEIGHT][WIDTH];

void Initial(); //API������� ������� ��(������ �׳� �����ϱ�) - �ʱ�ȭ(Ŀ���� �Ⱥ��̰� �ϴ� ����), ó�� �ѹ��� ȣ�� �ϸ� ��
void MoveCursor(int x, int y); //Ŀ���� ������ ���ϴ� ��ġ�� �̵�
void ClearScreen(); //ȭ���� ������ ���� - ���鹮�ڷ� �� ä������