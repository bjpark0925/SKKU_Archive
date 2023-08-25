#pragma warning(disable:4996)
#include<stdio.h>
int main() {

	int arr[9];
	int i;
	int sum;

	for (i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	sum = arr[0] + arr[4] + arr[8];

	printf("%d", sum);


	return 0;
}