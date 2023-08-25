#pragma warning <disable: 4996>
#include <stdio.h>

typedef struct STUDENT_INFO {
	char name[40];
	int score;
}STUDENT;

STUDENT students[5];
void insertstruct();
void aboveavg();
int i;
double avg = 0.0;

int main() {


	for (i = 0; i < 5; i++)
		insertstruct();

	aboveavg();



	return 0;
}
void insertstruct() {

	
	scanf("%s", students[i].name);
	scanf(" %d", students[i].score);

}

void aboveavg() {

	avg = (students[0].score + students[1].score + students[2].score + students[3].score + students[5].score)/5;
	for (i = 0; i < 5; i++) {
		if (avg > students[i].score)
			printf("%s", students[i].name);

	}
}
