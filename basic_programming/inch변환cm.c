#include<stdio.h>
int main() {
	//~inch�� ~cm�Դϴ�.
	double input, output;

	scanf_s("%lf", &input);

	//1inch=2.54cm
	output = 2.54 * input;

	printf("%.2lfinch�� %.2lfcm�Դϴ�.", input, output);
	

	return 0;
}