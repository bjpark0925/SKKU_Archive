#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

//이진 트리의 노드를 표현한 구조체
typedef struct _bTreeNode
{
    char data;
    struct _bTreeNode* parent;
    struct _bTreeNode* sibling; // right
    struct _bTreeNode* child; // left

}treeNode;

treeNode* Root; // root를 전역변수로 선언

//트리의 첫 노드(root) 생성
void createNode(char data)
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    Root = newNode;
    newNode->data = data;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    newNode->child = NULL;

}

// 탐색 함수(만약 특정 노드에 자식노드를 삽입하고 싶은 경우 먼저 그 부모노드가 되는 노드를 찾아야 하기 때문에 필요)
treeNode* searchNode(treeNode* R, char parent)
{
    if (R == NULL) // 루트가 없는 경우
        return NULL;

    if (R->data == parent) // 루트가 찾고자 하는 부모인 경우
        return R;

    treeNode* right = searchNode(R->sibling, parent);
    treeNode* left = searchNode(R->child, parent);

    if (right != NULL) // sibling 중 찾고자 하는 노드를 찾은 경우
        return right;
    if (left != NULL) // child 중 찾고자 하는 노드를 찾은 경우
        return left;

    return NULL; // 찾고자 하는 노드가 없는 경우
}

//새로운 노드 생성 및 연결
void insertNode(treeNode* P, char data) // P는 부모 노드
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // 부모 연결
    newNode->sibling = NULL;
    newNode->child = NULL;

    treeNode* cur = P->child;

    if (cur == NULL) // 부모에 자식이 없으면
        P->child = newNode;

    while (cur != NULL) { // 부모에 이미 자식이 있다면
        if (cur->sibling == NULL) { // 형제 노드의 가장 마지막 위치에 연결
            cur->sibling = newNode;
            break;
        }
        cur = cur->sibling;
    }
}

//형제 관계에 있는 노드 출력(자기 자신도 출력)
void getSibling(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // S(D)를 입력받은 경우, key는 D노드를 가리킴

    if (key == NULL) {
        printf("sibling 없음");
        return;
    }

    treeNode* P = key->parent; // P는 key노드의 parent노드
    if (P == NULL && R != NULL) { // key노드가 root와 같은 레벨인 경우
        key = R;

        while (key != NULL) {
            if (key == NULL)
                break;
            printf("%c", key->data);
            key = key->sibling;
        }
    }

    else {
        treeNode* C = P->child; // C는 P의 첫번째 child

        while (C != NULL) {
            if (C == NULL) { // C와 형제관계인 노드들 순회
                break;
            }
            printf("%c", C->data);
            C = C->sibling;
        }
    }
}

//트리 출력
void PrintTree(treeNode* node)
{
    if (node == NULL)
        return; // 재귀 탈출

    if (node == Root || (node->parent != NULL && node == node->parent->child))
        printf("(");

    printf("%c ", node->data); // 전위 순회
    PrintTree(node->child);
    PrintTree(node->sibling);
    
    if (node->sibling==NULL)
        printf(")");
}

//부모 노드 출력
void getParent(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // P(E)를 입력받은 경우, key는 E노드를 가리킴

    if (key == NULL || key->parent == NULL)
        printf("Error\n");

    else
        printf("%c\n", key->parent->data);
}

//자식 노드 출력
void getChild(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // C(A)를 입력받은 경우, key는 A노드를 가리킴

    if (key == NULL || key->child == NULL)
        printf("Error");

    else {
        treeNode* C = key->child; // C는 key의 첫번째 child

        while (C != NULL) {
            if (C == NULL)
                break;
            printf("%c", C->data);
            C = C->sibling;
        }
    }
}

//특정 노드의 레벨
int level_of_node(treeNode* R, char data)
{
    int cnt = 0;
    treeNode* key = searchNode(R, data); // L(G)를 입력받은 경우, key는 G노드를 가리킴

    if (key == NULL) // 입력한 노드가 트리에 없으면 -1 반환
        return -1;

    if (key->parent == NULL && R != NULL) {
        return 0;
    }
    
    else {
        key = key->parent;

        while (key != NULL) {
            if (key == NULL)
                break;
            cnt++;
            key = key->parent;
        }

        return cnt;
    }
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

//노드의 삭제
void DeleteNode(treeNode* Node)
{
    if (Node->sibling == NULL && Node->child == NULL) {
        if (Node->parent == NULL) {//root 노드와 같은 레벨대의 노드를 삭제하는 경우
            Node = Root; // 삭제할 노드에 연결된 간선을 끊기 위해 Root부터 탐색
            while (Node->sibling->sibling != NULL) {
                if (Node->sibling->sibling == NULL)
                    break;
                Node = Node->sibling;
            }

            Node->sibling = NULL; // 삭제할 노드에 연결된 간선 끊기
        }

        else { // 레벨 1 이상의 노드를 삭제하는 경우
            Node = Node->parent->child; // 삭제할 노드에 연결된 간선을 끊기 위해 삭제하고자 하는 노드의 첫째 형제부터 탐색
            while (Node->sibling->sibling != NULL) {
                if (Node->sibling->sibling == NULL)
                    break;
                Node = Node->sibling;
            }
            Node->sibling = NULL; // 삭제할 노드에 연결된 간선 끊기
        }
    }

    else
        printf("Error\n");
}

//조상 노드 출력
void getAncestors(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // A(H)를 입력받은 경우, key는 H노드를 가리킴

    if (key == NULL || key->parent == NULL)
        printf("Error");

    else {
        key = key->parent;

        while (key != NULL) {
            if (key == NULL)
                break;
            printf("%c", key->data);
            key = key->parent;
        }
    }
}

//자손 노드 출력
void getDescendants(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // D(B)를 입력받은 경우, key는 B노드를 가리킴

    if (key == NULL || key->child == NULL)
        printf("Error");

    else {
        key = key->child;

        while (key != NULL) {
            if (key == NULL)
                break;
            printf("%c", key->data);
            key = key->child;
        }
    }
}

//특정 노드의 차수
int degree_of_node(treeNode* R, char data)
{
    int cnt = 0;
    treeNode* key = searchNode(R, data); // D(B)를 입력받은 경우, key는 B노드를 가리킴
    treeNode* C = key->child; // C는 key의 첫번째 child

    if (key == NULL || C == NULL)
        return 0;

    while (C != NULL) {
        if (C == NULL)
            break;
        cnt++;
        C = C->sibling;
    }
    return cnt;
}

//밑의 트리 최고 차수 출력을 위해 위를 변형한 함수
int degree_of_node2(treeNode* R)
{
    int cnt = 0;
    treeNode* C = R->child; // C는 key의 첫번째 child

    if (R == NULL || C == NULL)
        return 0;

    while (C != NULL) {
        if (C == NULL)
            break;
        cnt++;
        C = C->sibling;
    }
    return cnt;
}

//트리의 최고 차수
int degree_of_tree(treeNode* R)
{
    int size = level_of_tree(R);
    int* ptr = malloc(sizeof(int) * size); // 각 레벨 별 차수들을 저장하는 포인터 배열 생성
    int i = 0;

    if (R == NULL)
        return 0;

    for (int j = 0; j < size; j++) {
        ptr[i] = degree_of_node2(R);

        R = R->child;
        i++;
    }

    //만들어진 array를 바탕으로, degree의 최대값 구하기
    if (ptr[0] == NULL) {
        return 0;
    }
    else {
        int max = ptr[0];
        for (int k = 0; k < size - 1; k++) {
            if (ptr[k] < ptr[k + 1])
                max = ptr[k + 1];
        }
        return max;
    }
}

//트리의 노드 개수
int countNode(treeNode* R) // 트리의 최고 차수 구하는 방법과 유사
{
    int size = level_of_tree(R) + 1;
    int* ptr = malloc(sizeof(int) * size); // 각 레벨 별 차수들을 저장하는 포인터 배열 생성
    int i = 0;
    int cnt = 0;

    treeNode* temp = R;

    if (R == NULL)
        return 0;

    if (temp->sibling != NULL) {
        while (temp != NULL) {
            if (temp == NULL)
                break;
            cnt++;
            temp = temp->sibling;
        }
        ptr[i] = cnt;
        i++;
    }

    else {
        ptr[i] = 1;
        i++;
    }

    temp = R;

    for (int j = 0; j < level_of_tree(R); j++) {
        ptr[i] = degree_of_node2(temp);

        temp = temp->child;
        i++;
    }

    //만들어진 array 요소들의 합 구하기

    int sum = 0;
    for (int k = 0; k < size; k++) {
        sum += ptr[k];
    }

    return sum;
}

//형제노드에 새로운 노드 추가
void insertSibling(treeNode* R, char data[]) // insertNode함수와 getSibling함수의 과정을 응용
{
    treeNode* key = searchNode(R, data[2]); // =+F(IJ)를 입력받은 경우, key는 F노드를 가리킴

    if (key == NULL) {
        printf("Error\n");
        return;
    }

    if (key->parent==NULL) {
        for (int i = 4; i < strlen(data) - 1; i++) {
            treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
            newNode->data = data[i];
            newNode->sibling = NULL;
            newNode->child = NULL;

            while (R != NULL) { // 형제 노드의 가장 마지막 위치에 연결하는 과정
                if (R->sibling == NULL) {
                    R->sibling = newNode;
                    break;
                }
                R = R->sibling;
            }
        }
    }

    else {
        treeNode* P = key->parent; // P는 key노드의 parent노드
        for (int i = 4; i < strlen(data) - 1; i++) {
            treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
            newNode->data = data[i];
            newNode->parent = P; // 부모 연결
            newNode->sibling = NULL;
            newNode->child = NULL;

            treeNode* C = P->child; // C는 P의 첫번째 child

            while (C != NULL) { // 형제 노드의 가장 마지막 위치에 연결하는 과정
                if (C->sibling == NULL) {
                    C->sibling = newNode;
                    break;
                }
                C = C->sibling;
            }
        }
    }

}

//joinTrees함수를 위한 함수들

//tree2 노드들의 초기 상태 설정
treeNode* makeTree2(char data)
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    newNode->child = NULL;

    return newNode;
}

void makeChildSubTree(treeNode* P, treeNode* C)
{
    P->child = C;
    C->parent = P;
}

void makeSiblingTree(treeNode* first, treeNode* second) // first, second는 형제 중 첫째, 둘째를 의미
{
    first->sibling = second;
    second->parent = first->parent;
}

//트리 삭제
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Root = NULL;

    return Root;
}

//기능 설명
void UserSetting()
{
    printf("<일반트리 ADT>\n");
    printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
    printf("명령어 : +^, +, S(), T, P(), C(), L(), L, -, A(), D(), G(), G, #, =+, J, K\n\n");
    printf("Q : 프로그램 종료\n");
    printf("+^A: A노드를 루트로 하는 트리 생성(A가 아니어도 됨)\n");
    printf("+A(BCD) : A의 자식노드로 B, C, D 삽입(변수 변경 가능)\n");
    printf("S(D) : D노드의 형제노드 출력(자기 자신도 출력)\n");
    printf("T: 트리 출력\n");
    printf("P(E) : E의 부모노드 출력(E가 아니어도 됨)\n");
    printf("C(A) : A의 자식노드 출력(A가 아니어도 됨)\n");
    printf("L(G) : G 노드의 레벨 출력(G가 아니어도 됨)\n");
    printf("L : 트리의 최고 레벨(높이) 출력\n");
    printf("-B : B노드 삭제(단말 노드만 삭제 가능)\n");
    printf("A(H) : H의 조상노드 출력(H가 아니어도 됨)\n");
    printf("D(B) : B의 후손노드 출력(B가 아니어도 됨)\n");
    printf("G(B) : B의 차수 출력(B의 child노드 개수)\n");
    printf("G : 트리의 최고 차수 출력\n");
    printf("# : 트리의 전체 노드 개수 출력\n");
    printf("=+F(IJ) : F의 형제노드로 I, J를 삽입(변수 변경 가능)\n");
    printf("J(P) : P를 새로운 루트노드로 하여, 따로 떨어져 있던 기존의 트리와 새로 만든 트리를 결합(P가 아니어도 됨)\n");
    printf("K : 트리 전체 삭제\n\n");
    printf("<일반트리를 이진트리로 구현했기 때문에, 이진트리를 위한 ADT를 따로 만들지 않았습니다.>\n");
    printf("<T 입력 시 트리 출력이 완벽하게 되도록 수정하였고\n DELETE_NODE 시 강제종료 되는 경우나 JOIN_TREE 시 COUNT_NODE가 다른 값을 리턴하는 경우를 모두 수정하였습니다.>\n\n");
}

int main() {

    UserSetting();

    char order[30];

    while (1)
    {
        printf("order: ");
        scanf("%s", order);

        if (order[0] == 'Q') {
            printf("프로그램을 종료합니다.\n");
            break;
        }//escape code

        if (order[0] == '+' && order[1] == '^' && strlen(order) == 3) {
            if (Root == NULL)
                createNode(order[2]);
            else
                printf("Root에 값이 존재합니다.\n");
        }

        if (order[0] == '+' && order[2] == '(' && order[strlen(order) - 1] == ')' && searchNode(Root, order[1]) != NULL) { // +A(BCD)로 입력받은 경우
            if (searchNode(Root, order[1]) == NULL) {
                printf("찾고자 하는 부모 노드가 없습니다.\n");
                continue;
            }

            for (int i = 3; i < strlen(order) - 1; i++) {
                insertNode(searchNode(Root, order[1]), order[i]); // searchNode로 부모노드를 찾은 후, 그 부모노드에 입력받은 것들을 insert
            }
        }

        if (order[0] == 'S' && order[1] == '(' && order[3] == ')') { // S(D)
            getSibling(Root, order[2]);
            printf("\n");
        }

        if (order[0] == 'T') {
            PrintTree(Root);
            printf("\n");
        }

        if (order[0] == 'P' && order[1] == '(' && order[3] == ')') { // P(E)
            getParent(Root, order[2]);
        }

        if (order[0] == 'C' && order[1] == '(' && order[3] == ')') { // C(E)
            getChild(Root, order[2]);
            printf("\n");
        }

        if (order[0] == 'L' && order[1] == '(' && order[3] == ')') { // L(G)
            if (level_of_node(Root, order[2]) == -1)
                printf("Error\n");
            printf("%d\n", level_of_node(Root, order[2]));
        }

        if (order[0] == 'L' && strlen(order) == 1) {
            if (level_of_tree(Root) == -1)
                printf("Error\n");
            printf("%d\n", level_of_tree(Root));
        }

        if (order[0] == '-') { // -B
            DeleteNode(searchNode(Root, order[1]));
        }

        if (order[0] == 'A' && order[1] == '(' && order[3] == ')') { // A(H)
            getAncestors(Root, order[2]);
            printf("\n");
        }

        if (order[0] == 'D' && order[1] == '(' && order[3] == ')') { // D(B)
            getDescendants(Root, order[2]);
            printf("\n");
        }

        if (order[0] == 'G' && order[1] == '(' && order[3] == ')') { // G(B)
            printf("%d\n", degree_of_node(Root, order[2]));
        }

        if (order[0] == 'G' && strlen(order) == 1) {
            printf("%d\n", degree_of_tree(Root));
        }

        if (order[0] == '#') {
            printf("%d\n", countNode(Root));
        }

        //insertSibling은 insertNode와 비슷하게 구성됨
        if (order[0] == '=' && order[1] == '+' && order[strlen(order) - 1] == ')' && searchNode(Root, order[2]) != NULL) { // =+F(IJ)
            insertSibling(Root, order);
        }

        //임의로 새로운 트리를 생성해서 기존의 트리와 결합
        if (order[0] == 'J' && order[1] == '(' && order[strlen(order) - 1] == ')') { // J(P)
            treeNode* t1 = makeTree2('1');
            treeNode* t2 = makeTree2('2');
            treeNode* t3 = makeTree2('3');
            treeNode* t4 = makeTree2('4');

            makeSiblingTree(t1, t2);
            makeSiblingTree(t2, t3);
            makeSiblingTree(t3, t4);
            //새로운 트리는 (1, 2, 3, 4) 형태로 구성됨

            treeNode* merge = makeTree2(order[2]);
            //merge와 기존 root노드 연결
            merge->child = Root;
            Root->parent = merge;

            //merge와 새로 만든 tree2 연결
            makeSiblingTree(merge, t1);

            Root = merge; // Root는 merge로 업데이트
        }

        if (order[0] == 'K') {
            Root = Clear(Root);
        }

    }

    system("pause");
    return 0;
}