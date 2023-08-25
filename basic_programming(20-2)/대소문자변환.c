#include<stdio.h>
int main() {
	// m->M
	char a, b;

	scanf_s("%c", &a);

	if ((a >= 'a') && (a <= 'z')) {
		b = 'a' - 'A';
	}
	else if ((a >= 'A') && (a <= 'Z')) {
		b = 'A' - 'a';
	}
	else { printf("그외의 문자임"); }

	printf("'%c' -> '%c'", a, a - b);

	return 0;
}