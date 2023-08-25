#pragma warning(disable:4996)
#include <stdio.h>

int func1(int, int, int, int);
int func2(int, int, int, int);

int main() {

	int x;
	int a, b, c;
	int d, e, f;
	int F, G;

	scanf("%d", &x);

	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &d, &e, &f);

	F = func1(x, a, b, c);

	G = func2(F, d, e, f);

	printf("%d", G);

	return 0;
}

int func1(int x, int a, int b, int c)
{
	int F;

	F = a * x * x + b * x + c;

	return F;

}

int func2(int F, int d, int e, int f)
{
	int G;

	G = d * F * F + e * F + f;

	return G;
}