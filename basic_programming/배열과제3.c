#pragma warning (disable:4996)
#include <stdio.h>
int main() {

	int Input[3];
	int i, j;
	char English[6][6]={
		"ZERO-", 
		"ONE--", 
		"TWO--", 
		"THREE", 
		"FOUR-", 
		"FIVE-"
	};

	for (i = 0; i < 3; i++) {
		scanf("%d", &Input[i]);
	}
	
	for (j = 0; j < 3; j++) {
		printf("%s\n", English[Input[j]]);
	}

	return 0;
}