#pragma warning(disable:4996)

#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define STAR "��"
#define INTERVAL 300
#define MIN 5
#define MAX 12

void gotoxy(int x, int y);
void draw_rectangle(int, int, int, int);

int main() {

	int input;
	int repeats;
	int start_x = 10;
	int start_y = 3;
	int width = 50;
	int height = 10;
	int x, y, i;

	printf("���� ��¦�̴� Ƚ���� ���ߴ� �����Դϴ�. �ƹ�Ű�� ������ �����մϴ�.\n");
	getch();

	system("cls");
	Sleep(1000);

	srand(time(NULL));
	repeats = rand() % (MAX - MIN + 1) + MIN;

	draw_rectangle(start_x, start_y, width, height);
	Sleep(1000);

	for (i = 1; i <= repeats; i++) {
		x = start_x + rand() % (width - 2);
		y = start_y + rand() % (height - 1);

		gotoxy(x, y);
		printf("%s", STAR);
		Sleep(INTERVAL);

		gotoxy(x, y);
		printf("%s", "");
		Sleep(INTERVAL);
	}
	gotoxy(10, 21);
	printf("���� ���(%d~%d��) ��¦�ŷ������? >>", MIN, MAX);
	scanf("%d", &input);

	gotoxy(10, 22);
	if (input == repeats) printf("�¾ҽ��ϴ�!\n");
	else
		printf("Ʋ�Ƚ��ϴ�. ���� %d�� �Դϴ�!\n", repeats);

	return 0;
}

void draw_rectangle(int start_x, int start_y, int width, int height)
{
	int col, row;

	gotoxy(start_x - 1, start_y - 1);
	for (col = 0; col <= width + 1; col++)
		putch('=');

	gotoxy(start_x - 1, start_y + height);
	for (col = 0; col <= width + 1; col++)
		putch('=');

	for (row = 0; row < height; row++) {
		gotoxy(start_x - 1, start_y + row);
		putch('��');
	}

	for (row = 0; row < height; row++) {
		gotoxy(start_x + width, start_y + row);
		putch('��');
	}
}
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);

}
