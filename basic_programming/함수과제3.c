#pragma warning(disable:4996)
#include <stdio.h>

int func1(int);

int main() {

	int x, f;

	scanf("%d", &x);

	f = func1(x);

	printf("%d", f);

	return 0;
}

int func1(int x)
{
	int f;
	f = 2 * x * x - 5 * x + 1;
	return f;
}