#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//���ڿ� ����, ���� ���� ���
#include<stdbool.h>//true, false


void UserSetting()
{
	printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n\n");
	printf("+abcd : ���� ���(������ ��Ҵ� �������)\n");
	printf("<N : ���� ��ġ�� �տ������� ����(N�� ������ �������)\n");
	printf(">P : ���� ��ġ�� �ڿ������� ����(P�� ������ �������)\n");
	printf("- : ���� ��ġ�� ��� ���� ���\n");
	printf(">- : ������ ��� ���� ���(���� �Լ��� �ۼ����� �ʰ� Delete����� �̿���)\n");
	printf("@ : ���� ��ġ�� ��� ���\n");
	printf("=a : ���� ��ġ�� �ִ� ��Ҹ� ����ڰ� �Է��� ��ҷ� ����(a�� �ƴϾ ��)\n");
	printf("E : �迭 ����\n");
	printf("M : ���� ��ġ�� ��Ҹ� (n, ��, ��)��°�� �̵� / M7, MP, MN�������� ��� ����\n");
	printf("D : �迭 ��� ���� Ȯ��\n");
	printf("L : �迭 ���\n");
	printf("S : ã�� ���\n");
	printf("R : �迭 �Ųٷ� �ٲٱ� ���\n");
	printf("WP : ��� 2�� ���� ��ȯ ���\n");
	printf("Q : ���α׷� ����\n\n");

}
int Setposition()
{
	return 0;
}

int DataInsert(char array[], char order[], int position)
{
	char insert_array[30];
	char temp[30];

	int j = 0;
	int i;

	while (array[j] != '\0') {//position �ڿ� �� tem���� ����
		temp[j] = array[position + 1 + j];
		j++;
	}
	temp[j] = '\0';

	for (i = 0; i < (int)strlen(order)-1; i++) {//+abcd�� insert_array�� abcd�� ����
		insert_array[i] = order[i + 1];
	}
	insert_array[strlen(order) - 1] = '\0';

	if (array[0] == '\0') {//array�� �ƹ��͵� ���� ���
		strcpy(array, insert_array);
		position += strlen(insert_array) - 1;
	}

	else {//array�� �� �迭�� �ƴ� ���
		for (i = 0; i < (int)strlen(insert_array); i++) {//position �ڸ� ������ ������ �ٲ�
			array[position + 1 + i] = insert_array[i];
		}

		int temlen = strlen(array);

		for (i = 0; i < strlen(temp); i++) {//array �� �ڿ� tem���� �����ߴ� �� ����
			array[temlen + i] = temp[i];
		}
		position += strlen(insert_array);
	}

	return position;
}

int traverse_front(char order[], char array[])
{
	int position = 0;

	for (int i = 1; i < strlen(order); i++) {
		if (order[i] == 'N')
			position++;
	}

	if (position >= strlen(array)) {
		printf("�迭���� ���� ��ġ�� ��Ÿ�� �� �����ϴ�. ���� ��ġ�� 0���� �մϴ�.\n");
		position = 0;
	}

	return position;
}

int traverse_rear(char order[], char array[])
{
	int position = strlen(array) - 1;

	for (int i = 1; i < strlen(order); i++) {
		if (order[i] == 'P')
			position--;
	}

	if (position < 0) {
		printf("�迭���� ���� ��ġ�� ��Ÿ�� �� �����ϴ�. ���� ��ġ�� �ǵڷ� �մϴ�.\n");
		position = strlen(array) - 1;
	}

	return position;
}

int Delete(char array[], int position)
{
	memmove(array + position, array + position + 1, strlen(array) - position);
	//memmove�Լ� �̿�, ���� ��ġ ������ �迭�� ������ �� ĭ�� �ű�

	if (position >= strlen(array)) {
		position = strlen(array) - 1;
	}

	return position;
}

void get_data(char array[], int position)
{
	printf("%c\n", array[position]);
}

void replace(char order[], char array[], int position)
{
	array[position] = order[1];
}

char empty(char array[])
{
	return '\0';
}

int move(char order[], char array[], int position)
{
	char s1[30];
	char temp;
	int num;

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//���� ��� ����ڰ� M2�� �Է�������, M2�� s1�� 2�� ����
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);

	if (num!=0) {//M���� ����ڰ� ������ �Է��� ���
		if (num >= strlen(array)) {
			printf("���� ��ġ�� ��Ҹ� %d�� �ε����� �ű� �� �����ϴ�.\n", num);
		}
		else {
			temp = array[position];
			array[position] = array[num];
			array[num] = temp;
		}
		position = num;
	}

	if ((order[1] == 'P')&&(position!=0)) {//M���� ����ڰ� P�� �Է��� ���
		temp = array[position];
		array[position] = array[position - 1];
		array[position - 1] = temp;

		position -= 1;
	}

	if ((order[1] == 'N')&&(position<strlen(array)-1)) {//M���� ����ڰ� N�� �Է��� ���
		temp = array[position];
		array[position] = array[position + 1];
		array[position + 1] = temp;

		position += 1;
	}

	return position;
}

void data_count(char array[])
{
	printf("%d\n", strlen(array));
}

void PrintArray(char array[])
{
	printf("%s\n", array);
}

void Search(char array[])
{
	int cnt = strlen(array);
	char SearchAlphabet;
	int index;
	bool exist = false;

	printf("searchalphabet: ");
	scanf("%c", &SearchAlphabet); // �迭���� ã�� ��� �Է¹ޱ�

	for (int i = 0; i < cnt; i++) {
		if (SearchAlphabet == array[i]) {
			exist = true;
			index = i;
		}
	} // �迭 ó������ ������ Ž���ϱ�(��Ұ� �迭�� ������ exist�� false�� ��)

	if (exist == true) { // �迭�� ��Ұ� �ִٸ�
		printf("%c�� �ε��� ��ȣ %d���� �ֽ��ϴ�.\n", SearchAlphabet, index);
	}
	else // �迭�� ��Ұ� ���ٸ�
		printf("ã���� �ϴ� %c�� ã�� ���߽��ϴ�.\n", SearchAlphabet);

} // ã���� �ϴ� ��Ҹ� �迭 ������ ã�� search�Լ�

int Reverse(char array[], int position)
{
	int cnt = strlen(array);
	int mid = cnt / 2;
	char tmp;

	for (int i = 0; i < cnt / 2; i++) { // ��ȯ�� �ߺ����� �ʱ� ���� cnt/2���� �ݺ���
		tmp = array[i];
		array[i] = array[cnt - 1 - i];
		array[cnt - 1 - i] = tmp;
	} // 0���� ����, 1���� ��-1��...������ ��ȯ��

	position = 2 * mid - position;
	
	return position;


} // �迭�� �Ųٷ� �ٲٴ� reverse�Լ�

int Swap(char array[], int position)
{
	int cnt = strlen(array);
	int n1, n2;
	char temp;

	while (1) {
		printf("swap�� �� �ε��� ��ȣ �Է�(�Է��� ����� ����): ");
		scanf("%d %d", &n1, &n2); //swap�� �ε��� ��ȣ 2���� ����

		if (n1 < cnt && n2 < cnt)
			break; // escape code

		else
			printf("�Է��� �ε��� ��ȣ�� ������ �� ����. �ٽ� �Է�\n");

	} // ���� ������ �ε��� ��ȣ ���� ���� n1�� n2�� ����

	temp = array[n1];
	array[n1] = array[n2];
	array[n2] = temp;
	// swap ����

	if (position == n1)
		position = n2;
	if (position == n2)
		position == n1;

} // ��� 2���� ���� ��ȯ�ϴ� swap �Լ�

int main() {
	char array[30] = { '\0', };
	char order[30];
	int position = Setposition();

	UserSetting();

	while (1) {

		printf("order : ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}//escape code

		if (order[0] == '+') {
			position = DataInsert(array, order, position);
		}

		if (order[0] == '<') {
			position = traverse_front(order, array);
		}

		if (order[0] == '>') {
			position = traverse_rear(order, array);

			if (order[1] == '-') {
				position = Delete(array, position);
			}
		}

		if (order[0] == '-') {
			position = Delete(array, position);
		}

		if (order[0] == '@') {
			printf("���� ��ġ�� ��� : ");
			get_data(array, position);
		}

		if (order[0] == '=') {
			replace(order, array, position);
		}

		if (order[0] == 'E') {
			array[0] = empty(array);
			position = Setposition();
		}

		if (order[0] == 'M') {
			position = move(order, array, position);
		}

		if (order[0] == 'D') {
			data_count(array);
		}

		if (order[0] == 'L') {
			PrintArray(array);
		}

		if (order[0] == 'S') {
			getchar();//���Ͱ� �ԷµǴ� ���� ���� ����
			Search(array);
		}

		if (order[0] == 'R') {
			position = Reverse(array, position);
		}

		if (strcmp(order, "WP") == 0) {
			position = Swap(array, position);
		}
	}

	system("pause");

	return 0;
}