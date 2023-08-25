#pragma warning(disable:4996)
#include <stdio.h>
#include <malloc.h> // memory allocation

int* memoryEx(int*, int);

int main() {

	int size;
	int* pData;
	int i;

	scanf("%d", &size);

	pData = (int *)malloc(sizeof(int)*size); //������ Ÿ���� �����ϰ� �ϴ� ĳ����

	for (i = 0; i < size; i++) {
		pData[i] = rand(); //�����Ͷ�� �ؼ� *�� ������ �� �ʿ�� ����. �迭ó�� �����ص� ��
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