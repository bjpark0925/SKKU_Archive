#pragma warning(disable:4996)
#include<stdio.h>

void print_row1(int, int);
void print_row2(int, int);

int main() {
	int N;
	int x = 0;
	int i;

	scanf("%d", &N);

	print_row1(x, N);
	printf("\n");
	for (i = 0; i <= N - 3; i++) {
		print_row2(x, N);
		printf("\n");
	}
	print_row1(x, N);

	return 0;
}

void print_row1(int x, int N)
{
	for (x = 0; x <= N-1; x++) {
		printf("%d",N);
	}
}

void print_row2(int x, int N)
{
	printf("%d", N);
	for (x = 0; x <= N-3; x++) printf(" ");
	printf("%d", N);
}