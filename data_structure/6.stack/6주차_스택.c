#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//���ڿ� ����, ���� ���� ���
#include<stdbool.h>//true, false

#define Max_Size 30 // ������ ũ�⸦ 30���� static�ϰ� ����(�������� '\0'�� �־�� �ϹǷ� ������ ũ��� 29)

void UserSetting()
{
	printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n\n");
	printf("+abcd : push ���(push�� ��Ҵ� �������)\n");
	printf("L : ���� ��ü ���\n");
	printf("P : top ��ġ�� ��� peek(����)\n");
	printf("- : top ��ġ�� �ϳ��� ��� pop(������)\n");
	printf("-5 : top ��ġ�� ��Һ��� 5�������� pop(5�� �ƴϾ ��)\n");
	printf("F : ������ �� á���� ����\n");
	printf("# : ���� ��� ���� Ȯ��\n");
	printf("T : top ��ġ�� ��� ���\n");
	printf("?a : ���ÿ� ��Ұ� �ִ��� ����(a�� �ƴϾ ��)\n");
	printf("=a : ���� ��ġ�� �ִ� ��Ҹ� ����ڰ� �Է��� ��ҷ� ����(a�� �ƴϾ ��)\n");
	printf("C : ���� ����(��ҵ� �����ָ鼭 �����)\n");
	printf("Q : ���α׷� ����\n\n");
	printf("���� 3���� �ڽŸ��� ���\n");
	printf("E : �� ���� ����\n");
	printf("SW : top�� top-1��Ҹ� swap\n");
	printf("R : ������ ������ top���� reverse�ؼ� ���\n\n");
}
int Setposition()//top�� ó�� ��ġ ����
{
	return -1;//���ÿ� �ƹ��͵� ������� ���� ��, top�� -1
}

int Push(char array[], char order[], int top)//push�Լ�
{
	char temp_array[30];
	int pushlen, remainlen;

	int i;

	for (i = 0; i < strlen(order) - 1; i++) {//+abcd�� temp_array�� abcd�� ����
		temp_array[i] = order[i + 1];
	}
	temp_array[strlen(order) - 1] = '\0';

	pushlen = strlen(temp_array);//����ڰ� �ְ� ���� ����� ����(ex.abcd�� 4��)
	remainlen = Max_Size - top - 2;//���ÿ� ���� �ڸ��� ����

	if (pushlen > remainlen) {//pushlen���� ���� �ڸ��� ������ ��(ex. 4�� �ְ� ������ 3�ڸ��ۿ� ���� ��)
		printf("���ÿ� ���� �ڸ��� �����մϴ�. ���� �ڸ��� %d���Դϴ�.\n", remainlen);
	}

	else {//���ÿ� �ڸ��� �˳��� ��
		for (i = 0; i < strlen(temp_array); i++) {//top �ڿ� �Է¹��� �͵� ����
			array[top + 1 + i] = temp_array[i];
		}

		top += strlen(temp_array);
	}

	return top;
}

void PrintAll(char array[], int top)//���� ��ü ��� �Լ�
{
	char temp[Max_Size] = { '\0' };
	int savetop = top;//������ top��ġ ����

	if (top == -1)//���ÿ� ����� ���� ���� ���
		printf("����� ���� ����\n");

	else {//���ÿ� ����� ���� �ִ� ���
		for (int i = 0; i <= savetop; i++) {//temp�� array�� �ݴ�� ����, array�� �ʱ�ȭ
			temp[i] = array[top];
			array[top] = '\0';
			top--;
		}
		top = savetop;//top�� �ٽ� ������ ��ġ�� ������Ʈ

		for (int i = 0; i <= savetop; i++) {//temp���� �ٽ� array�� �����ϸ� ��� �ϳ��ϳ��� ����
			array[i] = temp[top - i];
			printf("%c", array[i]);
		}
		array[savetop + 1] = '\0';
		printf("\n");


		top = savetop;
	}
}

void Peek(char array[], int top)//top�� �ִ� ���� ����ϴ� peek�Լ�
{
	if (top == -1)//���ÿ� ����� ���� ���� ���
		printf("peek�� ���� ����\n");
	else//���ÿ� ����� ���� �ִ� ���
		printf("%c\n", array[top]);
}

int Pop(char array[], char order[], int top)//pop�Լ�(�ѹ��� �ϳ����� ���� ����, ���ڸ� �̿��� ���� �� ���� ���� ����)
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
			if (num > top + 1)
				printf("�Է��� ���ڰ� ���� ��ü�� �������� �����ϴ�. �ٽ� �Է��ϼ���\n");
			else {
				for (int i = 0; i < num; i++) {
					Peek(array, top);//peek�ϰ�
					array[top] = '\0';//����
					top--;//top��ġ ����
				}
			}
		}
	}

	else {//-�� �Է¹��� ���
		if (top == -1)//���ÿ� ����� ���� ���� ���
			printf("pop�� ���� ����\n");

		else {//���ÿ� ����� ���� �ִ� ���
			Peek(array, top);//peek�ϰ�
			array[top] = '\0';//����
			top--;//top��ġ ����
		}
	}

	return top;
}

void is_full(char array[], int top)//���� ���� á���� ���� �Լ�
{
	if (top == Max_Size - 2)
		printf("���� ��\n");
	else
		printf("���� ������ ����\n");
}

void element_count(int top)//���� ��� ���� Ȯ�� �Լ�
{
	int cnt = top + 1;

	printf("%d\n", cnt);
}

void Top(char array[], int top)//top ��ġ�� ��� ��� �Լ�
{
	if (top == -1)
		printf("top ��ġ�� ��Ұ� ����\n");
	else
		printf("(%d, %c)\n", top + 1, array[top]);
}

void is_member(char array[], char order[], int top)//���ÿ� ��Ұ� �ִ��� ���� �Լ�
{
	char temp[Max_Size] = { '\0' };
	bool exist = false;//��� ���� ���� Ȯ���ϴ� ����
	int savetop = top;//������ top��ġ ����

	if (top == -1)//���ÿ� ����� ���� ���� ���
		printf("False\n");

	else {//���ÿ� ����� ���� �ִ� ���
		for (int i = 0; i <= savetop; i++) {//temp�� array�� �ݴ�� ����, ����� ���ÿ� search�ϱ�
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

		top = savetop;//top�� �ٽ� ������ ��ġ�� ������Ʈ

		for (int i = 0; i <= savetop; i++) {//temp�� ������ ���� �ٽ� array��
			array[i] = temp[top - i];
		}
	}
}

void Replace(char order[], char array[], int top)//top ��� ���� �Լ�
{
	if (top != -1)
		array[top] = order[1];
}

int Clear(char array[], char order[], int top)//���� ���� �Լ�
{
	int savetop = top;

	for (int i = 0; i <= savetop; i++) {
		top = Pop(array, order, top);
	}

	return top;
}

void is_empty(int top)//�� ���� ���� �Լ�
{
	if (top == -1)
		printf("True(������ �������)\n");
	else
		printf("False(������ ������� ����)\n");
}

void Swap(char array[], int top)//top�� top-1��Ҹ� swap �� ��� �Լ�
{
	char temp1[2] = { '\0', };
	char temp2[2] = { '\0', };
	int savetop = top;

	if (top < 1)
		printf("Swap�� ��Ұ� ������\n");

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

void ReverseStack(char array[], int top)//������ ��� �Լ�
{
	char temp[Max_Size] = { '\0' };
	int savetop = top;//������ top��ġ ����

	if (top == -1)//���ÿ� ����� ���� ���� ���
		printf("������ ���� ����\n");

	else {//���ÿ� ����� ���� �ִ� ���
		for (int i = 0; i <= savetop; i++) {//array�� top��Ұ� temp�� �Ѿ.
			temp[i] = array[top];
			printf("%c", array[top]); //�Ѿ�� ��� �ϳ��ϳ��� �����
			array[top] = '\0';
			top--;
		}
		top = savetop;//top�� �ٽ� ������ ��ġ�� ������Ʈ

		for (int i = 0; i <= savetop; i++) {//temp���� �ٽ� array�� ����
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
			printf("���α׷��� �����մϴ�.\n");
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