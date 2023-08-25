#include<stdio.h>
int main() {
	int year;
	scanf_s("%d", &year);

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("À±³â");
	else
		printf("À±³â ¾Æ´Ô");



	return 0;
}