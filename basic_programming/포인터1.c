#pragma warning(disable:4996)
#include <stdio.h>
#include <malloc.h> // memory allocation

int* memoryEx(int*, int);

int main() {

	int size;
	int* pData;
	int i;

	scanf("%d", &size);

	pData = (int *)malloc(sizeof(int)*size); //데이터 타입을 동일하게 하는 캐스팅

	for (i = 0; i < size; i++) {
		pData[i] = rand(); //포인터라고 해서 *를 무조건 쓸 필요는 없다. 배열처럼 접근해도 됨
	}

	printf("data: ");
	for (i = 0; i < size; i++) {
		printf("%d ", pData[i]);
	}
	printf("\n\n");

	pData = memoryEx(pData, size);

	free(pData);

	return 0;
}

int* memoryEx(int* data, int size)
{
	int temp;

	temp = (int*)malloc(sizeof(int) * size * 2);

	for (int i = 0; i < size; i++) temp[i] = data[i];
	free(data);

	return temp;
}