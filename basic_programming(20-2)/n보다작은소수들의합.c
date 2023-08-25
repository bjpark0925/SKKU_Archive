#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
int main() {
	//n까지의 소수 전부 출력 및 소수들의 합
	int i, j, n;
	scanf("%d", &n);

	int prime[10] = { 0, }; //소수들을 저장할 int형 배열
	int is_prime = 1;
	int size = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				is_prime = -1;
				break;
			}
		}
		if (is_prime == 1) {
			prime[size] = i;
			size++;
		}
		is_prime = 1; // 초기화 중요
	}

	if (size == 0)
		printf("NONE");
	else {
		int sum = 0;

		for (int i = 0; i < size; i++) {
			if (i == size - 1) {
				sum += prime[i];
				printf("%d=%d\n", prime[i], sum);
				break;
			}
			sum += prime[i];
			printf("%d+", prime[i]);
		}
	}
	return 0;
}