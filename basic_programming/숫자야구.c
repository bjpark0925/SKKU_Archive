#include<stdio.h>
int main() {
	int answer1, answer2, answer3;
	int guess1, guess2, guess3;
	int strike = 0;
	int ball = 0;

	scanf_s("%d %d %d", &answer1, &answer2, &answer3);
	scanf_s("%d %d %d", &guess1, &guess2, &guess3);

	if (answer1 == guess1)strike++;
	if (answer2 == guess2)strike++;
	if (answer3 == guess3)strike++;
	if (answer1 == guess2 || answer1 == guess3)ball++;
	if (answer2 == guess1 || answer2 == guess3)ball++;
	if (answer3 == guess1 || answer3 == guess2)ball++;
		
	printf("%dS%dB", strike, ball);

	return 0;
}