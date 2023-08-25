#include<stdio.h>
int main() {
	//È­¾¾¿Âµµ ÀÔ·Â-> È­¾¾¿ÂµµÀÇ ¼·¾¾¿Âµµ´Â ~.
	double f, c;

	scanf_s("%lf", &f);

	c = (f - 32) * 5 / 9;

	printf("%.1lf", c);



	return 0;
}