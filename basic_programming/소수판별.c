#include<stdio.h>
int main() {
	int a, i, prime;
	scanf_s("%d", &a);

	for (i = 2; i < a; i++) {
		if (a % i == 0)
			prime = 0;
		else
			prime = 1;//�Ҽ�
	}
	if (prime)
		printf("�Ҽ�");
	else
		printf("�Ҽ��ƴ�");


	return 0;
}