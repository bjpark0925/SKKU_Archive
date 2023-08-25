#pragma warning (disable: 4996)
#include <stdio.h>
int main() {

	char arr[11][80];
	int i, j;

	for (i = 0; i < 10; i++) {
		scanf("%s", &arr[i + 1]);
		getchar();
	}

	for (i = 0; i < 11; i++)
		printf("%s ", &arr[i]);

	return 0;
}