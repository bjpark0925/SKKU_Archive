#pragma warning (disable:4996)
#include<stdio.h>
int main() {
	int arr[5];
	int i, j, k;
	int tmp;

	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	
	
	for (j = 0; j < 4; j++) {
		if (arr[j] > arr[j + 1]) {
			tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
		}
	}
	
	for (k = 0; k < 5; k++) {
		printf("%d\n", arr[k]);
	}

	return 0;
}