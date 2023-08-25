#pragma warning (disable: 4996)
#include <stdio.h>
#include <string.h>
int main() {

	char arr[20];

	scanf("%s", arr);

	printf("%s\n", arr);

	int size = strlen(arr);
	char last = '\0';

	for (int i = 0; i < size; i++) {
		last = arr[size - 1];
		for (int j = size - 1; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = last;
		printf("%s\n", arr);
	}

	return 0;
}