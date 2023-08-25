#include<stdio.h>
int main() {
	int n;
	int n1000, n100, n10, n1, temp;

	scanf_s("%d", &n);

	n1000 = n / 1000;
	temp = n % 1000;

	n100 = temp / 100;
	temp = temp % 100;

	n10 = temp / 10;
	n1 = temp % 10;

	if (n >= 1000) {
		if ((n1 != 0)) {
			printf("%d%d%d%d", n1, n10, n100,n1000);
		}
		else if ((n1 == 0) && (n10 != 0)) {
			printf("%d%d%d", n10, n100, n1000);
		}
		else if ((n1 == 0) && (n10 == 0) && (n100 != 0)) {
			printf("%d%d", n100, n1000);
		}
		else{
			printf("%d", n1000);
		}
	}
	else if ((n >= 100) && (n < 1000)) {
		if ((n1 != 0) && (n10 != 0)) {
			printf("%d%d%d", n1, n10, n100);
		}
		else if ((n1 == 0) && (n10 != 0)) {
			printf("%d%d",n10, n100);
		}
		else if ((n != 0) && (n10 == 0)) {
			printf("%d%d%d", n1, n10, n100);
		}
		else{
			printf("%d", n100);
		}
	}
	else if ((n >= 10) && (n < 100)) {
		if ((n1 != 0)) {
			printf("%d%d", n1, n10);
		}
		else printf("%d", n10);
	}
	else printf("%d", n);
	
	return 0;
}