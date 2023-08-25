#include<stdio.h>
int main() {
	// 버블 정렬
	int num[5];
	int temp;
	int i, j, k;
	int max, secmax;

	for (i = 0; i < 5; i++) {
		scanf_s("%d", &num[i]);
	}

	for (j = 0; j < 5; j++) {//5번 반복
		for (k = 0; k < 4; k++) {//4번 반복
			if (num[k] > num[k + 1]) {
				temp = num[k];
				num[k] = num[k + 1];
				num[k + 1] = temp;
			}
		}
	}
	max = num[4];
	secmax = num[3];

	printf("%d\n%d", max, secmax);

	return 0;
}