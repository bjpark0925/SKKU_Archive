#include<stdio.h>
int main() {
	int score, sum, pass, fail, i;
	double avg;
	sum = 0;
	pass = 0;
	fail = 0;

	for (i = 1; i <= 10; i++) {
		scanf_s("%d", &score);
		sum += score;
		if (score >= 70)
			pass++;
		else
			fail++;
	}
	avg = (double) sum / 10;

	printf("%.1lf\n%d\n%d\n", avg, pass, fail);

	return 0;
}