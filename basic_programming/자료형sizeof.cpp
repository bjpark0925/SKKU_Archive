#include <stdio.h>
#pragma warning (disable:4996);

int main() {
	char x;
	int y;
	double z;

	printf("char형 변수 x의 크기 = %d\n", sizeof x);
	printf("int형 변수 y의 크기 = %d\n", sizeof y);
	printf("doubld형 변수 z의 크기 = %d\n", sizeof(z));
	printf("float형의 크기 = %d\n", sizeof(float));

	return 0;
}