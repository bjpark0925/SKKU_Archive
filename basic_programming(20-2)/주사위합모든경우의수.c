#pragma warning(disable:4996)
#include <stdio.h>

/*
int N;
int x, y, z;

void die3(int x, int y, int z)
{
	for (z = 1; z <= 6; z++) {
		if (N == x + y + z)
			printf("%d %d %d\n", x, y, z);
	}
}

void die2(int x, int y)
{
	for (y = 1; y <= 6; y++) {
		die3(x, y, z);
	}
}

void die1(int x)
{
	for (x = 1; x <= 6; x++) {
		die2(x, y);
	}
}

int main() {

	scanf("%d", &N);

	die1(x);

	return 0;
}
*/

//함수 안쓰고 할 경우
int main() {
	int n;

	scanf("%d", &n);
	int sum = 0;

	for (int a = 1; a <= 6; a++) {
		for (int b = 1; b <= 6; b++) {
			for (int c = 1; c <= 6; c++) {
				if (a + b + c == n) {
					printf("%d %d %d\n", a, b, c);
					sum++;
				}
			}
		}
	}
	printf("모든 경우의 수: %d", sum);

	return 0;
}

