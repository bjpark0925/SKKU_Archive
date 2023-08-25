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
	printf("병원에 방문한 사람들의 정보 중에서, 나이가 65세 이상인 사람들을 밝혀내는 프로그램\n");
	printf("================================================================================\n\n");
	printf("방문자 %d명 각각의 이름, 나이, 허리둘레(실수), 키(실수), 몸무게(실수)를 차례로 입력하세요.\n",num);

	for (int i = 0; i < num; i++) {
		scanf("%s", p[i].name);
		scanf("%d", &p[i].age);
		scanf("%f", &p[i].length);
		scanf("%f", &p[i].height);
		scanf("%lf", &p[i].weight);
	}
	
	for (int i = 0; i < num; i++) {
		if (p[i].age >= 65) {
			printf("%s님, ", p[i].name);
			cnt++;
		}
	}

	if (cnt != 0) {
		printf("\b\b께서 65세 이상 방문자입니다.\n");
	}

	printf("65세 이상 방문자 수는 총 %d명입니다.\n", cnt);

	return 0;
}