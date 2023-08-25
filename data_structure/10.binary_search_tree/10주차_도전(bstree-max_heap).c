#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

#define Max_Size 7

//이진 트리의 노드를 표현한 구조체
typedef struct _bsTreeNode
{
    int data;
    struct _bsTreeNode* parent;
    struct _bsTreeNode* right;
    struct _bsTreeNode* left;

}treeNode;

treeNode* Root; // root를 전역변수로 선언

//숫자를 입력받는 함수
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
    newNode->right = NULL;
    newNode->left = NULL;

}

//삽입 함수를 위해 자기 자리 탐색하기(정확히는, 자기 자리의 부모 탐색하기)
treeNode* findParent(treeNode* node, int data)
{
    // 자기가 들어갈 자리의 부모를 알아야 하기 때문에, before가 필요
    treeNode* before = NULL; // before 초기화

    while (node != NULL) {
        if (data < node->data) {
            before = node;
            node = node->left;
        }
        else if (data > node->data) {
            before = node;
            node = node->right;
        }
    }

    return before; // 자기가 들어갈 자리의 부모인 before 반환(단, 들어갈 위치가 오른쪽인지 왼쪽인지에 대한 정보는 없음)
}

//새로운 노드 생성 및 연결
void insertNode(treeNode* P, int data) // P는 부모 노드를 의미
{
    if (P == NULL) { // ex. 트리에 중복된 숫자가 있는 경우
        printf("Error\n");
        return;
    }

    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // 부모 연결
    newNode->left = NULL;
    newNode->right = NULL;

    if (data < P->data) {
        P->left = newNode;
    }
    else if (data > P->data) {
        P->right = newNode;
    }
}

//트리 출력
void PrintTree(treeNode* node)
{
    if (node == NULL)
        return; // 재귀 탈출

    printf("(");

    printf("%d ", node->data); // 전위 순회
    PrintTree(node->left);
    PrintTree(node->right);

    printf(")");
}

//중위 순회(왼 - 루 - 오)
void inorder_traverse(treeNode* node)
{
    if (node == NULL)
        return; // 재귀 탈출

    inorder_traverse(node->left);
    printf("%d ", node->data);
    inorder_traverse(node->right);

}

//오 - 루 - 왼 순의 중위 순회
void RightRootLeft_traverse(treeNode* node)
{
    if (node == NULL)
        return; // 재귀 탈출

    RightRootLeft_traverse(node->right);
    printf("%d ", node->data);
    RightRootLeft_traverse(node->left);

}

//최소값 탐색
int getMin(treeNode* node)
{
    if (node == NULL)
        return -1;

    if (node->left == NULL)
        return node->data;

    getMin(node->left);
}

//최대값 탐색
int getMax(treeNode* node)
{
    if (node == NULL)
        return -1;

    if (node->right == NULL)
        return node->data;

    getMax(node->right);
}

// 검색한 노드의 존재 여부 확인
int isNode(treeNode* node, int data)
{
    int exist = -1;

    while (node != NULL) {
        if (data < node->data) {
            node = node->left;
        }
        else if (data > node->data) {
            node = node->right;
        }
        else { // data==node->data
            exist = 1;
            break;
        }
    }

    return exist;
}

//노드 검색(경로 반환)
void findNode(treeNode* node, int data)
{
    int exist = isNode(node, data);

    if (exist > 0) {
        printf("Root");

        while (node != NULL) {
            if (data < node->data) {
                printf("->Left");
                node = node->left;
            }
            else if (data > node->data) {
                printf("->Right");
                node = node->right;
            }
            else { // data==node->data
                break;
            }
        }
    }

    else
        printf("Error"); // not exist
}

//노드 검색 버전 2(노드 반환)
treeNode* findNode2(treeNode* node, int data)
{
    treeNode* key = NULL; // 찾고자 하는 key노드 초기화

    while (node != NULL) {
        if (data < node->data) {
            node = node->left;
        }
        else if (data > node->data) {
            node = node->right;
        }
        else { // data==node->data
            key = node;
            break;
        }
    }

    return key;
}

//노드 삭제
void deleteNode(treeNode* node, int data)
{
    treeNode* key = NULL; // 삭제할 것
    treeNode* replace = NULL; // 삭제할 것을 대체할 것

    if (isNode(node, data) > 0) { // 삭제하고자 하는 노드가 존재하면
        key = findNode2(node, data);
        replace = key;

        //경우 1. 삭제할 노드의 자식이 없을 때
        if (key->left == NULL && key->right == NULL) {
            if (key->parent == NULL) { // 삭제할 노드가 root인 경우
                free(key);
            }
            else if (key->parent->left == key) { // 삭제할 노드가 부모의 왼쪽에 달린 경우
                key->parent->left = NULL;
                free(key);
            }
            else if (key->parent->right == key) { // 삭제할 노드가 부모의 오른쪽에 달린 경우
                key->parent->right = NULL;
                free(key);
            }
        }

        //경우 2. 삭제할 노드에 오른쪽 자식만 있을 때
        else if (key->left == NULL) {
            replace = replace->right; // replace는 key의 오른쪽 자식임

            key->data = replace->data;
            key->right = replace->right;
            replace->right->parent = key;
            free(replace);
        }

        //경우 3. 삭제할 노드에 왼쪽 자식이 있을 때
        else {

            // 삭제할 노드의 왼쪽 서브트리의 최대값을 replace로 하고자 함
            replace = replace->left;

            while (replace->right != NULL) {
                replace = replace->right;
            } // replace 찾음

            if (replace->parent == key) { // replace가 key의 왼쪽 자식일 경우
                key->data = replace->data;
                key->left = replace->left;
                free(replace);
            }

            else {
                replace->parent->right = replace->left;
                key->data = replace->data;
                free(replace);
            }
        }
    }


}

//트리의 높이
int Height(treeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = Height(node->left); // 재귀를 통해 왼쪽 서브트리의 높이 구함
    int right_height = Height(node->right); // 오른쪽도 마찬가지

    return 1 + (left_height > right_height ? left_height : right_height); // 둘 중 더 큰 것 반환
}

//검색한 노드의 오른쪽 자식 출력
void GetRightChild(treeNode* node, int data)
{
    if (node == NULL)
        printf("Error\n");
    else {
        treeNode* key = findNode2(node, data);

        if (key == NULL) {
            printf("Error\n");
        }
        else {
            if (key->right == NULL)
                printf("NULL\n");
            else
                printf("%d\n", key->right->data);
        }
    }
}

//검색한 노드의 왼쪽 자식 출력
void GetLeftChild(treeNode* node, int data)
{
    if (node == NULL)
        printf("Error\n");
    else {
        treeNode* key = findNode2(node, data);

        if (key == NULL) {
            printf("Error\n");
        }
        else {
            if (key->left == NULL)
                printf("NULL\n");
            else
                printf("%d\n", key->left->data);
        }
    }
}

//트리의 노드 개수
int countNode(treeNode* node) // 재귀 사용
{
    if (node == NULL)
        return 0;

    int result = 1;

    result += countNode(node->left) + countNode(node->right);

    return result;
}

//트리 삭제
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Root = NULL;

    return Root;
}

//검색한 노드의 레벨 출력(루트부터 검색한 노드까지 몇 번만에 도달했는지 확인)
int findLevel(treeNode* node, int data)
{
    int cnt = 0;

    while (node != NULL) {
        if (data < node->data) {
            node = node->left;
            cnt++;
        }
        else if (data > node->data) {
            node = node->right;
            cnt++;
        }
        else // data==node->data
            break;
    }

    return cnt;
}

//부모 노드 출력
void getParent(treeNode* R, int data)
{
    treeNode* key = findNode2(R, data);

    if (key == NULL || key->parent == NULL)
        printf("Error\n");

    else
        printf("%d\n", key->parent->data);
}

//기능 설명
void UserSetting()
{
    printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
    printf("명령어 : Q, +, P, I, R, N, X, F, -, H, G, L, #, C, E, $, @\n\n");
    printf("명령어만 우선 입력 후, 숫자만을 입력해야 합니다.\n\n");
    printf("Q : 프로그램 종료\n");
    printf("+: 입력받은 숫자에 대한 노드 삽입 or 입력받은 숫자를 루트로 하는 트리 생성\n");
    printf("P : 트리 출력\n");
    printf("I : 중위 순회(왼->루->오)\n");
    printf("R : 중위 순회(오->루->왼)\n");
    printf("N : 최소값 출력\n");
    printf("X : 최대값 출력\n");
    printf("F : 노드 검색(노드를 찾으면, 경로 반환)\n");
    printf("- : 노드 삭제\n");
    printf("H : 트리의 높이 출력\n");
    printf("G : 검색한 노드의 오른쪽 자식 출력\n");
    printf("L : 검색한 노드의 왼쪽 자식 출력\n");
    printf("# : 트리의 전체 노드 개수 출력\n");
    printf("C : 트리 전체 삭제\n\n");
    printf("<여기서부터는 자신만의 기능>\n");
    printf("E : 노드의 존재 여부\n");
    printf("$ : 노드의 레벨 출력\n");
    printf("@ : 노드의 부모 노드 출력\n");
    printf("입력받을 숫자는 중복되지 않도록 합니다.\n\n");
}

int main() {

    UserSetting();

    char order[30];
    int input;
    int heap[Max_Size];

    printf("[max heap 생성을 위해 %d개의 숫자를 입력해주세요]\n", Max_Size - 1);
    for (int i = 1; i < Max_Size; i++) {
        input = inputNum();
        heap[i] = input;
    }

    for (int i = Max_Size - 1; i > 1; i--) {
        if (heap[i / 2] < heap[i]) { //부모가 자식보다 작으면
            //swap
            int temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
        }
    }

    printf("max heap 출력 : ");
    for (int i = 1; i < Max_Size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    printf("max heap을 binary search tree에 삽입\n");
    createNode(heap[1]);
    for (int i = 2; i < Max_Size; i++) {
        insertNode(findParent(Root, heap[i]), heap[i]);
    }

    while (1)
    {
        printf("order: ");
        scanf("%s", order);

        if (order[0] == 'Q') {
            printf("프로그램을 종료합니다.\n");
            Root = Clear(Root);
            break;
        }//escape code

        if (order[0] == '+') {
            input = inputNum();
            if (Root == NULL)
                createNode(input);
            else
                insertNode(findParent(Root, input), input);
        }

        if (order[0] == 'P') {
            PrintTree(Root);
            printf("\n");
        }

        if (order[0] == 'I') {
            inorder_traverse(Root);
            printf("\n");
        }

        if (order[0] == 'R') {
            RightRootLeft_traverse(Root);
            printf("\n");
        }

        if (order[0] == 'N') {
            if (getMin(Root) == -1) {
                printf("Error\n");
                continue;
            }
            printf("%d\n", getMin(Root));
        }

        if (order[0] == 'X') {
            if (getMax(Root) == -1) {
                printf("Error\n");
                continue;
            }
            printf("%d\n", getMax(Root));
        }

        if (order[0] == 'F') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            findNode(Root, input);
            printf("\n");
        }

        if (order[0] == '-') {
            input = inputNum();
            deleteNode(Root, input);
        }

        if (order[0] == 'H') {
            printf("%d\n", Height(Root) - 1); // 트리의 레벨은 0레벨부터 시작이므로, -1
        }

        if (order[0] == 'G') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            GetRightChild(Root, input);
        }

        if (order[0] == 'L') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            GetLeftChild(Root, input);
        }

        if (order[0] == '#') {
            printf("%d\n", countNode(Root));
        }

        if (order[0] == 'C') {
            Root = Clear(Root);
        }

        if (order[0] == 'E') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            if (isNode(Root, input) > 0)
                printf("True\n");
            else
                printf("False\n");
        }

        if (order[0] == '$') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            printf("%d", findLevel(Root, input));
            printf("\n");
        }

        if (order[0] == '@') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }

            input = inputNum();
            getParent(Root, input);
        }

    }

    system("pause");
    return 0;
}