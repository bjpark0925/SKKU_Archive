#pragma warning (disable: 4996)
#include <stdio.h>
int main() {

	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int i;

	printf("���� : ");
	for (i = 0; i <= 10; i++)
		printf("%d ", arr[i]);
	printf("\n\n");

	printf("���� : ");
	for (i = 10; i >= 0; i--)
		printf("%d ", arr[i]);
	printf("\n\n");


	return 0;
}