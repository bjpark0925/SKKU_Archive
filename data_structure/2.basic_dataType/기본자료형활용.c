#pragma warning(disable: 4996)
#include<stdio.h>

#define num 3

typedef struct _GuestBook {
	char name[30];
	unsigned int age;
	float length;
	double height;
	long double weight;
}guestbook;

int main() {

	int cnt = 0;

	guestbook p[num];

	printf("================================================================================\n");
	printf("������ �湮�� ������� ���� �߿���, ���̰� 65�� �̻��� ������� �������� ���α׷�\n");
	printf("================================================================================\n\n");
	printf("�湮�� %d�� ������ �̸�, ����, �㸮�ѷ�(�Ǽ�), Ű(�Ǽ�), ������(�Ǽ�)�� ���ʷ� �Է��ϼ���.\n",num);

	for (int i = 0; i < num; i++) {
		scanf("%s", p[i].name);
		scanf("%d", &p[i].age);
		scanf("%f", &p[i].length);
		scanf("%f", &p[i].height);
		scanf("%lf", &p[i].weight);
	}
	
	for (int i = 0; i < num; i++) {
		if (p[i].age >= 65) {
			printf("%s��, ", p[i].name);
			cnt++;
		}
	}

	if (cnt != 0) {
		printf("\b\b���� 65�� �̻� �湮���Դϴ�.\n");
	}

	printf("65�� �̻� �湮�� ���� �� %d���Դϴ�.\n", cnt);

	return 0;
}