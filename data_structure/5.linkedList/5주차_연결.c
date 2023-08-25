#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>//���ڿ� ����, ����
#include<stdlib.h>//���� �޸�
#include<stdbool.h>//true, false

typedef struct _node//��� �ϳ��� ���� ����ü
{
	int data;
	struct _node* next;

}Node;

typedef struct _linkedList//����Ʈ ��ü�� ���� ����ü
{
	Node* head;
	Node* cur;
	Node* newNode;
	Node* before;
	Node* temp;
	int cnt;

}List;

void ListInit(List* plist)//����Ʈ�� �ʱ� ����
{
	plist->head = (Node*)malloc(sizeof(Node));//head ������ ���̳�� ����
	plist->head->next = NULL;
	plist->cur = plist->head;//ó���� head�� cur�� ��� ���̳�带 ����Ŵ

	plist->newNode = NULL;//���߿� ���� �͵� �ʱ�ȭ
	plist->before = NULL;
	plist->temp = NULL;
	plist->cnt = 0;
}

void UserSetting()
{
	printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
	printf("��ɾ� : Q, +, L, G, <N, >P, -, #, =, ?, C, E, WN, RL, S\n\n");
	printf("Q : ���α׷� ����\n");
	printf("+: ���� ���(+�� �Է� �� �����Ͽ� �ϳ��� ���(����)�� ���� ���� ����)\n");
	printf("L : ����Ʈ ��ü ���\n");
	printf("G : ���� ��ġ�� ��� ���\n");
	printf("<N : ���� ��ġ�� �տ������� ����(N�� ������ �������)\n");
	printf(">P : ���� ��ġ�� �ڿ������� ����(P�� ������ �������)\n");
	printf("- : ���� ��ġ�� ��� ���� ���\n");
	printf(">- : ������ ��� ���� ���(���� �Լ��� �ۼ����� �ʰ� Delete����� �̿���)\n");
	printf("# : ����Ʈ ��� ���� Ȯ��\n");
	printf("=71 : ���� ��ġ�� �ִ� ��Ҹ� ����ڰ� �Է��� ��ҷ� ����(71�� �ƴϾ ��)\n");
	printf("?ã�����(����) : ã�� ���\n");
	printf("C : ����Ʈ ��ü ����\n");
	printf("E : �� ����Ʈ���� Ȯ��\n\n");
	printf("[�� �����δ� ���ο� ���]\n");
	printf("WN : ���� ��ġ�� ��Ҹ� ���� ��ҿ� ��ġ �ٲٱ�\n");
	printf("RL : ����Ʈ �Ųٷ� ���(���Ḯ��Ʈ�� ���� ���´� ������ ����)\n");
	printf("S : ����Ʈ�� ����ִ� ��ü ��� ������ ���� ���ڸ� ���� ��Ұ� �ִ��� ã��\n\n");

}

void DataInsert(List* plist)//���� �Լ�
{
	int insertData;

	printf("������ ��Ҹ� �ϳ��� �Է��ϼ���(����): ");
	scanf("%d", &insertData);

	plist->newNode = (Node*)malloc(sizeof(Node));
	plist->newNode->data = insertData;

	//cur�� cur->next���̿� newNode�� �߰��Ǵ� ����, �߿�!!
	plist->newNode->next = plist->cur->next;
	plist->cur->next = plist->newNode;
	plist->before = plist->cur;//���� �Լ��� ���� �̸� before�� ��ġ�� ������
	plist->cur = plist->newNode;
	//
	plist->cnt = (plist->cnt) + 1;//cnt++
}

void PrintAll(List* plist)//������ ���� ��ȸ
{
	plist->temp = plist->cur;

	if (plist->head == plist->cur)
		printf("����� ���� ����\n");
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

void GetData(List* plist)//���� ��ġ�� ��� ���
{
	printf("%d\n", plist->cur->data);
}

void Traverse_front(List* plist, char order[])//�տ������� traverse
{
	int nullcnt = (plist->cnt) - 1;//cur�� ù��° ��ҿ� ���� ��, �� ��ҿ� �����ϱ���� ��� �̵��ؾ� �ϴ°�=nullcnt
	int ncnt = 0;

	plist->cur = plist->head->next;//cur�� before�� �Ǿ�����
	plist->before = plist->head;

	for (int i = 1; i < strlen(order); i++) {//N�� ���� ���
		if (order[i] == 'N') {
			ncnt = ncnt + 1;
		}
	}

	if (ncnt > nullcnt) {
		printf("���� ����Ʈ���� ���� ��ġ�� ��Ÿ�� �� �����ϴ�. ���� ��ġ�� ó������ �մϴ�.\n");
		plist->cur = plist->head->next;
		plist->before = plist->head;
	}
	else {
		for (int i = 0; i < ncnt; i++) {//����ڰ� �� N��ŭ cur�� �̵�
			plist->cur = plist->cur->next;
			plist->before = plist->before->next;
		}
	}
}

void Traverse_rear(List* plist, char order[])//�ڿ������� traverse
{
	int nullcnt = (plist->cnt) - 1;//cur�� ù��° ��ҿ� ���� ��, �� ��ҿ� �����ϱ���� ��� �̵��ؾ� �ϴ°�=nullcnt
	int pcnt = 0;
	int minus;

	plist->cur = plist->head->next;//cur�� before�� �Ǿ�����
	plist->before = plist->head;

	for (int i = 1; i < strlen(order); i++) {//P�� ���� ���
		if (order[i] == 'P') {
			pcnt = pcnt + 1;
		}
	}

	plist->cur = plist->head->next;//cur�� �ٽ� ù��° ����

	minus = nullcnt - pcnt;

	if (minus > nullcnt) {
		printf("���� ����Ʈ���� ���� ��ġ�� ��Ÿ�� �� �����ϴ�. ���� ��ġ�� ó������ �մϴ�.\n");
		plist->cur = plist->head->next;
		plist->before = plist->head;
	}
	else {//nullcnt-pcnt�� �� Ƚ������ cur�� before�� ����ؼ� ������ �̵�(�ڿ��� ������ �̵��� �Ұ����ϹǷ�)
		for (int i = 0; i < minus; i++) {
			plist->cur = plist->cur->next;
			plist->before = plist->before->next;
		}
	}
}

void Delete(List* plist)//������ ����
{
	if (plist->cur->next == NULL) {//������ ��尡 �������� ���
		plist->before->next = NULL;
		free(plist->cur);

		plist->cur = plist->head->next;//���� ��ġ�� ���� ��� ��������
		plist->before = plist->head;//before�� ���� ����
		plist->cnt = (plist->cnt) - 1;//cnt--
	}

	else {//������ ��尡 �ƴ� ���
		plist->before->next = plist->cur->next;//before��ġ�� ������ �ְ�, ����Ű�� ���� �ٲ�
		free(plist->cur);

		plist->cur = plist->before->next;//�Ҿ���� cur�� ��ġ�� before �������� ���� ����
		plist->cnt = (plist->cnt) - 1;//cnt--
	}
}

void DataCount(List* plist)//����Ʈ ����� �� ����
{
	printf("%d\n", plist->cnt);
}

void Replace(List* plist, char order[])//���� ��ġ�� ��� �ٲٱ�
{
	char s1[30];
	int num;

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//���� ��� ����ڰ� =71�� �Է�������, 71�� s1�� ���� ���·� ����
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);//71�� ���ڷ� ��ȯ

	if (num != 0) {//=���� ����ڰ� ������ �Է��� ���
		plist->cur->data = num;
	}
	else {
		printf("�Է� ������ �ùٸ��� ����\n");
	}
}

void isMember(List* plist, char order[])//����� ���� ����
{
	char s1[30];
	int num;

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//���� ��� ����ڰ� =71�� �Է�������, 71�� s1�� ���� ���·� ����
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);//71�� ���ڷ� ��ȯ


	int index = 1;
	int remember_index;
	bool exist = false;

	plist->temp = plist->cur;//���� ��ġ�� temp�� ����

	plist->cur = plist->head;//ó������ ������ ��ȸ�� ���� cur�� head�� ����

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
		if (plist->cur->data == num) {
			exist = true;
			remember_index = index;
		}
		index++;
	}

	if (exist == true)
		printf("%d�� �ΰ� �ε��� ��ȣ ���� %d���� �ֽ��ϴ�.\n", num, remember_index);
	else
		printf("ã���� �ϴ� %d�� ã�� ���߽��ϴ�.\n", num);

	plist->cur = plist->temp;//cur�� �ٽ� ���� ��ġ�� ���ư�
	plist->temp = NULL;

}

void Clear(List* plist) {//������ ��ü ����

	if (plist->cnt == 0) {
		printf("�̹� �� ����Ʈ�Դϴ�.\n");
	}
	else {
		plist->before = plist->head;
		plist->cur = plist->head->next;

		while (plist->cur->next != NULL) {
			plist->before->next = plist->cur->next;
			free(plist->cur);

			plist->cur = plist->before->next;
		}

		//���� �ʱ� ��Ȳ�� �Ȱ��� ����

		plist->head->next = NULL;
		plist->cur = plist->head;//ó���� head�� cur�� ��� ���̳�带 ����Ŵ

		plist->newNode = NULL;//���߿� ���� �͵� �ʱ�ȭ
		plist->before = NULL;
		plist->cnt = 0;
	}

	//�ؿ��ɷε� �غôµ� �� �ȵǳ׿�.
	/*
	for (int i = 0; i < plist->cnt; i++) {
		Delete(plist);
	}
	*/
}

void isEmpty(List* plist) {//�� ����Ʈ ����
	if (plist->cnt == 0) {
		printf("����Ʈ�� �������\n");
	}
	else
		printf("����Ʈ�� ������� ����\n");
}

void NSwap(List* plist) {//���� ��ġ�� ���� �ٷ� �ڿ� �ִ� ����� ��ġ ����
	if (plist->cur->next == NULL) {
		printf("���� ��ġ�� ��Ҹ� ���� ��ġ�� ��ҿ� swap�� �� �����ϴ�.\n");
	}
	else {
		plist->before->next = plist->cur->next;
		plist->cur->next = plist->cur->next->next;
		plist->before->next->next = plist->cur;
	}
}

void ReversePrintAll(List* plist)//����Ʈ ��ü �Ųٷ� ���
{
	int array[50];

	plist->temp = plist->cur;

	if (plist->head == plist->cur)
		printf("����� ���� ����\n");
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

void isSameCountData(List* plist)//����Ʈ�� ����ִ� ��ü ��� ������ ���� ���ڸ� ���� ��Ұ� �ִ��� ����
{
	int index = 1;
	int remember_index;
	bool exist = false;

	if (plist->head == plist->cur)
		printf("����� ���� ����\n");

	plist->temp = plist->cur;//���� ��ġ�� temp�� ����

	plist->cur = plist->head;//ó������ ������ ��ȸ�� ���� cur�� head�� ����

	while (plist->cur->next != NULL) {
		plist->cur = plist->cur->next;
		if (plist->cur->data == plist->cnt) {
			exist = true;
			remember_index = index;
		}
		index++;
	}

	if (exist == true)
		printf("����Ʈ�� ��ü ������ %d�� �ΰ� �ε��� ��ȣ ���� %d���� �ֽ��ϴ�.\n", plist->cnt, remember_index);
	else
		printf("����Ʈ�� ��ü ������ ���� ��Ұ� �����ϴ�.\n");

	plist->cur = plist->temp;//cur�� �ٽ� ���� ��ġ�� ���ư�
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		}//escape code

		if (order[0] == '+') {//����
			DataInsert(&list);
		}

		if (order[0] == 'L') {//��ü ���
			PrintAll(&list);
		}

		if (order[0] == 'G') {//���� ��ġ ��� ���
			GetData(&list);
		}

		if (order[0] == '<') {//�տ������� ��ȸ
			Traverse_front(&list, order);
		}

		if (order[0] == '>') {//�ڿ������� ��ȸ
			Traverse_rear(&list, order);
			if (order[1] == '-')//>-�Է� �� ������ ��� ����
				Delete(&list);
		}

		if (order[0] == '-') {//������ ����
			Delete(&list);
		}

		if (order[0] == '#') {//��ü ��� ����
			DataCount(&list);
		}

		if (order[0] == '=') {//���� ��ġ ��� �ٲٱ�
			Replace(&list, order);
		}

		if (order[0] == '?') {//ã��
			isMember(&list, order);
		}

		if (order[0] == 'C') {//��ü ����
			Clear(&list);
		}
		if (order[0] == 'E') {//�� ����Ʈ ����
			isEmpty(&list);
		}

		if (strcmp(order,"WN")==0) {//���� ��ġ�� ���� �ٷ� �ڿ� �ִ� ����� ��ġ ����
			NSwap(&list);
		}

		if (strcmp(order, "RL") == 0) {//����Ʈ ��ü �Ųٷ� ���
			ReversePrintAll(&list);
		}

		if (order[0] == 'S') {//����Ʈ�� ����ִ� ��ü ��� ������ ���� ���ڸ� ���� ��Ұ� �ִ��� ã��
			isSameCountData(&list);
		}
	}
	printf("\n");

	system("pause");

	return 0;
}