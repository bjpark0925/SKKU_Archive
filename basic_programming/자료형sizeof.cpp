#include <stdio.h>
#pragma warning (disable:4996);

int main() {
	char x;
	int y;
	double z;

	printf("char�� ���� x�� ũ�� = %d\n", sizeof x);
	printf("int�� ���� y�� ũ�� = %d\n", sizeof y);
	printf("doubld�� ���� z�� ũ�� = %d\n", sizeof(z));
	printf("float���� ũ�� = %d\n", sizeof(float));

	return 0;
}