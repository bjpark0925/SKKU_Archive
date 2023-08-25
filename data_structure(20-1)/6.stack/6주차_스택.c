#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//문자열 길이, 복사 위한 헤더
#include<stdbool.h>//true, false

#define Max_Size 30 // 스택의 크기를 30으로 static하게 설정(마지막은 '\0'가 있어야 하므로 실질적 크기는 29)

void UserSetting()
{
	printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n\n");
	printf("+abcd : push 명령(push할 요소는 마음대로)\n");
	printf("L : 스택 전체 출력\n");
	printf("P : top 위치의 요소 peek(보기)\n");
	printf("- : top 위치의 하나만 요소 pop(꺼내기)\n");
	printf("-5 : top 위치의 요소부터 5개까지를 pop(5가 아니어도 됨)\n");
	printf("F : 스택이 꽉 찼는지 여부\n");
	printf("# : 스택 요소 개수 확인\n");
	printf("T : top 위치의 요소 출력\n");
	printf("?a : 스택에 요소가 있는지 여부(a가 아니어도 됨)\n");
	printf("=a : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경(a가 아니어도 됨)\n");
	printf("C : 스택 비우기(요소들 보여주면서 비워짐)\n");
	printf("Q : 프로그램 종료\n\n");
	printf("밑의 3개는 자신만의 기능\n");
	printf("E : 빈 스택 여부\n");
	printf("SW : top과 top-1요소를 swap\n");
	printf("R : 스택의 순서를 top부터 reverse해서 출력\n\n");
}
int Setposition()//top의 처음 위치 설정
{
	return -1;//스택에 아무것도 들어있지 않을 때, top은 -1
}

int Push(char array[], char order[], int top)//push함수
{
	char temp_array[30];
	int pushlen, remainlen;

	int i;

	for (i = 0; i < strlen(order) - 1; i++) {//+abcd를 temp_array에 abcd로 저장
		temp_array[i] = order[i + 1];
	}
	temp_array[strlen(order) - 1] = '\0';

	pushlen = strlen(temp_array);//사용자가 넣고 싶은 요소의 개수(ex.abcd면 4개)
	remainlen = Max_Size - top - 2;//스택에 남은 자리의 개수

	if (pushlen > remainlen) {//pushlen보다 남은 자리가 부족할 때(ex. 4개 넣고 싶은데 3자리밖에 없을 때)
		printf("스택에 남은 자리가 부족합니다. 남은 자리는 %d개입니다.\n", remainlen);
	}

	else {//스택에 자리가 넉넉할 때
		for (i = 0; i < strlen(temp_array); i++) {//top 뒤에 입력받은 것들 넣음
			array[top + 1 + i] = temp_array[i];
		}

		top += strlen(temp_array);
	}

	return top;
}

void PrintAll(char array[], int top)//스택 전체 출력 함수
{
	char temp[Max_Size] = { '\0' };
	int savetop = top;//원래의 top위치 저장

	if (top == -1)//스택에 저장된 것이 없는 경우
		printf("출력할 것이 없음\n");

	else {//스택에 저장된 것이 있는 경우
		for (int i = 0; i <= savetop; i++) {//temp는 array와 반대로 저장, array는 초기화
			temp[i] = array[top];
			array[top] = '\0';
			top--;
		}
		top = savetop;//top을 다시 원래의 위치로 업데이트

		for (int i = 0; i <= savetop; i++) {//temp에서 다시 array로 저장하며 요소 하나하나에 접근
			array[i] = temp[top - i];
			printf("%c", array[i]);
		}
		array[savetop + 1] = '\0';
		printf("\n");


		top = savetop;
	}
}

void Peek(char array[], int top)//top에 있는 것을 출력하는 peek함수
{
	if (top == -1)//스택에 저장된 것이 없는 경우
		printf("peek할 것이 없음\n");
	else//스택에 저장된 것이 있는 경우
		printf("%c\n", array[top]);
}

int Pop(char array[], char order[], int top)//pop함수(한번에 하나씩만 꺼낼 수도, 숫자를 이용해 여러 개 꺼낼 수도 있음)
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
			if (num > top + 1)
				printf("입력한 숫자가 스택 전체의 개수보다 많습니다. 다시 입력하세요\n");
			else {
				for (int i = 0; i < num; i++) {
					Peek(array, top);//peek하고
					array[top] = '\0';//삭제
					top--;//top위치 변경
				}
			}
		}
	}

	else {//-만 입력받은 경우
		if (top == -1)//스택에 저장된 것이 없는 경우
			printf("pop할 것이 없음\n");

		else {//스택에 저장된 것이 있는 경우
			Peek(array, top);//peek하고
			array[top] = '\0';//삭제
			top--;//top위치 변경
		}
	}

	return top;
}

void is_full(char array[], int top)//스택 가득 찼는지 여부 함수
{
	if (top == Max_Size - 2)
		printf("가득 참\n");
	else
		printf("가득 차있지 않음\n");
}

void element_count(int top)//스택 요소 개수 확인 함수
{
	int cnt = top + 1;

	printf("%d\n", cnt);
}

void Top(char array[], int top)//top 위치의 요소 출력 함수
{
	if (top == -1)
		printf("top 위치에 요소가 없음\n");
	else
		printf("(%d, %c)\n", top + 1, array[top]);
}

void is_member(char array[], char order[], int top)//스택에 요소가 있는지 여부 함수
{
	char temp[Max_Size] = { '\0' };
	bool exist = false;//요소 존재 여부 확인하는 변수
	int savetop = top;//원래의 top위치 저장

	if (top == -1)//스택에 저장된 것이 없는 경우
		printf("False\n");

	else {//스택에 저장된 것이 있는 경우
		for (int i = 0; i <= savetop; i++) {//temp는 array와 반대로 저장, 저장과 동시에 search하기
			temp[i] = array[top];

			if (temp[i] == order[1])
				exist = true;

			array[top] = '\0';
			top--;
		}

		if (exist == true)
			printf("True\n");
		else
			printf("False\n");

		top = savetop;//top을 다시 원래의 위치로 업데이트

		for (int i = 0; i <= savetop; i++) {//temp에 저장한 것을 다시 array로
			array[i] = temp[top - i];
		}
	}
}

void Replace(char order[], char array[], int top)//top 요소 변경 함수
{
	if (top != -1)
		array[top] = order[1];
}

int Clear(char array[], char order[], int top)//스택 비우기 함수
{
	int savetop = top;

	for (int i = 0; i <= savetop; i++) {
		top = Pop(array, order, top);
	}

	return top;
}

void is_empty(int top)//빈 스택 여부 함수
{
	if (top == -1)
		printf("True(스택이 비어있음)\n");
	else
		printf("False(스택이 비어있지 않음)\n");
}

void Swap(char array[], int top)//top과 top-1요소를 swap 후 출력 함수
{
	char temp1[2] = { '\0', };
	char temp2[2] = { '\0', };
	int savetop = top;

	if (top < 1)
		printf("Swap할 요소가 부족함\n");

	else {
		temp1[0] = array[top];
		array[top] = '\0';
		top--;

		temp2[0] = array[top];
		array[top] = '\0';
		top--;

		array[top + 1] = temp1[0];
		array[top + 2] = temp2[0];
		top = savetop;

		PrintAll(array, top);
	}
}

void ReverseStack(char array[], int top)//뒤집고 출력 함수
{
	char temp[Max_Size] = { '\0' };
	int savetop = top;//원래의 top위치 저장

	if (top == -1)//스택에 저장된 것이 없는 경우
		printf("뒤집을 것이 없음\n");

	else {//스택에 저장된 것이 있는 경우
		for (int i = 0; i <= savetop; i++) {//array의 top요소가 temp로 넘어감.
			temp[i] = array[top];
			printf("%c", array[top]); //넘어가는 요소 하나하나를 출력함
			array[top] = '\0';
			top--;
		}
		top = savetop;//top을 다시 원래의 위치로 업데이트

		for (int i = 0; i <= savetop; i++) {//temp에서 다시 array로 저장
			array[i] = temp[top - i];
		}
		array[savetop + 1] = '\0';
		printf("\n");

		top = savetop;
	}
}

int main() {
	char array[Max_Size] = { '\0', };
	char order[30];
	int top = Setposition();

	UserSetting();

	while (1) {

		printf("order : ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("프로그램을 종료합니다.\n");
			break;
		}//escape code

		if (order[0] == '+') {
			top = Push(array, order, top);
		}

		if (order[0] == 'L') {
			PrintAll(array, top);
		}

		if (order[0] == 'P') {
			Peek(array, top);
		}

		if (order[0] == '-') {
			top = Pop(array, order, top);
		}

		if (order[0] == 'F') {
			is_full(array, top);
		}

		if (order[0] == '#') {
			element_count(top);
		}

		if (order[0] == 'T') {
			Top(array, top);
		}

		if (order[0] == '?') {
			is_member(array, order, top);
		}

		if (order[0] == '=') {
			Replace(order, array, top);
		}

		if (order[0] == 'C') {
			top = Clear(array, order, top);
		}

		if (order[0] == 'E') {
			is_empty(top);
		}

		if (strcmp(order, "SW") == 0) {
			Swap(array, top);
		}

		if (order[0] == 'R') {
			ReverseStack(array, top);
		}
	}

	system("pause");

	return 0;
}