#pragma warning (disable: 4996)
#include<stdio.h>
#include<string.h>

//����ü�� a,b,c,d�� ���� �ʱ�ȭ���� �ʰ�, �ʿ��� ��ŭ�� �����
//���ĺ� ������ ����� �ƴ�, �Է� ������ ����� �� ���

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
		//�ߺ��� �� Ȯ�� �� ���
		for (int j = 0; j < size; j++) {
			if (a1[j].alphabet == word[i]) {
				a1[j].cnt++;
				is_alpha = 1;
			}
		}
		if (is_alpha == 1) { // is_alpha ������ ����, �ʱ�ȭ
			is_alpha = 0;
			continue;
		}
		//

		a1[size].alphabet = word[i];
		a1[size].cnt++;
		size++;
	}

	printf("size: %d\n", size); // a1�� �� ����ƴ��� Ȯ�ο�

	//��������
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