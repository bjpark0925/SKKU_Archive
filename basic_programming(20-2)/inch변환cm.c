#include<stdio.h>
int main() {
	//~inch는 ~cm입니다.
	double input, output;

	scanf_s("%lf", &input);

	//1inch=2.54cm
	output = 2.54 * input;

	printf("%.2lfinch는 %.2lfcm입니다.", input, output);
	

	return 0;
}