#include <stdio.h>
#pragma warning(disable:4996)
int sum(int, int);

int main() {
	int a, b, gkq;

	scanf("%d %d", &a, &b);

	gkq = sum(a, b);

	printf("%d", gkq);

	return 0;
}
int sum(int x, int y) {

	int gkq;

	gkq = (y * (y + 1)) / 2 - (x * (x + 1)) / 2 + x;

	return gkq;
}