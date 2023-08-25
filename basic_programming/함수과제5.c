#pragma warning(disable:4996)
#include <stdio.h>

void die1(int);
void die2(int, int);
void die3(int, int, int);

int N;
int x, y, z;

int main() {

	scanf("%d", &N);

	die1(x);

	return 0;
}
void die1(int x)
{
	for (x = 1; x <= 6; x++) {
		die2(x, y);
	}
}

void die2(int x, int y)
{
	for (y = 1; y <= 6; y++) {
		die3(x, y, z);
	}
}

void die3(int x, int y, int z)
{
	for (z = 1; z <= 6; z++) {
		if (N == x + y + z)
			printf("%d %d %d\n", x, y, z);
	}
}
