#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>

typedef struct {
	char alphabet;
	int cnt;
}Alphabet;

int main() {

	char word[20] = { '\0', };
	scanf("%s", word);

	Alphabet a1[27];

	for (int i = 0; i < 27; i++) {
		a1[i].alphabet = 'a' + i;
		a1[i].cnt = 0;
	}
	
	for (int i = 0; i < strlen(word); i++) {
		a1[word[i]-'a'].cnt++;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			if (a1[j].cnt < a1[j + 1].cnt) {
				char temp = a1[j].alphabet;
				a1[j].alphabet = a1[j + 1].alphabet;
				a1[j + 1].alphabet = temp;

				int tmp = a1[j].cnt;
				a1[j].cnt = a1[j + 1].cnt;
				a1[j + 1].cnt = tmp;
			}
		}
	}

	for (int i = 0; i < 27; i++) {
		if (a1[i].cnt == 0)
			continue;
		printf("%c %d\n", a1[i].alphabet, a1[i].cnt);
	}

	
	
	return 0;
}