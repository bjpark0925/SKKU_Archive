#pragma warning(disable: 4996)
#include<stdio.h>
#include<string.h>//문자열 길이, 복사 위한 헤더
#include<stdbool.h>//true, false


void UserSetting()
{
	printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n\n");
	printf("+abcd : 삽입 명령(삽입할 요소는 마음대로)\n");
	printf("<N : 현재 위치를 앞에서부터 변경(N의 개수는 마음대로)\n");
	printf(">P : 현재 위치를 뒤에서부터 변경(P의 개수는 마음대로)\n");
	printf("- : 현재 위치의 요소 삭제 명령\n");
	printf(">- : 마지막 요소 삭제 명령(따로 함수를 작성하지 않고 Delete명령을 이용함)\n");
	printf("@ : 현재 위치의 요소 출력\n");
	printf("=a : 현재 위치에 있는 요소를 사용자가 입력한 요소로 변경(a가 아니어도 됨)\n");
	printf("E : 배열 비우기\n");
	printf("M : 현재 위치의 요소를 (n, 앞, 뒤)번째로 이동 / M7, MP, MN형식으로 사용 가능\n");
	printf("D : 배열 요소 개수 확인\n");
	printf("L : 배열 출력\n");
	printf("S : 찾기 명령\n");
	printf("R : 배열 거꾸로 바꾸기 명령\n");
	printf("WP : 요소 2개 서로 교환 명령\n");
	printf("Q : 프로그램 종료\n\n");

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

	while (array[j] != '\0') {//position 뒤에 꺼 tem으로 저장
		temp[j] = array[position + 1 + j];
		j++;
	}
	temp[j] = '\0';

	for (i = 0; i < (int)strlen(order)-1; i++) {//+abcd를 insert_array에 abcd로 저장
		insert_array[i] = order[i + 1];
	}
	insert_array[strlen(order) - 1] = '\0';

	if (array[0] == '\0') {//array에 아무것도 없는 경우
		strcpy(array, insert_array);
		position += strlen(insert_array) - 1;
	}

	else {//array가 빈 배열이 아닌 경우
		for (i = 0; i < (int)strlen(insert_array); i++) {//position 뒤를 삽입할 것으로 바꿈
			array[position + 1 + i] = insert_array[i];
		}

		int temlen = strlen(array);

		for (i = 0; i < strlen(temp); i++) {//array 맨 뒤에 tem으로 저장했던 것 넣음
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
		printf("배열에서 현재 위치를 나타낼 수 없습니다. 현재 위치를 0으로 합니다.\n");
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
		printf("배열에서 현재 위치를 나타낼 수 없습니다. 현재 위치를 맨뒤로 합니다.\n");
		position = strlen(array) - 1;
	}

	return position;
}

int Delete(char array[], int position)
{
	memmove(array + position, array + position + 1, strlen(array) - position);
	//memmove함수 이용, 현재 위치 이후의 배열을 앞으로 한 칸씩 옮김

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

	for (int i = 0; i < (int)strlen(order) - 1; i++) {//예를 들어 사용자가 M2를 입력했으면, M2를 s1에 2로 저장
		s1[i] = order[i + 1];
	}
	s1[strlen(order) - 1] = '\0';

	num = atoi(s1);

	if (num!=0) {//M이후 사용자가 정수를 입력한 경우
		if (num >= strlen(array)) {
			printf("현재 위치의 요소를 %d번 인덱스로 옮길 수 없습니다.\n", num);
		}
		else {
			temp = array[position];
			array[position] = array[num];
			array[num] = temp;
		}
		position = num;
	}

	if ((order[1] == 'P')&&(position!=0)) {//M이후 사용자가 P를 입력한 경우
		temp = array[position];
		array[position] = array[position - 1];
		array[position - 1] = temp;

		position -= 1;
	}

	if ((order[1] == 'N')&&(position<strlen(array)-1)) {//M이후 사용자가 N을 입력한 경우
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
	scanf("%c", &SearchAlphabet); // 배열에서 찾을 요소 입력받기

	for (int i = 0; i < cnt; i++) {
		if (SearchAlphabet == array[i]) {
			exist = true;
			index = i;
		}
	} // 배열 처음부터 끝까지 탐색하기(요소가 배열에 없으면 exist는 false가 됨)

	if (exist == true) { // 배열에 요소가 있다면
		printf("%c는 인덱스 번호 %d번에 있습니다.\n", SearchAlphabet, index);
	}
	else // 배열에 요소가 없다면
		printf("찾고자 하는 %c를 찾지 못했습니다.\n", SearchAlphabet);

} // 찾고자 하는 요소를 배열 내에서 찾는 search함수

int Reverse(char array[], int position)
{
	int cnt = strlen(array);
	int mid = cnt / 2;
	char tmp;

	for (int i = 0; i < cnt / 2; i++) { // 교환이 중복되지 않기 위해 cnt/2까지 반복함
		tmp = array[i];
		array[i] = array[cnt - 1 - i];
		array[cnt - 1 - i] = tmp;
	} // 0번과 끝번, 1번과 끝-1번...순으로 교환함

	position = 2 * mid - position;
	
	return position;


} // 배열을 거꾸로 바꾸는 reverse함수

int Swap(char array[], int position)
{
	int cnt = strlen(array);
	int n1, n2;
	char temp;

	while (1) {
		printf("swap할 두 인덱스 번호 입력(입력은 띄어쓰기로 구분): ");
		scanf("%d %d", &n1, &n2); //swap할 인덱스 번호 2개를 받음

		if (n1 < cnt && n2 < cnt)
			break; // escape code

		else
			printf("입력한 인덱스 번호를 감당할 수 없음. 다시 입력\n");

	} // 감당 가능한 인덱스 번호 범위 내의 n1과 n2를 받음

	temp = array[n1];
	array[n1] = array[n2];
	array[n2] = temp;
	// swap 과정

	if (position == n1)
		position = n2;
	if (position == n2)
		position == n1;

} // 요소 2개를 서로 교환하는 swap 함수

int main() {
	char array[30] = { '\0', };
	char order[30];
	int position = Setposition();

	UserSetting();

	while (1) {

		printf("order : ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("프로그램을 종료합니다.\n");
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
			printf("현재 위치의 요소 : ");
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
			getchar();//엔터가 입력되는 것을 막기 위함
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