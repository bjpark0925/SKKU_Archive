#pragma warning(disable:4996)
#include <stdio.h>
int main() {

	int* p;
	int arr[10] = {13, 23, 56, 4, 9, 10, 90, 44, 65, 80};
	int i;

	printf("arr: ");
	for (i = 0; i < 10; i++) {
		printf("%d ", *(arr+i));//a[i]
	}
	printf("\n\n");

	p = &arr[5];
	printf("point: ");
	for (i = 0; i < 10; i++) {
		printf("%d ", *(p+i));//p[i]
	}
	printf("\n\n");
	printf("arr[0] >> %d\n\n", arr[0]);
	printf("*p >> %d\n\n", *p);



	return 0;
}