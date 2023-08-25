#include <stdio.h>
int main() {
	// 5명 퀴즈 점수 받고, 평균 미만 학생 수 구하기
	int quiz[5];
	double avg, sum=0.0;
	int i;
	int count = 0;

	for (i = 0; i < 5; i++) {
		scanf_s("%d", &quiz[i]);
		sum += quiz[i];
	}// for
	
	avg = sum / 5.0;

	printf("AVG : %lf\n",avg);

	for (i = 0; i < 5; i++) {
		if (avg > quiz[i]) count++;
	}
	printf("COUNT : %d\n", count);

	for (i = 0; i < 5; i++) {
		printf("%d >> %lf\n", quiz[i], quiz[i] - avg);
	}

	return 0;
}