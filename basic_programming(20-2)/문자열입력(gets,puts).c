#pragma warning (disable: 4996)
#include <stdio.h>

int main() {

	char str[40];

	//scanf("%s", str);
	// ���ڿ��� ��� & �Ⱦ�(str ��ü�� �ּ��̹Ƿ�)
	// %c(���� �ϳ�)�� ���� �迭 ��Ұ� �;��ϹǷ� ���� str[0]�տ� &�ٿ�����.
	gets(str); // ���� ����

	// 'a'�� ���� a, "a"�� ���ڿ� a(�ּұ��� ����).

	//printf("%s\n", str); 
	// str[0]���� �����ؼ� null char���������� ���
	puts(str);
	


	return 0;
}