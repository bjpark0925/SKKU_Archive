#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	// 영단어 3글자 행맨게임
	char answer[4];
	char blank[4] = { '_', '_', '_', '\0' };
	char input;
	int i;
	int cnt = 0;

	gets(answer);

	while (1) {
		if (cnt == 5)
			break;

		if (!strcmp(answer, blank))
			break;

		scanf("%c", &input);
		getchar();
		cnt++;

		for (i = 0; i < 3; i++) {
			if (input == answer[i]) {
				blank[i] = input;
			}
			printf(" %c", blank[i]);
		}
		printf("\n");
	}

	return 0;
}