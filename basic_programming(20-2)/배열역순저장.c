#pragma warning (disable: 4996)
#include <stdio.h>
int main() {
	char array[30] = { '\0', };
	char temp[30] = { '\0', };
	scanf("%s", array);

	int size = strlen(array);

	printf("원래 : ");
	for (int i = 0; i < size; i++)
		printf("%c", array[i]);
	printf("\n\n");

	int j = 0;
	for (int i = size - 1; i >= 0; i--) {
		temp[j] = array[i];
		j++;
	}

	printf("역순: ");
	for (int i = 0; i < size; i++)
		printf("%c", temp[i]);
	printf("\n\n");


	return 0;
}