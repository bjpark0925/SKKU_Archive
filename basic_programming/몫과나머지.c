#include<stdio.h>
int main() {
	int n, m;
	int big, small;
	int neck, rest;

	scanf_s("%d %d", &n, &m);

	(n >= m) ? ((big = n) && (small = m)) : ((big = m) && (small = n));

	/*if (n >= m) {
		big = n;
		small = m;
	}
	else {
		big = m;
		small = n;
	}*/
	neck = big / small;
	rest = big % small;

	printf("%d\n", neck);
	printf("%d\n", rest);


	return 0;
}