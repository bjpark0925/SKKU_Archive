#include<stdio.h>
int main() {
	//문자 입력, 문자의 아스키코드값은 ~.
	char a;

	scanf_s("%c", &a);

	printf("%c의 아스키코드 값은 %d.\n", a, a);



	return 0;
}