#include<stdio.h>
int main() {
	char a;
	scanf_s("%c", &a);
	if ((a >= 'a') && (a <= 'z'))
		printf("�ҹ���");
	else if ((a >= 'A') && (a <= 'Z'))
		printf("�빮��");
	else if ((a > '0') && (a < '10'))
		printf("���ڸ�����");
	else
		printf("�� ���� ����");

	return 0;
}