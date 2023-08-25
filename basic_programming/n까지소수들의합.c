#include<stdio.h>
int main() {
	int i, j, n;
	int sum;
	sum = 0;
	scanf_s("%d", &n);

	if (n <= 1)
		printf("NONE");
	else {
		for (i = 2; i <= n; i++) {
			for (j = 2; j < i; j++) {
				if (i % j == 0)
					break;
			}
			if ((i < n) && (i == j)) {
				printf("%d+", i);
				sum += i;
			}
			if ((i == n) && (i == j)) {
				printf("%d", i);
				sum += i;
			}
		}
		printf("=%d", sum);
	}
	return 0;
}