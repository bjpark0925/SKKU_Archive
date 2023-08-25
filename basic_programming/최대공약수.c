#include<stdio.h>
int main() {
	int n, m;
	int r;
	int max;

	scanf_s("%d %d", &n, &m);

	if (n >= m) {
		while (1) {
			if (m == 0) {
				max = n;
				break;
			}
			r = n % m;
			n = m;
			m = r;
		}
	}
	else {
		while (1) {
			if (n == 0) {
				max = m;
				break;
			}
			r = m % n;
			m = n;
			n = r;
		}
	}
	printf("%d", max);

	return 0;
}