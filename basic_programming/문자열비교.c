#pragma warning(disable: 4996)
#include<stdio.h>
int main() {

	char str1[40], str2[40];

	scanf("%s", str1);
	scanf("%s", str2);

	if (strcmp(str1, str2) == 0) {
		printf("Equal!!\n");
	}
	else
		printf("Not Equal!!\n");


	/*printf("length: %d\n", strlen(str1));

	strcpy(str2, str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
	*/
	return 0;
}