#include<stdio.h>
int main() {
	int n, m, big, small;
	int temp, lcm;
	scanf_s("%d %d", &n, &m);

	if (n > m) {
		big = n;
		small = m;
	}
	else {
		big = m;
		small = n;
	}

	while (1) {
		if (big % small == 0) {
			break;
		}
		temp = big % small;
		big = small;
		small = temp;
	}
	lcm = n * m * small;

	printf("%d", lcm);

	return 0;
}