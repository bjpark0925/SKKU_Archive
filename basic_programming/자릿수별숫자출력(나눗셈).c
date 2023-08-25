#include<stdio.h>
int main() {
	int num, a, b, c, d, mod;

	printf("네자리 정수를 입력하세요.>>");
	scanf_s("%d", &num);
	printf("\n");

	a = num / 1000;
	mod = num % 1000;

	b = mod / 100;
	mod = mod % 100;

	c = mod / 10;
	d = mod % 10;

	printf("입력한 수는 %d천%d백%d십%d 입니다.\n", a, b, c, d);
	
	return 0;
}