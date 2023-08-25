#include<stdio.h>
int main() {
	int n, yak, i;
	int sum = 0;
	scanf_s("%d", &n);

	for (i = 2; i < n; i++) {
		if (n % i == 0) {
			yak = i;
			printf("%d+", yak);
			sum += yak;
		}
	}
	printf("%d=", n);
	sum += n;
	printf("%d", sum);

	return 0;
}