#pragma warning (disable: 4996)
#include <stdio.h>
int main() {

	int score[3][2];
	int i, k;
	int Akor, Amath, Bkor, Bmath, Ckor, Cmath;
	int sumA, sumB, sumC;
	
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 2; i++) {
			scanf("%d", &score[k][i]);
		}
	}

	Akor = score[0][0];
	Amath = score[0][1];
	Bkor = score[1][0];
	Bmath = score[1][1];
	Ckor = score[2][0];
	Cmath = score[2][1];

	sumA = Akor + Amath;
	sumB = Bkor + Bmath;
	sumC = Ckor + Cmath;

	printf("%d\n%d\n%d", sumA, sumB, sumC);

	return 0;
}