#include "2019312014_박병준_콘솔메뉴원본.h" // 헤더 파일 포함하기

int main()
{
	int nSelectedMainMenu;
	int bIterationFlag = TRUE;

	srand(time(NULL)); // seed (이제 rand()함수에는 무작위의 숫자가 나옴 )

	while (bIterationFlag) {
		system("cls"); // clear screen
		nSelectedMainMenu = displayMainMenu();
		system("cls");
		switch (nSelectedMainMenu) {
		case DIE_SIMULATION:
			dieSimulation();
			break;
		case GAME_SHOW:
			gameShow();
			break;
		case UP_DOWN_GAME:
			upDownGame();
			break;
		case WORD_GAME:
			wordGame();
			break;
		case OX_GAME:
			OXGame();
			break;
		case ABOUT:
			about();
			break;
		case EXIT:
			bIterationFlag = FALSE; // escape condition
			printf("\n\n\tGOOD BYE\n\n");
			break;
		default:
			printf("\n\n\tWRONG ANSWER!!\n\n");
			break;
		} // switch
		system("pause");
	} // while

	return 0;
} // main()

//====================================
//  Implementation of User Defined Functions
//==================================== 

int displayMainMenu() {

	int nMenu;

	printf("\n\n");
	printf("\t========================\n");
	printf("\t        Main Menu\n");
	printf("\t========================\n");
	printf("\t  1. Die Simulation\n");
	printf("\t  2. Game Show\n");
	printf("\t  3. Up Down Game\n");
	printf("\t  4. Word Game\n");
	printf("\t  5. OX Game\n");
	printf("\t  6. About\n");
	printf("\t========================\n");
	printf("\t  0. Exit\n");
	printf("\t========================\n");
	printf("\t >>");
	scanf("%d", &nMenu);


	return nMenu;
} // displayMainMenu

void dieSimulation()
{
	int nFaceValue, nSum = 0, nCount = 0;
	int i;

	printf("\n\n");
	printf("\t=========================\n");
	printf("\t      Die Simulation\n");
	printf("\t=========================\n\n");

	for (i = 0; i < 100000; i++, nSum = 0) {
		while (nSum < 100) {
			nFaceValue = (rand() % 6) + 1; // 주사위가 1~6 중 하나 무작위로 굴려짐
			nSum += nFaceValue; // 나온 주사위 값은 nSum에 계속 누적됨
			nCount++; // 카운트 증가
		} // while(nSum이 100이 될 때까지 카운팅함)
	} // for(총 10만 번 시뮬레이션)

	printf("\n");
	printf("\t 주사위의 누적합이 100을\n");
	printf("\t 넘으려면 시뮬레이션 결과\n");
	printf("\t 약 %.2lf번을 굴리면 됩니다.\n\n", nCount / 100000.0);
	printf("\t==========================\n");

} // dieSimulation()

void gameShow()
{
	int nChoiceDoor, nPrizeDoor;
	int nRevealDoor, nSwitchDoor;
	int nChoiceCount = 0, nSwitchCount = 0;
	int i;

	printf("\n\n");
	printf("\t=========================\n");
	printf("\t        Game Show\n");
	printf("\t=========================\n\n");

	//Case1: 안바꾸기
	for (i = 0; i < 100000; i++) {
		nChoiceDoor = rand() % 3; // 0~2
		nPrizeDoor = rand() % 3; // 0~2
		if (nChoiceDoor == nPrizeDoor) nChoiceCount++;
	} // for
	printf("\t  CHOICE >> %.2lf %%\n\n", nChoiceCount / 1000.0); // 확률(%) 출력

	//Case2: 바꾸기
	for (i = 0; i < 100000; i++) {
		nChoiceDoor = rand() % 3; // 0~2
		nPrizeDoor = rand() % 3; // 0~2

		nRevealDoor = 0;
		while (nRevealDoor == nChoiceDoor ||
			nRevealDoor == nPrizeDoor) nRevealDoor++; // 리빌도어가 0에서부터 출발하여 초이스와 프라이즈가 아닌 곳에 위치함

		nSwitchDoor = 0;
		while (nSwitchDoor == nChoiceDoor ||
			nSwitchDoor == nRevealDoor) nSwitchDoor++; // 스위치도어는 초이스, 리빌과 다름

		if (nSwitchDoor == nPrizeDoor) nSwitchCount++; // 스위치 도어가 정답이면 카운트 증가
	} // for
	printf("\t  Switch >> %.2lf %%\n\n", nSwitchCount / 1000.0); // 확률 출력(%)

	printf("\t=================\n");
} // gameShow()

void upDownGame()
{
	int nRandom, nInput;
	int nmin, nmax;
	int nCount;

	nmin = 1;
	nmax = 100;
	nCount = 0;

	nRandom = (rand() % 100) + 1;//임의의 1~100
	printf("%d\n", nRandom); // 정답 잠깐 출력

	while (TRUE) {
		system("cls"); // clear screen
		printf("\n\n");
		printf("\t=========================\n");
		printf("\t       Up Down Game\n");
		printf("\t=========================\n\n");
		printf("\t(%d ~ %d)\n\n", nmin, nmax);
		printf("\t Input(1~100) >> ");

		scanf("%d", &nInput); // 사용자가 숫자 input하고
		nCount++; // 카운트 증가

		if (nRandom < nInput) {
			printf("\n\t DOWN\n\n");
			nmax = nInput - 1;
		}
		else if (nRandom > nInput) {
			printf("\n\t UP\n\n");
			nmin = nInput + 1;
		}
		else {//nRandom == nInput
			printf("\n\t RIGHT!!\n\n");
			printf("\n\t COUNT >> %d\n\n", nCount);
			printf("\t=========================\n");
			break;//escape condition
		}//if..else	
		printf("\t=========================\n");
		system("pause"); //getch(); => 콘솔창 멈추기
	}//while(정답 맞힐 때까지)

} // upDownGame()

void wordGame()
{
	char strWords[10][80] = {
		"computer",
		"controller",
		"university",
		"department",
		"education",
		"smartphone",
		"source",
		"keyboard",
		"mouse",
		"windows"
	};
	char strInput[80], chInput, strChar[80];
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int nSelectedIndex, nLength;
	int i, nCount = 0;
	// strWords[nSelectedIndex]는 예를 들어 'e','d','c','a','t','i','o','n','\0'
	// strInput은 '_''_'...'\0'
	// chInput은 입력받은 문자를 strInput에 추가
	// strChar은 문자열 입력을 위해

	nSelectedIndex = rand() % 10; // 0~9
	printf("%s\n", strWords[nSelectedIndex]); // 잠깐 정답 공개

	nLength = strlen(strWords[nSelectedIndex]); // 정답의 길이
	printf("%d\n", nLength);

	for (i = 0; i < nLength; i++) strInput[i] = '_';
	strInput[nLength] = '\0';

	while (TRUE) {
		system("cls");
		printf("\n\n");
		printf("\t=========================\n");
		printf("\t        Word Game\n");
		printf("\t=========================\n\n");

		printf("\t  ");
		for (i = 0; i < strlen(strAlphabet); i++) {
			printf("%c ", strAlphabet[i]);
			if ((i + 1) % 11 == 0) printf("\n\n\t  ");
		} // for(남은 알파벳들 표시(a~z))
		printf("\n\n");

		printf("\n\t  ");
		for (i = 0; i < nLength; i++) printf("%c ", strInput[i]); // strInput 출력
		printf("\n\n");

		if (!strcmp(strWords[nSelectedIndex], strInput)) break; // escape code
		printf("\t  >>");
		//scanf("%c", &chInput);
		scanf("%s", strChar); // 사용자가 문자 입력

		if (nCount == 0 && strlen(strChar) != 1) {
			printf("\n\n");
			printf("\t  The first input can be ONE CHARACTER ONLY!!\n\n");
			system("pause");
			continue;
		} // 첫 번째 입력은 문자 하나만 오도록

		nCount++; // 카운트 증가

		if (strlen(strChar) == 1) { // character(문자 하나 입력)

			chInput = strChar[0];

			strAlphabet[chInput - 'a'] = ' '; // 입력받은 문자에 해당하는 인덱스를 공백으로 변경

			for (i = 0; i < nLength; i++) {
				if (chInput == strWords[nSelectedIndex][i]) {
					strInput[i] = chInput;
				} // if
			} // for
		}
		else { // string
			if (!strcmp(strChar, strWords[nSelectedIndex])) // 입력한 게 정답일 경우
				strcpy(strInput, strChar);
			else {
				nCount *= 2;
				printf("\n\n");
				printf("\t  The COUNT doubles because you're wrong!!\n\n");
				printf("\t  COUNT >> %d\n\n", nCount);
				printf("\t  =========================\n\n");
				system("pause");
			}
		}
	} // while
	printf("\n\n");
	printf("\t=========================\n\n");
	printf("\t  You got it in %d times\n\n", nCount);
	printf("\t=========================\n\n");
} // wordGame()

void OXGame()
{
	char strOX[11] = "0123456789";
	char chPlayer = 'O', chWin = '\0';
	int nIndex;

	while (chWin == '\0') {

		displayOX(strOX);

		chWin = winCheck(strOX);
		if (chWin != '\0')
			break;

		while (TRUE) {
			nIndex = playOX(chPlayer);
			if (strOX[nIndex] != 'O' && strOX[nIndex] != 'X') {
				strOX[nIndex] = chPlayer; //입력한 숫자를 o로 바꾸기
				break;
			}
		}
		chPlayer = (chPlayer == 'O') ? 'X' : 'O'; //player가 원래 o였다면 x로 바꾸기

	}

	if (chWin == 'D') {
		printf("\n\n");
		printf("\t DRAW!!\n\n"); // 무승부
	}
	else {
		printf("\n\n");
		printf("\t %c WIN!!\n\n", chWin); // 승리 표시
	}

}//OXGame()

void displayOX(char strOX[])
{
	int i;

	system("cls"); // 화면 지우기
	printf("\n\n");
	printf("\t=========================\n");
	printf("\t        OX Game\n");
	printf("\t=========================\n\n");
	printf("    ");
	for (i = 1; i <= 9; i++) {
		printf("       %c", strOX[i]);
		if (!(i % 3))
			printf("\n\n    ");
	} // 화면에 1부터 9까지 표시
	printf("\t=========================\n");

}//displayOX()

int playOX(char player)
{
	int index = 0;

	while (index < 1 || index>9) { // 1부터 9사이의 숫자로 범위 지정
		printf("\n\n");
		printf("\t%c's turn>> ", player);
		scanf("%d", &index); // 사용자에게 숫자 고르도록 함
	}

	return index;
}//playOX()

char winCheck(char strOX[])
{
	char result = '\0';
	int i;

	if (strOX[1] == strOX[2] && strOX[2] == strOX[3])
		result = strOX[1];
	else if (strOX[4] == strOX[5] && strOX[5] == strOX[6])
		result = strOX[4];
	else if (strOX[7] == strOX[8] && strOX[8] == strOX[9])
		result = strOX[7];
	else if (strOX[1] == strOX[4] && strOX[4] == strOX[7])
		result = strOX[1];
	else if (strOX[2] == strOX[5] && strOX[5] == strOX[8])
		result = strOX[2];
	else if (strOX[3] == strOX[6] && strOX[6] == strOX[9])
		result = strOX[3];
	else if (strOX[1] == strOX[5] && strOX[5] == strOX[9])
		result = strOX[1];
	else if (strOX[3] == strOX[5] && strOX[5] == strOX[7])
		result = strOX[3];
	// 3목이 되는 경우 모두 표시

	else if ((strOX[1] != '1') && (strOX[2] != '2') && (strOX[3] != '3')
		&& (strOX[4] != '4') && (strOX[5] != '5') && (strOX[6] != '6')
		&& (strOX[7] != '7') && (strOX[8] != '8') && (strOX[9] != '9'))
		result = 'D'; // 모든 칸이 꽉 채워진 경우 무승부

	return result;

}//winCheck()

void about()
{
	printf("\n\n");
	printf("\t=========================\n");
	printf("\t          About\n\n");
	printf("\t=========================\n\n");
	printf("\tMade By 박병준\n\n");
	printf("\t2019312014\n\n");
	printf("\tCOMEDU\n\n");
	printf("\tAll Rights Reserved\n\n");
	printf("\t=========================\n\n");
} // about()