#include<stdio.h>
int main() {

	int a, b, c;
	int max;
	scanf_s("%d %d %d", &a, &b, &c);
	/*if (a >= b) {
		max = a;
	}
	else max = b;

	if (max >= c) {
		max = max;
	}
	else max = c;*/
	max = (a > b) ? a : b;
	max =(max > c) ? max : c;

	printf("%d", max);
	return 0;
}