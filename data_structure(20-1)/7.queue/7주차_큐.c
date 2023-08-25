#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//���ڿ� ����, ���� ���� ���
#include<stdbool.h>//true, false

#define Max_Size 30 // ť�� ũ�⸦ 30���� static�ϰ� ����(�������� '\0'�� �־�� �ϹǷ� ������ ũ��� 29)

void UserSetting()
{
	printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n\n");
	printf("+abcd : enqueue ���(enqueue�� ��Ҵ� �������)\n");
	printf("L : ť ��ü ���\n");
	printf("P : head ��ġ�� ��� peek(����)\n");
	printf("- : head ��ġ�� ��� �ϳ��� dequeue ���\n");
	printf("-5 : head ��ġ�� ��Һ��� 5������ dequeue(5�� �ƴϾ ��)\n");
	printf("F : ť�� �� á���� ����\n");
	printf("# : ť ��� ���� Ȯ��\n");
	printf("H : head�� ���� ��ġ ���\n");
	printf("T : tail�� ���� ��ġ ���\n");
	printf("E : �� ť ����\n");
	printf("?a : ť�� ��Ұ� �ִ��� ����(a�� �ƴϾ ��)\n");
	printf("=a : tail ��ġ�� �ִ� ��Ҹ� ����ڰ� �Է��� ��ҷ� ����(a�� �ƴϾ ��)\n");
	printf("C : ť ����(��ҵ� �����ָ鼭 �����)\n");
	printf("Q : ���α׷� ����\n\n");
	printf("���� 3���� �ڽŸ��� ���\n");
	printf("S : ������ ����(�տ� �� �ڸ��� ������ ��ҵ��� �̵�)\n");
	printf("Z : tail �ڿ� ���� �ڸ��� ������ ���\n");
	printf("R : ť�� ������ �ݴ�� �ؼ� ���(ť�� ���´� �״��)\n\n");
	printf("PrintAll �Լ��� is_member �Լ����� head�� ������� �ϴ� ������ �����߽��ϴ�.\n\n");

}
int Setposition()//head�� ó�� ��ġ ����
{
	return -1;//ť�� �ƹ��͵� ������� ���� ��, head�� tail�� -1
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


int DataCount(Position* p)//ť ��� ����
{
	return p->tail - p->head;
}

void Shift(char array[], Position* p)
{
	if (p->head == -1)//�̹� ������ ���ĵ� �����̸� �״�� ��ȯ
		return;

	int frontlen = p->head + 1;//head �տ� ���� �ڸ��� ����
	int i = 0;

	while (p->head != p->tail) {//��ҵ��� ��� ������ ���
		p->head++;
		array[i] = array[p->head];
		array[p->head] = '\0';
		i++;
	}

	p->head = Setposition();//head�� tail ��ġ �缳��
	p->tail -= frontlen;
}

void Enqueue(char array[], char order[], Position* p)//enqueue�Լ�
{
	char temp_array[Max_Size];
	int enlen, rearlen, frontlen, remainlen;

	int i;

	for (i = 0; i < strlen(order) - 1; i++) {//+abcd�� temp_array�� abcd�� ����
		temp_array[i] = order[i + 1];
	}
	temp_array[strlen(order) - 1] = '\0';

	enlen = strlen(temp_array);//����ڰ� �ְ� ���� ����� ����(ex.abcd�� 4��)
	rearlen = Max_Size - p->tail - 2;//tail �ڿ� ���� �ڸ��� ����
	frontlen = p->head + 1;//head �տ� ���� �ڸ��� ����
	remainlen = frontlen + rearlen;//ť�� ���� �ڸ��� �� ����

	if (enlen > rearlen) {//enlen���� tail ���� �ڸ��� ������ ��(ex. 4�� �ְ� ������ tail �ڿ� 3�ڸ��ۿ� ���� ��)
		if (enlen > remainlen)//enlen���� remainlen�� ������ ��
			printf("ť�� ���� �ڸ��� �����մϴ�. ���� �ڸ��� %d���Դϴ�.\n", remainlen);
		else {//���� �ڸ��� �� ������ ���ڸ��� ���� ��
			Shift(array, p);//�տ� ���ڸ��� ������ ť ����

			for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}

	else {//ť�� �ڸ��� �˳��� ��
		for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
			array[p->tail + 1 + i] = temp_array[i];
		}

		p->tail += strlen(temp_array);
	}
}

void PrintAll(char array[], Position* p)//ť ��ü ��� �Լ�
{
	char temp_array[Max_Size] = { '\0', };
	int i = 0;
	int enlen, rearlen, frontlen, remainlen;

	if (p->head == p->tail)//ť�� �������
		printf("����� ���� ����\n");

	else {//ť�� ����� ���� �ִ� ���
		while (p->head != p->tail)
		{
			p->head++;
			printf("%c", array[p->head]);//head��Ҹ� peek�ϰ�
			temp_array[i] = array[p->head];//temp_array�� ����
			i++;
		}
		printf("\n");

		//���� temp�� �־�״� �͵��� �ٽ� ť�� ����
		//enqueue�� ������ ����

		enlen = strlen(temp_array);//�ְ� ���� ����� ����(ex.abcd�� 4��)
		rearlen = Max_Size - p->tail - 2;//tail �ڿ� ���� �ڸ��� ����
		frontlen = p->head + 1;//head �տ� ���� �ڸ��� ����
		remainlen = frontlen + rearlen;//ť�� ���� �ڸ��� �� ����

		if (enlen > rearlen) {//enlen���� tail ���� �ڸ��� ������ ��(ex. 4�� �ְ� ������ tail �ڿ� 3�ڸ��ۿ� ���� ��)
			if (enlen > remainlen)//enlen���� remainlen�� ������ ��
				printf("ť�� ���� �ڸ��� �����մϴ�. ���� �ڸ��� %d���Դϴ�.\n", remainlen);
			else {//���� �ڸ��� �� ������ ���ڸ��� ���� ��
				Shift(array, p);//�տ� ���ڸ��� ������ ť ����

				for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
					array[p->tail + 1 + i] = temp_array[i];
				}

				p->tail += strlen(temp_array);
			}
		}

		else {//ť�� �ڸ��� �˳��� ��
			for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}
}

void Peek(char array[], Position* p)//head�� �ִ� ���� ����ϴ� peek�Լ�
{
	if (p->head == p->tail)//ť�� �������
		printf("peek�� ���� ����\n");
	else//ť�� ����� ���� �ִ� ���
	{
		int savehead = p->head;
		p->head++;
		printf("%c\n", array[p->head]);
		p->head = savehead;
	}
}

void Dequeue(char array[], char order[], Position* p)//dequeue�Լ�(�ѹ��� �ϳ����� ���� ����, ���ڸ� �̿��� ���� �� ���� ���� ����)
{
	char s1[30];
	int num;

	if (order[1] != '\0') {//-���� ���·� �Է¹��� ���
		for (int i = 0; i < strlen(order) - 1; i++) {//���� ��� ����ڰ� -12�� �Է�������, 12�� s1�� ���� ���·� ����
			s1[i] = order[i + 1];
		}
		s1[strlen(order) - 1] = '\0';

		num = atoi(s1);//12�� ���ڷ� ��ȯ

		if (num != 0) {//-���� ����ڰ� ������ �Է��� ���
			if (num > DataCount(p))
				printf("�Է��� ���ڰ� ť�� �ִ� ��� �������� �����ϴ�. �ٽ� �Է��ϼ���");
			else {
				for (int i = 0; i < num; i++) {
					p->head++;
					printf("%c", array[p->head]);//peek�ϰ�
					array[p->head] = '\0';//����
				}
				printf(" ����");
			}
		}
	}

	else {//-�� �Է¹��� ���
		if (p->head == p->tail)//ť�� �������
			printf("dequeue�� ���� ����\n");

		else {//ť�� ����� ���� �ִ� ���
			p->head++;
			printf("%c", array[p->head]);//peek�ϰ�
			array[p->head] = '\0';//����
		}
	}
}

bool is_full(Position* p)//ť ���� á���� ����
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

bool is_member(char array[], char order[], Position* p)//ť�� ��Ұ� �ִ��� ���� �Լ�
{
	char temp_array[Max_Size] = { '\0', };
	int i = 0;
	int enlen, rearlen, frontlen, remainlen;
	bool exist = false;//��� ���� ���� Ȯ���ϴ� ����

	if (is_empty == 1)//ť�� ����� ���� ���� ���
		printf("False\n");

	else {//ť�� ����� ���� �ִ� ���
		while (p->head != p->tail)
		{
			p->head++;
			if (array[p->head] == order[1])//ť�� ��Ұ� �����ϸ�
				exist = true;
			temp_array[i] = array[p->head];//temp_array�� ����
			i++;
		}

		//head�� ������� �ϴ� ���� �ƴ�, enqueue�� ������ �̷�������� ��

		enlen = strlen(temp_array);//�ְ� ���� ����� ����(ex.abcd�� 4��)
		rearlen = Max_Size - p->tail - 2;//tail �ڿ� ���� �ڸ��� ����
		frontlen = p->head + 1;//head �տ� ���� �ڸ��� ����
		remainlen = frontlen + rearlen;//ť�� ���� �ڸ��� �� ����

		if (enlen > rearlen) {//enlen���� tail ���� �ڸ��� ������ ��(ex. 4�� �ְ� ������ tail �ڿ� 3�ڸ��ۿ� ���� ��)
			if (enlen > remainlen)//enlen���� remainlen�� ������ ��
				printf("ť�� ���� �ڸ��� �����մϴ�. ���� �ڸ��� %d���Դϴ�.\n", remainlen);
			else {//���� �ڸ��� �� ������ ���ڸ��� ���� ��
				Shift(array, p);//�տ� ���ڸ��� ������ ť ����

				for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
					array[p->tail + 1 + i] = temp_array[i];
				}

				p->tail += strlen(temp_array);
			}
		}

		else {//ť�� �ڸ��� �˳��� ��
			for (i = 0; i < strlen(temp_array); i++) {//tail �ڿ� �Է¹��� �͵� ����
				array[p->tail + 1 + i] = temp_array[i];
			}

			p->tail += strlen(temp_array);
		}
	}

	return exist;
}

void Replace(char order[], char array[], Position* p)//tail ��� ���� �Լ�
{
	if (is_empty(p) != 1)
		array[p->tail] = order[1];
}

void Clear(char array[], char order[], Position* p)//ť ���� �Լ�
{
	while (p->head != p->tail) {
		Dequeue(array, order, p);
	}
	printf("\n");

	Positioninit(p);
}

int Z(Position* p)//tail �ڿ� ���� �ڸ��� ����
{
	int rearlen = Max_Size - p->tail - 2;
	return rearlen;
}

void Reverse(char array[], Position* p)//������ ��� �Լ�
{
	char temp[Max_Size] = { '\0' };
	int savehead = p->head;//������ head��ġ ����
	int i = 0;

	if (is_empty(p) == 1)//ť�� �������
		printf("������ ���� ����\n");

	else {//ť�� ����� ���� �ִ� ���
		while (p->head != p->tail)
		{
			p->head++;
			temp[i] = array[p->head];
			i++;
		}
		p->head = savehead;//head�� �������

		int cnt = strlen(temp);
		char tmp;//�ܾ� �ϳ��� �ӽ÷� ������ ����

		for (i = 0; i < cnt / 2; i++) {// ��ȯ�� �ߺ����� �ʱ� ���� cnt/2���� �ݺ���
			tmp = temp[i];
			temp[i] = temp[cnt - 1 - i];
			temp[cnt - 1 - i] = tmp;
		}// 0���� ����, 1���� ��-1��...������ ��ȯ��

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
			printf("���α׷��� �����մϴ�.\n");
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