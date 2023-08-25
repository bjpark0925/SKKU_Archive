#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>//문자열 길이, 복사
#include<stdlib.h>//동적 메모리
#include<stdbool.h>//true, false

typedef struct _node//노드 하나를 위한 구조체
{
	int data;
	struct _node* next;

}Node;

typedef struct _linkedList//리스트 전체를 위한 구조체
{
	Node* head;
	Node* cur;
	Node* newNode;
	Node* before;
	Node* temp;
	int cnt;

}List;

void ListInit(List* plist)//리스트의 초기 상태
{
	plist->head = (Node*)malloc(sizeof(Node));//head 다음에 더미노드 생성
	plist->head->next = NULL;
	plist->cur = plist->head;//처음은 head와 cur가 모두 더미노드를 가리킴

	plist->newNode = NULL;//나중에 쓰일 것들 초기화
	plist->before = NULL;
	plist->temp = NULL;
	plist->cnt = 0;
}

void UserSetting()
{
	printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
	printf("명령어 : Q, +, L, G, <N, >P, -, #, =, ?, C, E, WN, RL, S\n\n");
	printf("Q : 프로그램 종료\n");
	printf("+: 삽입 명령(+만 입력 후 엔터하여 하나의 요소(정수)만 삽입 가능 주의)\n");
	printf("L : 리스트 전체 출력\n");
	printf("G : 현재 위치의 요소 출력\n");
	printf("<N : 현재 위치를 앞에서부터 변경(N의 개수는 마음대로)\n");
	printf(">P : 현재 위치를 뒤에서부터 변경(P의 개수는 마음대로)\n");
	printf("- : 현재 위치의 요소 삭제 명령\n");
	printf(">- : 마지막 요소 삭제 명령(따로 함수를 작성하지 않고 Delete명령을 이용함)\n");
	printf("# : 리스트 요소 개수 확인\n");
	printf("=71 : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경(71이 아니어도 됨)\n");
	printf("?찾을요소(정수) : 찾기 명령\n");
	printf("C : 리스트 전체 비우기\n");
	printf("E : 빈 리스트인지 확인\n\n");
	printf("[이 밑으로는 새로운 기능]\n");
	printf("WN : 현재 위치의 요소를 뒤의 요소와 위치 바꾸기\n");
	printf("RL : 리스트 거꾸로 출력(연결리스트의 연결 상태는 변하지 않음)\n");
	printf("S : 리스트에 들어있는 전체 요소 개수와 같은 숫자를 가진 요소가 있는지 찾기\n\n");

}

void DataInsert(List* plist)//삽입 함수
{
	int insertData;

	printf("삽입할 요소를 하나만 입력하세요(정수): ");
	scanf("%d", &insertData);

	plist->newNode = (Node*)malloc(sizeof(Node));
	plist->newNode->data = insertData;

	//cur와 cur->next사이에 newNode가 추가되는 과정, 중요!!
	plist->newNode->next = plist->cur->next;
	plist->cur->next = plist->newNode;
	plist->before = plist->cur;//삭제 함수를 위해 미리 before의 위치를 설정함
	plist->cur = plist->newNode;
	//
	plist->cnt = (plist->cnt) + 1;//cnt++
}

void PrintAll(List* plist)//데이터 전부 조회
{
	plist->temp = plist->cur;

	if (plist->head == plist->cur)
		printf("저장된 것이 없음\n");
	else {
		plist->cur = plist->head;

		while (plist->cur->next != NULL) {
			plist->cur = plist->cur->next;
			printf("%d ", plist->cur->data);
		}
		printf("\n");
	}
	plist->cur = plist->temp;
	plist->temp = NULL;
}

void GetData(List* plist)//현재 위치의 요소 출력
{
	printf("%d\n", plist->cur->data);
}

void Traverse_front(List* plist, char order[])//앞에서부터 traverse
{
	int nullcnt = (plist->cnt) - 1;//cur가 첫번째 요소에 있을 때, 끝 요소에 도달하기까지 몇번 이동해야 하는가=nullcnt
	int ncnt = 0;

	plist->cur = plist->head->next;//cur과 before를 맨앞으로
	plist->before = plist->head;

	for (int i = 1; i < strlen(order); i++) {//N의 개수 계산
		if (order[i] == 'N') {
			ncnt = ncnt + 1;
		}
	}

	if (ncnt > nullcnt) {
		printf("연결 리스트에서 현재 위치를 나타낼 수 없습니다. 현재 위치를 처음으로 합니다.\n");
		plist->cur = plist->head->next;
		plist->before = plist->head;
	}
	else {
		for (int i = 0; i < ncnt; i++) {//사용자가 쓴 N만큼 cur가 이동
			plist->cur = plist->cur->next;
			plist->before = plist->before->next;
		}
	}
}

void Traverse_rear(List* plist, char order[])//뒤에서부터 traverse
{
	int nullcnt = (plist->cnt) - 1;//cur가 첫번째 요소에 있을 때, 끝 요소에 도달하기까지 몇번 이동해야 하는가=nullcnt
	int pcnt = 0;
	int minus;

	plist->cur = plist->head->next;//cur과 before를 맨앞으로
	plist->before = plist->head;

	for (int i = 1; i < strlen(order); i++) {//P의 개수 계산
		if (order[i] == 'P') {
			pcnt = pcnt + 1;
		}
	}

	plist->cur = plist->head->next;//cur을 다시 첫번째 노드로

	minus = nullcnt - pcnt;

	if (minus > nullcnt) {
		printf("연결 리스트에서 현재 위치를 나타낼 수 없습니다. 현재 위치를 처음으로 합니다.\n");
		plist->cur = plist->head->next;
		plist->before = plist->head;
	}
	else {//nullcnt-pcnt를 한 횟수동안 cur과 before는 계속해서 옆으로 이동(뒤에서 앞으로 이동이 불가능하므로)
		for (int i = 0; i < minus; i++) {
			plist->cur = plist->cur->next;
			plist->before = plist->before->next;
		}
	}
}

void Delete(List* plist)//데이터 삭제
{
	if (plist->cur->next == NULL) {//삭제할 노드가 마지막인 경우
		plist->before->next = NULL;
		free(plist->cur);

		plist->cur = plist->head->next;//현재 위치를 더미 노드 다음으로
		plist->before = plist->head;//before는 더미 노드로
		plist->cnt = (plist->cnt) - 1;//cnt--
	}

	else {//마지막 노드가 아닌 경우
		plist->before->next = plist->cur->next;//before위치는 가만히 있고, 가리키는 곳만 바꿈
		free(plist->cur);

		plist->cur = plist->before->next;//잃어버린 cur의 위치를 before 다음으로 새로 지정
		plist->cnt = (plist->cnt) - 1;//cnt--
	}
}

void DataCount(List* plist)//리스트 요소의 총 개수
{
	printf("%d\n", plist->cnt);
}

void Replace(List* plist, char order[])//현재 위치의 요소 바꾸기
{
	char s1[30];
	int num;

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//예를 들어 사용자가 =71을 입력했으면, 71을 s1에 문자 형태로 저장
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);//71을 숫자로 변환

	if (num != 0) {//=이후 사용자가 정수를 입력한 경우
		plist->cur->data = num;
	}
	else {
		printf("입력 형식이 올바르지 않음\n");
	}
}

void isMember(List* plist, char order[])//요소의 존재 여부
{
	char s1[30];
	int num;

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//예를 들어 사용자가 =71을 입력했으면, 71을 s1에 문자 형태로 저장
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);//71을 숫자로 변환


	int index = 1;
	int remember_index;
	bool exist = false;

	plist->temp = plist->cur;//현재 위치를 temp로 저장

	plist->cur = plist->head;//처음부터 끝까지 순회를 위해 cur를 head로 설정

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
		if (plist->cur->data == num) {
			exist = true;
			remember_index = index;
		}
		index++;
	}

	if (exist == true)
		printf("%d는 인간 인덱스 번호 기준 %d번에 있습니다.\n", num, remember_index);
	else
		printf("찾고자 하는 %d를 찾지 못했습니다.\n", num);

	plist->cur = plist->temp;//cur은 다시 현재 위치로 돌아감
	plist->temp = NULL;

}

void Clear(List* plist) {//데이터 전체 삭제

	if (plist->cnt == 0) {
		printf("이미 빈 리스트입니다.\n");
	}
	else {
		plist->before = plist->head;
		plist->cur = plist->head->next;

		while (plist->cur->next != NULL) {
			plist->before->next = plist->cur->next;
			free(plist->cur);

			plist->cur = plist->before->next;
		}

		//이후 초기 상황과 똑같이 조성

		plist->head->next = NULL;
		plist->cur = plist->head;//처음은 head와 cur가 모두 더미노드를 가리킴

		plist->newNode = NULL;//나중에 쓰일 것들 초기화
		plist->before = NULL;
		plist->cnt = 0;
	}

	//밑에걸로도 해봤는데 잘 안되네요.
	/*
	for (int i = 0; i < plist->cnt; i++) {
		Delete(plist);
	}
	*/
}

void isEmpty(List* plist) {//빈 리스트 여부
	if (plist->cnt == 0) {
		printf("리스트가 비어있음\n");
	}
	else
		printf("리스트가 비어있지 않음\n");
}

void NSwap(List* plist) {//현재 위치의 노드와 바로 뒤에 있는 노드의 위치 변경
	if (plist->cur->next == NULL) {
		printf("현재 위치의 요소를 다음 위치의 요소와 swap할 수 없습니다.\n");
	}
	else {
		plist->before->next = plist->cur->next;
		plist->cur->next = plist->cur->next->next;
		plist->before->next->next = plist->cur;
	}
}

void ReversePrintAll(List* plist)//리스트 전체 거꾸로 출력
{
	int array[50];

	plist->temp = plist->cur;

	if (plist->head == plist->cur)
		printf("저장된 것이 없음\n");
	else {
		plist->cur = plist->head;

		for (int i = 0; i < plist->cnt; i++) {
			plist->cur = plist->cur->next;
			array[(plist->cnt) -1 - i] = plist->cur->data;
		}
		for (int i = 0; i < plist->cnt; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}

	plist->cur = plist->temp;
	plist->temp = NULL;

}

void isSameCountData(List* plist)//리스트에 들어있는 전체 요소 개수와 같은 숫자를 가진 요소가 있는지 여부
{
	int index = 1;
	int remember_index;
	bool exist = false;

	if (plist->head == plist->cur)
		printf("저장된 것이 없음\n");

	plist->temp = plist->cur;//현재 위치를 temp로 저장

	plist->cur = plist->head;//처음부터 끝까지 순회를 위해 cur를 head로 설정

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
		if (plist->cur->data == plist->cnt) {
			exist = true;
			remember_index = index;
		}
		index++;
	}

	if (exist == true)
		printf("리스트의 전체 개수인 %d는 인간 인덱스 번호 기준 %d번에 있습니다.\n", plist->cnt, remember_index);
	else
		printf("리스트의 전체 개수와 같은 요소가 없습니다.\n");

	plist->cur = plist->temp;//cur은 다시 현재 위치로 돌아감
	plist->temp = NULL;
}

int main()
{
	List list;
	ListInit(&list);

	char order[30];

	UserSetting();

	while (1)
	{
		printf("order: ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("프로그램을 종료합니다.\n");
			break;
		}//escape code

		if (order[0] == '+') {//삽입
			DataInsert(&list);
		}

		if (order[0] == 'L') {//전체 출력
			PrintAll(&list);
		}

		if (order[0] == 'G') {//현재 위치 요소 얻기
			GetData(&list);
		}

		if (order[0] == '<') {//앞에서부터 순회
			Traverse_front(&list, order);
		}

		if (order[0] == '>') {//뒤에서부터 순회
			Traverse_rear(&list, order);
			if (order[1] == '-')//>-입력 시 마지막 요소 삭제
				Delete(&list);
		}

		if (order[0] == '-') {//데이터 삭제
			Delete(&list);
		}

		if (order[0] == '#') {//전체 요소 개수
			DataCount(&list);
		}

		if (order[0] == '=') {//현재 위치 요소 바꾸기
			Replace(&list, order);
		}

		if (order[0] == '?') {//찾기
			isMember(&list, order);
		}

		if (order[0] == 'C') {//전체 삭제
			Clear(&list);
		}
		if (order[0] == 'E') {//빈 리스트 여부
			isEmpty(&list);
		}

		if (strcmp(order,"WN")==0) {//현재 위치의 노드와 바로 뒤에 있는 노드의 위치 변경
			NSwap(&list);
		}

		if (strcmp(order, "RL") == 0) {//리스트 전체 거꾸로 출력
			ReversePrintAll(&list);
		}

		if (order[0] == 'S') {//리스트에 들어있는 전체 요소 개수와 같은 숫자를 가진 요소가 있는지 찾기
			isSameCountData(&list);
		}
	}
	printf("\n");

	system("pause");

	return 0;
}