#pragma once // ��� ���� �� �� ���� ó��
#pragma warning (disable: 4996) // for scanf()
#include<stdio.h>
#include<stdlib.h> // for system()
#include<time.h> // for time()

//====================================
//  Declaration of CONSTANTS
//====================================
#define TRUE 1
#define FALSE 0

#define DIE_SIMULATION 1
#define GAME_SHOW 2
#define UP_DOWN_GAME 3
#define WORD_GAME 4
#define OX_GAME 5
#define ABOUT 6
#define EXIT 0

// ��ũ�� ��� �������

//====================================
//  Declaration of User Defined Functions
//====================================
int displayMainMenu();
void dieSimulation();
void gameShow();
void upDownGame();
void wordGame();
void OXGame();
void about();
//------------------------------------
//void wordGame();
void lowGame(char lowword[][80], int l);
void midGame(char midword[][80], int m);
void highGame(char highword[][80], int h);
void Gaming(char strWords[][80], int num);
//void OXGame();
void displayOX(char strOX[]);
int playOX(char player);
char winCheck(char strOX[]);
