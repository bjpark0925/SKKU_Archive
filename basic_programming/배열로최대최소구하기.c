#include<stdio.h>
int main() {
	// �迭�� �ִ� �ּ� ���ϱ�

	int arr[5];
	int i;
	int max, min;

	for (i = 0; i < 5; i++) {
		scanf_s("%d", &arr[i]);
	}
	
	max = min = arr[0];
	for (i = 0; i < 5; i++) {
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}
	
	printf("max >> %d\n", max);
	printf("min >> %d\n", min);

	return 0;
}