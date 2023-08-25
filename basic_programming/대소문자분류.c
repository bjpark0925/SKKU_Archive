#include<stdio.h>
int main() {
	char a;
	scanf_s("%c", &a);
	if ((a >= 'a') && (a <= 'z'))
		printf("소문자");
	else if ((a >= 'A') && (a <= 'Z'))
		printf("대문자");
	else if ((a > '0') && (a < '10'))
		printf("한자리숫자");
	else
		printf("그 외의 문자");

	return 0;
}