#include <stdio.h>
#pragma warning(disable:4996)

int main() {

	char ch = 'A';
	int x = 10, y = 4, sum;
	double pi = 3.14, avg;

	sum = ch + 2;
	printf("sum = %d=%c\n", sum, sum);

	sum = pi;
	printf("sum = %d\n", sum);

	printf("정수 간 x/y=%d\n", x / y);
	printf("실수 간 x/y = %lf\n", (double)x / (double)y);

	return 0;

}