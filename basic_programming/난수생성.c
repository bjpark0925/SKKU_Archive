#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

	srand(time(NULL));
	int random, i, sum, answer;
	random = 0;
	sum = 0;

	for (i = 1; i < 10; i++) { 
		random = rand() % 100;
		sum += random;
		printf("%d + ", random);
	}
	printf("\b");
	printf("\n");
	scanf_s("%d", &answer);
	
	while (1) {
		if (answer == sum) {
			printf("����");
			break;
		}
		else {
			printf("��! �ٽ��Է�");
			scanf_s("%d", &answer);
		}
	}
}