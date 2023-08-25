#include<stdio.h>
int main() {
	int a, i, prime;
	scanf_s("%d", &a);

	for (i = 2; i < a; i++) {
		if (a % i == 0)
			prime = 0;
		else
			prime = 1;//소수
	}
	if (prime)
		printf("소수");
	else
		printf("소수아님");


	return 0;
}