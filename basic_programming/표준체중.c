#include<stdio.h>
int main() {

	double height, weight;
	double feet, pound;
	double standard;

	printf("Ű �Է�: ");
	scanf_s("%lf", &height);

	printf("������ �Է�: ");
	scanf_s("%lf", &weight);

	feet = 30.48 * height;
	pound = weight / 2.204591;
	standard = (height - 100) * 0.9;

	printf("\n");
	printf("����� Ű�� %.1lfcm(%.1lffeet)�Դϴ�.\n", height, feet);
	printf("����� ü���� %.1lfkg(%.1lfpound)�Դϴ�.\n", weight, pound);
	printf("ǥ��ü�� %.1lfkg���� ���̴� %.1lfkg�Դϴ�.\n", standard, weight - standard);
	
	return 0;
}