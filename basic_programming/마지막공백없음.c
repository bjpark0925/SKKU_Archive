#pragma warning(disable:4996)
#include <stdio.h>
int main() {

	int n;
	int prime;
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (n % i == 0)
			prime = 1;
		else
			prime = 0;

		if ((prime)&&(i!=n)) {
			printf("%d ", i);
		}
		if ((prime) && (i == n)) {
			printf("%d", i);
		}
	}

	return 0;
}