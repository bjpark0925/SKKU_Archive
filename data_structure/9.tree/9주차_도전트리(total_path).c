#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

//이진 트리의 노드를 표현한 구조체
typedef struct _bTreeNode
{
    int data;
    struct _bTreeNode* parent;
    struct _bTreeNode* sibling; // right
    struct _bTreeNode* child; // left

}treeNode;

treeNode* Root; // root를 전역변수로 선언

int inputNum()
{
    int input;
    printf("숫자 입력: ");
    scanf("%d", &input);

    return input;
}

//트리의 첫 노드(root) 생성
void createNode(int data)
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    Root = newNode;
    Root->data = data;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    newNode->child = NULL;

}

//기능 설명
void UserSetting()
{
    printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
    printf("명령어 : Q, +^, +, T, L, #, P()\n\n");
    printf("Q : 프로그램 종료\n");
    printf("+^: 입력받은 숫자를 루트로 하는 트리 생성(우선 +^만 입력해야함)\n");
    printf("+ : 특정노드에 자식노드를 삽입(우선 +만 입력해야 함)\n");
    printf("T : 트리 출력\n");
    printf("L : 트리의 최고 레벨 출력\n");
    printf("P : 특정노드까지 path의 합 계산(우선 P만 입력해야 함)\n\n");
    printf("기존에 만들었던 트리에서 char형 data를 int형으로 변경했습니다.\n");
    printf("입력받을 숫자는 중복되지 않도록 합니다.\n\n");
}

// 탐색 함수(만약 특정 노드에 자식노드를 삽입하고 싶은 경우 먼저 그 부모노드가 되는 노드를 찾아야 하기 때문에 필요)
treeNode* searchNode(treeNode* R, int data)
{
    if (R == NULL) // 루트가 없는 경우
        return NULL;

    if (R->data == data) // 루트가 찾고자 하는 부모인 경우
        return R;

    treeNode* right = searchNode(R->sibling, data);
    treeNode* left = searchNode(R->child, data);

    if (right != NULL) // sibling 중 찾고자 하는 노드를 찾은 경우
        return right;
    if (left != NULL) // child 중 찾고자 하는 노드를 찾은 경우
        return left;

    return 0; // 찾고자 하는 노드가 없는 경우
}

//새로운 노드 생성 및 연결
void insertNode(treeNode* P, int data) // P는 부모 노드
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // 부모 연결
    newNode->sibling = NULL;
    newNode->child = NULL;

    treeNode* cur = P->child;

    if (cur == NULL) // 루트에 자식이 없으면
        P->child = newNode;

    while (cur != NULL) { // 루트에 이미 자식이 있다면
        if (cur->sibling == NULL) { // 형제 노드의 가장 마지막 위치에 연결
            cur->sibling = newNode;
            break;
        }
        cur = cur->sibling;
    }
}

//트리 출력
void PrintTree(treeNode* R)
{
    if (R == NULL) // R이 NULL이면
        return; // 재귀 탈출

    if (R->child != NULL || R->sibling != NULL)
        printf("(");

    printf("%d", R->data); // 전위 순회
    PrintTree(R->child);
    PrintTree(R->sibling);

    if (R->child != NULL || R->sibling != NULL)
        printf(")");
}

//path 계산
int getPath(treeNode* R)
{
    int sum = 0;
    int data = inputNum();

    treeNode* key = searchNode(R, data); // P(5)를 입력받은 경우, key는 5노드를 가리킴

    if (key == NULL)
        return -1;

    while (key != NULL) {
        if (key == NULL)
            break;

        sum += key->data;
        key = key->parent;
    }

    return sum;
}

//트리의 최고 레벨(높이)
int level_of_tree(treeNode* R)
{
    int cnt = 0;
    treeNode* key = R;

    if (key == NULL)
        return -1;

    key = key->child;

    while (key != NULL) {
        if (key == NULL)
            break;
        cnt++;
        key = key->child;
    }

    return cnt;
}

//트리 삭제
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Clear(Root->sibling);
    Clear(Root->child);
    free(Root);

    return Root;
}

int main() {

    UserSetting();

    char order[30];
    int input;

    while (1)
    {
        printf("order: ");
        scanf("%s", order);

        if (order[0] == 'Q') {
            printf("프로그램을 종료합니다.\n");
            Root = Clear(Root);
            break;
        }//escape code

        if (order[0] == '+' && order[1] == '^') {
            input = inputNum();
            createNode(input);
        }

        if (order[0] == '+' && strlen(order)==1) {
            int parent;
            printf("부모 노드 입력: ");
            scanf("%d", &parent);

            if (searchNode(Root, parent) == NULL)
                break;

            int num;
            printf("부모노드에 들어갈 자식노드의 개수 입력: ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++) {
                input = inputNum();
                insertNode(searchNode(Root, parent), input); // searchNode로 부모노드를 찾은 후, 그 부모노드에 입력받은 것을 insert
            }
        }

        if (order[0] == 'T') {
            PrintTree(Root);
            printf("\n");
        }

        if (order[0] == 'L' && strlen(order) == 1) {
            if (level_of_tree(Root) == -1)
                printf("Error\n");
            printf("%d\n", level_of_tree(Root));
        }

        if (order[0] == 'P') {
            printf("%d\n", getPath(Root));
        }

    }

    system("pause");
    return 0;
}