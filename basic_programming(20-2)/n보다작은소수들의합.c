#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
int main() {
	//n������ �Ҽ� ���� ��� �� �Ҽ����� ��
	int i, j, n;
	scanf("%d", &n);

	int prime[10] = { 0, }; //�Ҽ����� ������ int�� �迭
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
		is_prime = 1; // �ʱ�ȭ �߿�
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