#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

#define Max_Size 7

//���� Ʈ���� ��带 ǥ���� ����ü
typedef struct _bsTreeNode
{
    int data;
    struct _bsTreeNode* parent;
    struct _bsTreeNode* right;
    struct _bsTreeNode* left;

}treeNode;

treeNode* Root; // root�� ���������� ����

//���ڸ� �Է¹޴� �Լ�
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
    newNode->right = NULL;
    newNode->left = NULL;

}

//���� �Լ��� ���� �ڱ� �ڸ� Ž���ϱ�(��Ȯ����, �ڱ� �ڸ��� �θ� Ž���ϱ�)
treeNode* findParent(treeNode* node, int data)
{
    // �ڱⰡ �� �ڸ��� �θ� �˾ƾ� �ϱ� ������, before�� �ʿ�
    treeNode* before = NULL; // before �ʱ�ȭ

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

    return before; // �ڱⰡ �� �ڸ��� �θ��� before ��ȯ(��, �� ��ġ�� ���������� ���������� ���� ������ ����)
}

//���ο� ��� ���� �� ����
void insertNode(treeNode* P, int data) // P�� �θ� ��带 �ǹ�
{
    if (P == NULL) { // ex. Ʈ���� �ߺ��� ���ڰ� �ִ� ���
        printf("Error\n");
        return;
    }

    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // �θ� ����
    newNode->left = NULL;
    newNode->right = NULL;

    if (data < P->data) {
        P->left = newNode;
    }
    else if (data > P->data) {
        P->right = newNode;
    }
}

//Ʈ�� ���
void PrintTree(treeNode* node)
{
    if (node == NULL)
        return; // ��� Ż��

    printf("(");

    printf("%d ", node->data); // ���� ��ȸ
    PrintTree(node->left);
    PrintTree(node->right);

    printf(")");
}

//���� ��ȸ(�� - �� - ��)
void inorder_traverse(treeNode* node)
{
    if (node == NULL)
        return; // ��� Ż��

    inorder_traverse(node->left);
    printf("%d ", node->data);
    inorder_traverse(node->right);

}

//�� - �� - �� ���� ���� ��ȸ
void RightRootLeft_traverse(treeNode* node)
{
    if (node == NULL)
        return; // ��� Ż��

    RightRootLeft_traverse(node->right);
    printf("%d ", node->data);
    RightRootLeft_traverse(node->left);

}

//�ּҰ� Ž��
int getMin(treeNode* node)
{
    if (node == NULL)
        return -1;

    if (node->left == NULL)
        return node->data;

    getMin(node->left);
}

//�ִ밪 Ž��
int getMax(treeNode* node)
{
    if (node == NULL)
        return -1;

    if (node->right == NULL)
        return node->data;

    getMax(node->right);
}

// �˻��� ����� ���� ���� Ȯ��
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

//��� �˻�(��� ��ȯ)
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

//��� �˻� ���� 2(��� ��ȯ)
treeNode* findNode2(treeNode* node, int data)
{
    treeNode* key = NULL; // ã���� �ϴ� key��� �ʱ�ȭ

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

//��� ����
void deleteNode(treeNode* node, int data)
{
    treeNode* key = NULL; // ������ ��
    treeNode* replace = NULL; // ������ ���� ��ü�� ��

    if (isNode(node, data) > 0) { // �����ϰ��� �ϴ� ��尡 �����ϸ�
        key = findNode2(node, data);
        replace = key;

        //��� 1. ������ ����� �ڽ��� ���� ��
        if (key->left == NULL && key->right == NULL) {
            if (key->parent == NULL) { // ������ ��尡 root�� ���
                free(key);
            }
            else if (key->parent->left == key) { // ������ ��尡 �θ��� ���ʿ� �޸� ���
                key->parent->left = NULL;
                free(key);
            }
            else if (key->parent->right == key) { // ������ ��尡 �θ��� �����ʿ� �޸� ���
                key->parent->right = NULL;
                free(key);
            }
        }

        //��� 2. ������ ��忡 ������ �ڽĸ� ���� ��
        else if (key->left == NULL) {
            replace = replace->right; // replace�� key�� ������ �ڽ���

            key->data = replace->data;
            key->right = replace->right;
            replace->right->parent = key;
            free(replace);
        }

        //��� 3. ������ ��忡 ���� �ڽ��� ���� ��
        else {

            // ������ ����� ���� ����Ʈ���� �ִ밪�� replace�� �ϰ��� ��
            replace = replace->left;

            while (replace->right != NULL) {
                replace = replace->right;
            } // replace ã��

            if (replace->parent == key) { // replace�� key�� ���� �ڽ��� ���
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

//Ʈ���� ����
int Height(treeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = Height(node->left); // ��͸� ���� ���� ����Ʈ���� ���� ����
    int right_height = Height(node->right); // �����ʵ� ��������

    return 1 + (left_height > right_height ? left_height : right_height); // �� �� �� ū �� ��ȯ
}

//�˻��� ����� ������ �ڽ� ���
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

//�˻��� ����� ���� �ڽ� ���
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

//Ʈ���� ��� ����
int countNode(treeNode* node) // ��� ���
{
    if (node == NULL)
        return 0;

    int result = 1;

    result += countNode(node->left) + countNode(node->right);

    return result;
}

//Ʈ�� ����
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Root = NULL;

    return Root;
}

//�˻��� ����� ���� ���(��Ʈ���� �˻��� ������ �� ������ �����ߴ��� Ȯ��)
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

//�θ� ��� ���
void getParent(treeNode* R, int data)
{
    treeNode* key = findNode2(R, data);

    if (key == NULL || key->parent == NULL)
        printf("Error\n");

    else
        printf("%d\n", key->parent->data);
}

//��� ����
void UserSetting()
{
    printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
    printf("��ɾ� : Q, +, P, I, R, N, X, F, -, H, G, L, #, C, E, $, @\n\n");
    printf("��ɾ �켱 �Է� ��, ���ڸ��� �Է��ؾ� �մϴ�.\n\n");
    printf("Q : ���α׷� ����\n");
    printf("+: �Է¹��� ���ڿ� ���� ��� ���� or �Է¹��� ���ڸ� ��Ʈ�� �ϴ� Ʈ�� ����\n");
    printf("P : Ʈ�� ���\n");
    printf("I : ���� ��ȸ(��->��->��)\n");
    printf("R : ���� ��ȸ(��->��->��)\n");
    printf("N : �ּҰ� ���\n");
    printf("X : �ִ밪 ���\n");
    printf("F : ��� �˻�(��带 ã����, ��� ��ȯ)\n");
    printf("- : ��� ����\n");
    printf("H : Ʈ���� ���� ���\n");
    printf("G : �˻��� ����� ������ �ڽ� ���\n");
    printf("L : �˻��� ����� ���� �ڽ� ���\n");
    printf("# : Ʈ���� ��ü ��� ���� ���\n");
    printf("C : Ʈ�� ��ü ����\n\n");
    printf("<���⼭���ʹ� �ڽŸ��� ���>\n");
    printf("E : ����� ���� ����\n");
    printf("$ : ����� ���� ���\n");
    printf("@ : ����� �θ� ��� ���\n");
    printf("�Է¹��� ���ڴ� �ߺ����� �ʵ��� �մϴ�.\n\n");
}

int main() {

    UserSetting();

    char order[30];
    int input;
    int heap[Max_Size];

    printf("[max heap ������ ���� %d���� ���ڸ� �Է����ּ���]\n", Max_Size - 1);
    for (int i = 1; i < Max_Size; i++) {
        input = inputNum();
        heap[i] = input;
    }

    for (int i = Max_Size - 1; i > 1; i--) {
        if (heap[i / 2] < heap[i]) { //�θ� �ڽĺ��� ������
            //swap
            int temp = heap[i / 2];
            heap[i / 2] = heap[i];
            heap[i] = temp;
        }
    }

    printf("max heap ��� : ");
    for (int i = 1; i < Max_Size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");

    printf("max heap�� binary search tree�� ����\n");
    createNode(heap[1]);
    for (int i = 2; i < Max_Size; i++) {
        insertNode(findParent(Root, heap[i]), heap[i]);
    }

    while (1)
    {
        printf("order: ");
        scanf("%s", order);

        if (order[0] == 'Q') {
            printf("���α׷��� �����մϴ�.\n");
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
            printf("%d\n", Height(Root) - 1); // Ʈ���� ������ 0�������� �����̹Ƿ�, -1
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