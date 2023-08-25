#include<stdio.h>
int main() {

	double height, weight;
	double feet, pound;
	double standard;

	printf("키 입력: ");
	scanf_s("%lf", &height);

	printf("몸무게 입력: ");
	scanf_s("%lf", &weight);

	feet = 30.48 * height;
	pound = weight / 2.204591;
	standard = (height - 100) * 0.9;

	printf("\n");
	printf("당신의 키는 %.1lfcm(%.1lffeet)입니다.\n", height, feet);
	printf("당신의 체중은 %.1lfkg(%.1lfpound)입니다.\n", weight, pound);
	printf("표준체중 %.1lfkg과의 차이는 %.1lfkg입니다.\n", standard, weight - standard);
	
	return 0;
}