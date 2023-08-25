#include "�ָܼ޴�_�۳���⺹��.h" // ��� ���� �����ϱ�

int main()
{
	int nSelectedMainMenu;
	int bIterationFlag = TRUE;

	srand(time(NULL)); // seed (���� rand()�Լ����� �������� ���ڰ� ���� )

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
			nFaceValue = (rand() % 6) + 1; // �ֻ����� 1~6 �� �ϳ� �������� ������
			nSum += nFaceValue; // ���� �ֻ��� ���� nSum�� ��� ������
			nCount++; // ī��Ʈ ����
		} // while(nSum�� 100�� �� ������ ī������)
	} // for(�� 10�� �� �ùķ��̼�)

	printf("\n");
	printf("\t �ֻ����� �������� 100��\n");
	printf("\t �������� �ùķ��̼� ���\n");
	printf("\t �� %.2lf���� ������ �˴ϴ�.\n\n", nCount / 100000.0);
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

	//Case1: �ȹٲٱ�
	for (i = 0; i < 100000; i++) {
		nChoiceDoor = rand() % 3; // 0~2
		nPrizeDoor = rand() % 3; // 0~2
		if (nChoiceDoor == nPrizeDoor) nChoiceCount++;
	} // for
	printf("\t  CHOICE >> %.2lf %%\n\n", nChoiceCount / 1000.0); // Ȯ��(%) ���

	//Case2: �ٲٱ�
	for (i = 0; i < 100000; i++) {
		nChoiceDoor = rand() % 3; // 0~2
		nPrizeDoor = rand() % 3; // 0~2

		nRevealDoor = 0;
		while (nRevealDoor == nChoiceDoor ||
			nRevealDoor == nPrizeDoor) nRevealDoor++; // ������� 0�������� ����Ͽ� ���̽��� ������� �ƴ� ���� ��ġ��

		nSwitchDoor = 0;
		while (nSwitchDoor == nChoiceDoor ||
			nSwitchDoor == nRevealDoor) nSwitchDoor++; // ����ġ����� ���̽�, ������ �ٸ�

		if (nSwitchDoor == nPrizeDoor) nSwitchCount++; // ����ġ ��� �����̸� ī��Ʈ ����
	} // for
	printf("\t  Switch >> %.2lf %%\n\n", nSwitchCount / 1000.0); // Ȯ�� ���(%)

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

	nRandom = (rand() % 100) + 1;//������ 1~100
	printf("%d\n", nRandom); // ���� ��� ���

	while (TRUE) {
		system("cls"); // clear screen
		printf("\n\n");
		printf("\t=========================\n");
		printf("\t       Up Down Game\n");
		printf("\t=========================\n\n");
		printf("\t(%d ~ %d)\n\n", nmin, nmax);
		printf("\t Input(1~100) >> ");

		scanf("%d", &nInput); // ����ڰ� ���� input�ϰ�
		nCount++; // ī��Ʈ ����

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
		system("pause"); //getch(); => �ܼ�â ���߱�
	}//while(���� ���� ������)

} // upDownGame()

typedef struct {
	char word[80];
	int len;
}newWord;

char wordList[20][80] = {
	"detect",
	"reinforcement",
	"accident",
	"inconvenience",
	"consciousness",
	"policy",
	"eject",
	"approached",
	"suffrage",
	"ordinary",
	"abandon",
	"province",
	"hail",
	"rational",
	"distribution",
	"performance",
	"urban",
	"facial",
	"midnight",
	"judgements"
};

void wordGame()
{
	newWord strWords[20];
	
	for (int i = 0; i < 20; i++) {
		strcpy(strWords[i].word, wordList[i]);
		strWords[i].len = strlen(strWords[i].word);
	}

	int bubblesort[20];
	for (int i = 0; i < 20; i++) {
		bubblesort[i] = strWords[i].len;
	}

	for (int j = 0; j < 19; j++) {
		for (int k = 0; k < 19; k++) {
			if (bubblesort[k] > bubblesort[k + 1]) {
				int temp = bubblesort[k];
				bubblesort[k] = bubblesort[k + 1];
				bubblesort[k + 1] = temp;
			}
		}
	}

	int highindex, midindex, lowindex;

	lowindex = bubblesort[5];
	midindex = bubblesort[12];
	highindex = bubblesort[19];

	char highword[10][80];
	char midword[10][80];
	char lowword[10][80];

	int l = 0, m = 0, h = 0;

	for (int i = 0; i < 20; i++) {
		if (strWords[i].len <= lowindex) {
			strcpy(lowword[l], strWords[i].word);
			l++;
		}
		else if (strWords[i].len <= midindex) {
			strcpy(midword[m], strWords[i].word);
			m++;
		}
		else {
			strcpy(highword[h], strWords[i].word);
			h++;
		}
	}

	system("cls");
	printf("lowindex : %d��\n", l);
	printf("midindex : %d��\n", m);
	printf("highindex : %d��\n", h);
	system("pause");

	//��������� �ܾ� ��� ����ü strWords[20] ����� �ܾ�� �����Ϸ� �з��� �۾�
	
	//������ ���� �޴� ǥ���ϱ�

	system("cls");
	printf("\n\n");
	printf("\t=========================\n");
	printf("\t        Word Game\n");
	printf("\t=========================\n\n");

	printf("\tlow level : 1\n");
	printf("\tmid level : 2\n");
	printf("\thigh level : 3\n\n");

	printf("\t1 �Ǵ� 2 �Ǵ� 3 �Է�\n\n");

	int order;
	printf("\t  >>");
	scanf("%d", &order);

	if (order == 1) {
		//low game �Լ�(low game �Ϸ� �� mid game���� �̵��ϵ���, mid game �� high game)
		lowGame(lowword, l);
		midGame(midword, m);
		highGame(highword, h);
	}

	else if (order == 2) {
		//mid game �Լ�(mid game �Ϸ� �� high game���� �̵��ϵ���)
		midGame(midword, m);
		highGame(highword, h);
	}

	else if (order == 3) {
		//high game �Լ�(high game �Ϸ� �� �����ϵ���)
		highGame(highword, h);
	}

	else {
		printf("���� �߸� �Է���\n");
	}

	
} // wordGame()

void lowGame(char lowword[][80], int l)
{
	Gaming(lowword, l);

	system("cls");
	printf("\n\n");
	printf("\t  Go to the next(mid) Level!!\n\n");
	system("pause");
}

void midGame(char midword[][80], int m)
{
	Gaming(midword, m);

	system("cls");
	printf("\n\n");
	printf("\t  Go to the next(high) Level!!\n\n");
	system("pause");
}

void highGame(char highword[][80], int h)
{
	Gaming(highword, h);

	system("cls");
	printf("\n\n");
	printf("\t  Congratulationsl!!\n\n");
	printf("\t  You Succeded the last Levell!!\n\n");
}

void Gaming(char strWords[][80], int num)
{
	char strInput[80], chInput, strChar[80];
	char strAlphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int nSelectedIndex, nLength;
	int i, nCount = 0;
	// strWords[nSelectedIndex]�� ���� ��� 'e','d','c','a','t','i','o','n','\0'
	// strInput�� '_''_'...'\0'
	// chInput�� �Է¹��� ���ڸ� strInput�� �߰�
	// strChar�� ���ڿ� �Է��� ����

	nSelectedIndex = rand() % (num + 1); // 0~5
	system("cls");
	printf("%s\n", strWords[nSelectedIndex]); // ��� ���� ����

	nLength = strlen(strWords[nSelectedIndex]); // ������ ����
	printf("%d\n", nLength);
	system("pause");

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
		} // for(���� ���ĺ��� ǥ��(a~z))
		printf("\n\n");

		printf("\n\t  ");
		for (i = 0; i < nLength; i++) printf("%c ", strInput[i]); // strInput ���
		printf("\n\n");

		if (!strcmp(strWords[nSelectedIndex], strInput)) break; // escape code
		printf("\t  >>");
		//scanf("%c", &chInput);
		scanf("%s", strChar); // ����ڰ� ���� �Է�

		if (nCount == 0 && strlen(strChar) != 1) {
			printf("\n\n");
			printf("\t  The first input can be ONE CHARACTER ONLY!!\n\n");
			system("pause");
			continue;
		} // ù ��° �Է��� ���� �ϳ��� ������

		nCount++; // ī��Ʈ ����

		if (strlen(strChar) == 1) { // character(���� �ϳ� �Է�)

			chInput = strChar[0];

			strAlphabet[chInput - 'a'] = ' '; // �Է¹��� ���ڿ� �ش��ϴ� �ε����� �������� ����

			for (i = 0; i < nLength; i++) {
				if (chInput == strWords[nSelectedIndex][i]) {
					strInput[i] = chInput;
				} // if
			} // for
		}
		else { // string
			if (!strcmp(strChar, strWords[nSelectedIndex])) // �Է��� �� ������ ���
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
	system("pause");
}

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
				strOX[nIndex] = chPlayer; //�Է��� ���ڸ� o�� �ٲٱ�
				break;
			}
		}
		chPlayer = (chPlayer == 'O') ? 'X' : 'O'; //player�� ���� o���ٸ� x�� �ٲٱ�

	}

	if (chWin == 'D') {
		printf("\n\n");
		printf("\t DRAW!!\n\n"); // ���º�
	}
	else {
		printf("\n\n");
		printf("\t %c WIN!!\n\n", chWin); // �¸� ǥ��
	}

}//OXGame()

void displayOX(char strOX[])
{
	int i;

	system("cls"); // ȭ�� �����
	printf("\n\n");
	printf("\t=========================\n");
	printf("\t        OX Game\n");
	printf("\t=========================\n\n");
	printf("    ");
	for (i = 1; i <= 9; i++) {
		printf("       %c", strOX[i]);
		if (!(i % 3))
			printf("\n\n    ");
	} // ȭ�鿡 1���� 9���� ǥ��
	printf("\t=========================\n");

}//displayOX()

int playOX(char player)
{
	int index = 0;

	while (index < 1 || index>9) { // 1���� 9������ ���ڷ� ���� ����
		printf("\n\n");
		printf("\t%c's turn>> ", player);
		scanf("%d", &index); // ����ڿ��� ���� ������ ��
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
	// 3���� �Ǵ� ��� ��� ǥ��

	else if ((strOX[1] != '1') && (strOX[2] != '2') && (strOX[3] != '3')
		&& (strOX[4] != '4') && (strOX[5] != '5') && (strOX[6] != '6')
		&& (strOX[7] != '7') && (strOX[8] != '8') && (strOX[9] != '9'))
		result = 'D'; // ��� ĭ�� �� ä���� ��� ���º�

	return result;

}//winCheck()

void about()
{
	printf("\n\n");
	printf("\t=========================\n");
	printf("\t          About\n\n");
	printf("\t=========================\n\n");
	printf("\tMade By �ں���\n\n");
	printf("\t2019312014\n\n");
	printf("\tCOMEDU\n\n");
	printf("\tAll Rights Reserved\n\n");
	printf("\t=========================\n\n");
} // about()