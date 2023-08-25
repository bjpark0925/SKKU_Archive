#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>

//구조체를 a,b,c,d로 전부 초기화하지 않고, 필요한 만큼만 사용함
//알파벳 순으로 출력이 아닌, 입력 순으로 출력할 때 사용

typedef struct {
	char alphabet;
	int cnt;
}Alphabet;

int main() {

	char word[20] = { '\0', };
	scanf("%s", word);

	Alphabet a1[27];

	for (int i = 0; i < 27; i++) {
		a1[i].alphabet = '\0';
		a1[i].cnt = 0;
	}

	int size = 0;
	int is_alpha = 0;

	for (int i = 0; i < strlen(word); i++) {
		//중복된 것 확인 및 계산
		for (int j = 0; j < size; j++) {
			if (a1[j].alphabet == word[i]) {
				a1[j].cnt++;
				is_alpha = 1;
			}
		}
		if (is_alpha == 1) { // is_alpha 재사용을 위해, 초기화
			is_alpha = 0;
			continue;
		}
		//

		a1[size].alphabet = word[i];
		a1[size].cnt++;
		size++;
	}

	printf("size: %d\n", size); // a1에 잘 저장됐는지 확인용

	//버블정렬
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
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

	for (int i = 0; i < size; i++) {
		printf("%c %d\n", a1[i].alphabet, a1[i].cnt);
	}



	return 0;
}