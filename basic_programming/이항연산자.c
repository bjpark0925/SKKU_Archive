#include<stdio.h>;
int main() {

	int a, b, c;
	int max;

	printf("�� ���� �Է� >>");
	scanf_s("%d %d %d", &a, &b, &c);
	printf("\n");

	max = (a > b) ? a : b;
	max = (max > c) ? max : c;

	printf("%d\n", max);

	return 0;
}