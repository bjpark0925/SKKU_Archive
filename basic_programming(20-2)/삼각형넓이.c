#include<stdio.h>
int main() {
	int a, b;
	double c;

	scanf_s("%d %d", &a, &b);

	c = (a * b) / 2.0;

	printf("%.1lf\n", c);



	return 0;
}