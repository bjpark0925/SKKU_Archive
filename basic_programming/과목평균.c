#include<stdio.h>
int main() {
	int kor, math, eng;
	double avg;

	scanf_s("%d %d %d", &kor, &math, &eng);

	avg = (double)(kor + math + eng) / 3;

	printf("%.2lf", avg);


	return 0;
}