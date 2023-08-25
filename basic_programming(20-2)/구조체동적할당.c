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

		printf("이름은?: ");
		scanf("%s",class[i].name);

		printf("학년은?: ");
		scanf("%d", &class[i].grade);

		printf("평점은?: ");
		scanf("%d", &class[i].abcd);
		getchar(); // fflush(stdin);
	}

	for (int i = 0; i < 3; i++) {
		printf("이름: %s, 학년: %d, 평점: %d\n", class[i].name, class[i].grade, class[i].abcd);
		printf("\n");
	}
	return 0;
}