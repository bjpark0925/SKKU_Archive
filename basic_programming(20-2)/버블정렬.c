#include<stdio.h>
int main() {
	// ���� ����
	int num[5];
	int temp;
	int i, j, k;
	int max, secmax;

	for (i = 0; i < 5; i++) {
		scanf_s("%d", &num[i]);
	}

	for (j = 0; j < 5; j++) {//5�� �ݺ�
		for (k = 0; k < 4; k++) {//4�� �ݺ�
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