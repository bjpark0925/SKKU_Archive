#include<stdio.h>
int main() {
	//n������ �Ҽ� ���� ���
	int i, j, n;
	scanf_s("%d", &n);

	for (i = 2; i <= n; i++) {
		for (j = 2; j < i; j++) {
			if (i % j == 0)
				break;
		}
		if (i == j)
			printf("%d ", i);
	}

	return 0;
}