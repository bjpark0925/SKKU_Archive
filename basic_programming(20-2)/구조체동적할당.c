#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct School
{
	char name[20];
	int grade;
	int abcd;
}score;


int main(void)
{
	score* class = (score*)malloc(sizeof(score)*3);

	for (int i = 0; i < 3; i++) {

		printf("�̸���?: ");
		scanf("%s",class[i].name);

		printf("�г���?: ");
		scanf("%d", &class[i].grade);

		printf("������?: ");
		scanf("%d", &class[i].abcd);
		getchar(); // fflush(stdin);
	}

	for (int i = 0; i < 3; i++) {
		printf("�̸�: %s, �г�: %d, ����: %d\n", class[i].name, class[i].grade, class[i].abcd);
		printf("\n");
	}
	return 0;
}