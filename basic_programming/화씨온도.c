#include<stdio.h>
int main() {
	//ȭ���µ� �Է�-> ȭ���µ��� �����µ��� ~.
	double f, c;

	scanf_s("%lf", &f);

	c = (f - 32) * 5 / 9;

	printf("%.1lf", c);



	return 0;
}