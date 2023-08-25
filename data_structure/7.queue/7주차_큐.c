#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//문자열 길이, 복사 위한 헤더
#include<stdbool.h>//true, false

#define Max_Size 30 // 큐의 크기를 30으로 static하게 설정(마지막은 '\0'가 있어야 하므로 실질적 크기는 29)

void UserSetting()
{
	printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n\n");
	printf("+abcd : enqueue 명령(enqueue할 요소는 마음대로)\n");
	printf("L : 큐 전체 출력\n");
	printf("P : head 위치의 요소 peek(보기)\n");
	printf("- : head 위치의 요소 하나만 dequeue 명령\n");
	printf("-5 : head 위치의 요소부터 5개까지 dequeue(5가 아니어도 됨)\n");
	printf("F : 큐가 꽉 찼는지 여부\n");
	printf("# : 큐 요소 개수 확인\n");
	printf("H : head의 현재 위치 출력\n");
	printf("T : tail의 현재 위치 출력\n");
	printf("E : 빈 큐 여부\n");
	printf("?a : 큐에 요소가 있는지 여부(a가 아니어도 됨)\n");
	printf("=a : tail 위치에 있는 요소를 사용자가 입력한 요소로 변경(a가 아니어도 됨)\n");
	printf("C : 큐 비우기(요소들 보여주면서 비워짐)\n");
	printf("Q : 프로그램 종료\n\n");
	printf("밑의 3개는 자신만의 기능\n");
	printf("S : 앞으로 정렬(앞에 빈 자리가 없도록 요소들을 이동)\n");
	printf("Z : tail 뒤에 남은 자리가 얼마인지 출력\n");
	printf("R : 큐의 순서를 반대로 해서 출력(큐의 상태는 그대로)\n\n");
	printf("PrintAll 함수와 is_member 함수에서 head를 원래대로 하는 연산을 수정했습니다.\n\n");

}
int Setposition()//head의 처음 위치 설정
{
	return -1;//큐에 아무것도 들어있지 않을 때, head와 tail은 -1
}

typedef struct _position
{
	int head;
	int tail;

}Position;

void Positioninit(Position* p)
{
	p->head = Setposition();
	p->tail = Setposition();
}


int DataCount(Position* p)//큐 요소 개수
{
	return p->tail - p->head;
}

void Shift(char array[], Position* p)
{
	if (p->head == -1)//이미 앞으로 정렬된 상태이면 그대로 반환
		return;

	int frontlen = p->head + 1;//head 앞에 남은 자리의 개수
	int i = 0;

	while (p->head != p->tail) {//요소들을 모두 앞으로 당김
		p->head++;
		array[i] = array[p->head];
		array[p->head] = '\0';
		i++;
	}

	p->head = Setposition();//head와 tail 위치 재설정
	p->tail -= frontlen;
}

void Enqueue(char array[], char order[], Position* p)//enqueue함수
{
	char temp_array[Max_Size];
	int enlen, rearlen, frontlen, remainlen;

	int i;

	for (i = 0; i < strlen(order) - 1; i++) {//+abcd를 temp_array에 abcd로 저장
		temp_array[i] = order[i + 1];
	}
	temp_array[strlen(order) - 1] = '\0';

	enlen = strlen(temp_array);//사용자가 넣고 싶은 요소의 개수(ex.abcd면 4개)
	rearlen = Max_Size - p->tail - 2;//tail 뒤에 남은 자리의 개수
	frontlen = p->head + 1;//head 앞에 남은 자리의 개수
	remainlen = frontlen + rearlen;//큐에 남은 자리의 총 개수

	if (enlen > rearlen) {//enlen보다 tail 뒤의 자리가 부족할 때(ex. 4개 넣고 싶은데 tail 뒤에 3자리밖에 없을 때)
		if (enlen > remainlen)//enlen보다 remainlen이 부족할 때
			printf("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다.\n", remainlen);
		else {//남은 자리의 총 개수가 모자르지 않을 때
			Shift(array, p);//앞에 빈자리가 없도록 큐 정렬

			for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}

	else {//큐에 자리가 넉넉할 때
		for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
			array[p->tail + 1 + i] = temp_array[i];
		}

		p->tail += strlen(temp_array);
	}
}

void PrintAll(char array[], Position* p)//큐 전체 출력 함수
{
	char temp_array[Max_Size] = { '\0', };
	int i = 0;
	int enlen, rearlen, frontlen, remainlen;

	if (p->head == p->tail)//큐가 비었으면
		printf("출력할 것이 없음\n");

	else {//큐에 저장된 것이 있는 경우
		while (p->head != p->tail)
		{
			p->head++;
			printf("%c", array[p->head]);//head요소를 peek하고
			temp_array[i] = array[p->head];//temp_array에 저장
			i++;
		}
		printf("\n");

		//이후 temp에 넣어뒀던 것들을 다시 큐에 넣음
		//enqueue의 과정과 동일

		enlen = strlen(temp_array);//넣고 싶은 요소의 개수(ex.abcd면 4개)
		rearlen = Max_Size - p->tail - 2;//tail 뒤에 남은 자리의 개수
		frontlen = p->head + 1;//head 앞에 남은 자리의 개수
		remainlen = frontlen + rearlen;//큐에 남은 자리의 총 개수

		if (enlen > rearlen) {//enlen보다 tail 뒤의 자리가 부족할 때(ex. 4개 넣고 싶은데 tail 뒤에 3자리밖에 없을 때)
			if (enlen > remainlen)//enlen보다 remainlen이 부족할 때
				printf("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다.\n", remainlen);
			else {//남은 자리의 총 개수가 모자르지 않을 때
				Shift(array, p);//앞에 빈자리가 없도록 큐 정렬

				for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
					array[p->tail + 1 + i] = temp_array[i];
				}

				p->tail += strlen(temp_array);
			}
		}

		else {//큐에 자리가 넉넉할 때
			for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}
}

void Peek(char array[], Position* p)//head에 있는 것을 출력하는 peek함수
{
	if (p->head == p->tail)//큐가 비었으면
		printf("peek할 것이 없음\n");
	else//큐에 저장된 것이 있는 경우
	{
		int savehead = p->head;
		p->head++;
		printf("%c\n", array[p->head]);
		p->head = savehead;
	}
}

void Dequeue(char array[], char order[], Position* p)//dequeue함수(한번에 하나씩만 꺼낼 수도, 숫자를 이용해 여러 개 꺼낼 수도 있음)
{
	char s1[30];
	int num;

	if (order[1] != '\0') {//-숫자 형태로 입력받은 경우
		for (int i = 0; i < strlen(order) - 1; i++) {//예를 들어 사용자가 -12를 입력했으면, 12를 s1에 문자 형태로 저장
			s1[i] = order[i + 1];
		}
		s1[strlen(order) - 1] = '\0';

		num = atoi(s1);//12를 숫자로 변환

		if (num != 0) {//-이후 사용자가 정수를 입력한 경우
			if (num > DataCount(p))
				printf("입력한 숫자가 큐에 있는 요소 개수보다 많습니다. 다시 입력하세요");
			else {
				for (int i = 0; i < num; i++) {
					p->head++;
					printf("%c", array[p->head]);//peek하고
					array[p->head] = '\0';//삭제
				}
				printf(" 삭제");
			}
		}
	}

	else {//-만 입력받은 경우
		if (p->head == p->tail)//큐가 비었으면
			printf("dequeue할 것이 없음\n");

		else {//큐에 저장된 것이 있는 경우
			p->head++;
			printf("%c", array[p->head]);//peek하고
			array[p->head] = '\0';//삭제
		}
	}
}

bool is_full(Position* p)//큐 가득 찼는지 여부
{
	if (p->tail == Max_Size - 2)
		return true;
	else
		return false;
}


int Head(Position* p)
{
	return p->head;
}

int Tail(Position* p)
{
	return p->tail;
}

bool is_empty(Position* p)
{
	if (p->head == p->tail)
		return true;
	else
		return false;
}

bool is_member(char array[], char order[], Position* p)//큐에 요소가 있는지 여부 함수
{
	char temp_array[Max_Size] = { '\0', };
	int i = 0;
	int enlen, rearlen, frontlen, remainlen;
	bool exist = false;//요소 존재 여부 확인하는 변수

	if (is_empty == 1)//큐에 저장된 것이 없는 경우
		printf("False\n");

	else {//큐에 저장된 것이 있는 경우
		while (p->head != p->tail)
		{
			p->head++;
			if (array[p->head] == order[1])//큐에 요소가 존재하면
				exist = true;
			temp_array[i] = array[p->head];//temp_array에 저장
			i++;
		}

		//head를 원래대로 하는 것이 아닌, enqueue의 과정이 이루어지도록 함

		enlen = strlen(temp_array);//넣고 싶은 요소의 개수(ex.abcd면 4개)
		rearlen = Max_Size - p->tail - 2;//tail 뒤에 남은 자리의 개수
		frontlen = p->head + 1;//head 앞에 남은 자리의 개수
		remainlen = frontlen + rearlen;//큐에 남은 자리의 총 개수

		if (enlen > rearlen) {//enlen보다 tail 뒤의 자리가 부족할 때(ex. 4개 넣고 싶은데 tail 뒤에 3자리밖에 없을 때)
			if (enlen > remainlen)//enlen보다 remainlen이 부족할 때
				printf("큐에 남은 자리가 부족합니다. 남은 자리는 %d개입니다.\n", remainlen);
			else {//남은 자리의 총 개수가 모자르지 않을 때
				Shift(array, p);//앞에 빈자리가 없도록 큐 정렬

				for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
					array[p->tail + 1 + i] = temp_array[i];
				}

				p->tail += strlen(temp_array);
			}
		}

		else {//큐에 자리가 넉넉할 때
			for (i = 0; i < strlen(temp_array); i++) {//tail 뒤에 입력받은 것들 넣음
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}

	return exist;
}

void Replace(char order[], char array[], Position* p)//tail 요소 변경 함수
{
	if (is_empty(p) != 1)
		array[p->tail] = order[1];
}

void Clear(char array[], char order[], Position* p)//큐 비우기 함수
{
	while (p->head != p->tail) {
		Dequeue(array, order, p);
	}
	printf("\n");

	Positioninit(p);
}

int Z(Position* p)//tail 뒤에 남은 자리의 개수
{
	int rearlen = Max_Size - p->tail - 2;
	return rearlen;
}

void Reverse(char array[], Position* p)//뒤집고 출력 함수
{
	char temp[Max_Size] = { '\0' };
	int savehead = p->head;//원래의 head위치 저장
	int i = 0;

	if (is_empty(p) == 1)//큐가 비었으면
		printf("뒤집을 것이 없음\n");

	else {//큐에 저장된 것이 있는 경우
		while (p->head != p->tail)
		{
			p->head++;
			temp[i] = array[p->head];
			i++;
		}
		p->head = savehead;//head를 원래대로

		int cnt = strlen(temp);
		char tmp;//단어 하나를 임시로 저장할 변수

		for (i = 0; i < cnt / 2; i++) {// 교환이 중복되지 않기 위해 cnt/2까지 반복함
			tmp = temp[i];
			temp[i] = temp[cnt - 1 - i];
			temp[cnt - 1 - i] = tmp;
		}// 0번과 끝번, 1번과 끝-1번...순으로 교환함

		printf("%s\n", temp);
	}
}

int main() {
	char array[Max_Size] = { '\0', };
	char order[30];
	Position position;

	Positioninit(&position);

	UserSetting();

	while (1) {

		printf("order : ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("프로그램을 종료합니다.\n");
			break;
		}//escape code

		if (order[0] == '+') {
			Enqueue(array, order, &position);
		}

		if (order[0] == 'L') {
			PrintAll(array, &position);
		}

		if (order[0] == 'P') {
			Peek(array, &position);
		}

		if (order[0] == '-') {
			Dequeue(array, order, &position);
			printf("\n");
		}

		if (order[0] == 'F') {
			if (is_full(&position) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == '#') {
			printf("%d\n", DataCount(&position));
		}

		if (order[0] == 'H') {
			printf("%d\n", Head(&position));
		}

		if (order[0] == 'T') {
			printf("%d\n", Tail(&position));
		}

		if (order[0] == 'E') {
			if (is_empty(&position) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == '?') {
			if (is_member(array, order, &position) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == '=') {
			Replace(order, array, &position);
		}

		if (order[0] == 'C') {
			Clear(array, order, &position);
		}

		if (order[0] == 'S') {
			Shift(array, &position);
		}

		if (order[0] == 'Z') {
			printf("%d\n", Z(&position));
		}

		if (order[0] == 'R') {
			Reverse(array, &position);
		}
	}

	system("pause");
	return 0;
}