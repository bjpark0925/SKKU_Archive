#include<stdio.h>
int main() {
	int num, a, b, c, d, mod;

	printf("���ڸ� ������ �Է��ϼ���.>>");
	scanf_s("%d", &num);
	printf("\n");

	a = num / 1000;
	mod = num % 1000;

	b = mod / 100;
	mod = mod % 100;

	c = mod / 10;
	d = mod % 10;

	printf("�Է��� ���� %dõ%d��%d��%d �Դϴ�.\n", a, b, c, d);
	
	return 0;
}