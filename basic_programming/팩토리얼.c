#include<stdio.h>
int main() {
	int a, fact;
	int i;
	fact = 1;
	scanf_s("%d", &a);

	for (i = a; i >= 1; i--) {
		fact *= i;
	}
	printf("%d!=%d", a, fact);


	return 0;
}