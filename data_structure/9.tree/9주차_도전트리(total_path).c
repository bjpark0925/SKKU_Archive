#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

//���� Ʈ���� ��带 ǥ���� ����ü
typedef struct _bTreeNode
{
    int data;
    struct _bTreeNode* parent;
    struct _bTreeNode* sibling; // right
    struct _bTreeNode* child; // left

}treeNode;

treeNode* Root; // root�� ���������� ����

int inputNum()
{
    int input;
    printf("���� �Է�: ");
    scanf("%d", &input);

    return input;
}

//Ʈ���� ù ���(root) ����
void createNode(int data)
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    Root = newNode;
    Root->data = data;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    newNode->child = NULL;

}

//��� ����
void UserSetting()
{
    printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
    printf("��ɾ� : Q, +^, +, T, L, #, P()\n\n");
    printf("Q : ���α׷� ����\n");
    printf("+^: �Է¹��� ���ڸ� ��Ʈ�� �ϴ� Ʈ�� ����(�켱 +^�� �Է��ؾ���)\n");
    printf("+ : Ư����忡 �ڽĳ�带 ����(�켱 +�� �Է��ؾ� ��)\n");
    printf("T : Ʈ�� ���\n");
    printf("L : Ʈ���� �ְ� ���� ���\n");
    printf("P : Ư�������� path�� �� ���(�켱 P�� �Է��ؾ� ��)\n\n");
    printf("������ ������� Ʈ������ char�� data�� int������ �����߽��ϴ�.\n");
    printf("�Է¹��� ���ڴ� �ߺ����� �ʵ��� �մϴ�.\n\n");
}

// Ž�� �Լ�(���� Ư�� ��忡 �ڽĳ�带 �����ϰ� ���� ��� ���� �� �θ��尡 �Ǵ� ��带 ã�ƾ� �ϱ� ������ �ʿ�)
treeNode* searchNode(treeNode* R, int data)
{
    if (R == NULL) // ��Ʈ�� ���� ���
        return NULL;

    if (R->data == data) // ��Ʈ�� ã���� �ϴ� �θ��� ���
        return R;

    treeNode* right = searchNode(R->sibling, data);
    treeNode* left = searchNode(R->child, data);

    if (right != NULL) // sibling �� ã���� �ϴ� ��带 ã�� ���
        return right;
    if (left != NULL) // child �� ã���� �ϴ� ��带 ã�� ���
        return left;

    return 0; // ã���� �ϴ� ��尡 ���� ���
}

//���ο� ��� ���� �� ����
void insertNode(treeNode* P, int data) // P�� �θ� ���
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // �θ� ����
    newNode->sibling = NULL;
    newNode->child = NULL;

    treeNode* cur = P->child;

    if (cur == NULL) // ��Ʈ�� �ڽ��� ������
        P->child = newNode;

    while (cur != NULL) { // ��Ʈ�� �̹� �ڽ��� �ִٸ�
        if (cur->sibling == NULL) { // ���� ����� ���� ������ ��ġ�� ����
            cur->sibling = newNode;
            break;
        }
        cur = cur->sibling;
    }
}

//Ʈ�� ���
void PrintTree(treeNode* R)
{
    if (R == NULL) // R�� NULL�̸�
        return; // ��� Ż��

    if (R->child != NULL || R->sibling != NULL)
        printf("(");

    printf("%d", R->data); // ���� ��ȸ
    PrintTree(R->child);
    PrintTree(R->sibling);

    if (R->child != NULL || R->sibling != NULL)
        printf(")");
}

//path ���
int getPath(treeNode* R)
{
    int sum = 0;
    int data = inputNum();

    treeNode* key = searchNode(R, data); // P(5)�� �Է¹��� ���, key�� 5��带 ����Ŵ

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

//Ʈ���� �ְ� ����(����)
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

//Ʈ�� ����
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
            printf("���α׷��� �����մϴ�.\n");
            Root = Clear(Root);
            break;
        }//escape code

        if (order[0] == '+' && order[1] == '^') {
            input = inputNum();
            createNode(input);
        }

        if (order[0] == '+' && strlen(order)==1) {
            int parent;
            printf("�θ� ��� �Է�: ");
            scanf("%d", &parent);

            if (searchNode(Root, parent) == NULL)
                break;

            int num;
            printf("�θ��忡 �� �ڽĳ���� ���� �Է�: ");
            scanf("%d", &num);

            for (int i = 0; i < num; i++) {
                input = inputNum();
                insertNode(searchNode(Root, parent), input); // searchNode�� �θ��带 ã�� ��, �� �θ��忡 �Է¹��� ���� insert
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