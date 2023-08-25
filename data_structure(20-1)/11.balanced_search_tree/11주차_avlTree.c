#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

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

//��Ʈ�� �޸𸮰� �Ҵ�� ���¿��� ��Ʈ ����
void insertRoot(int data)
{
    Root->data = data;
}

//Ʈ���� ����
int Height(treeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = Height(node->left); // ��͸� ���� ���� ����Ʈ���� ���� ����
    int right_height = Height(node->right); // �����ʵ� ��������

    // �� �� �� ū �� ��ȯ
    if (left_height > right_height)
        return left_height + 1;
    else
        return right_height + 1;
}

//���� �μ�
int balanceFactor(treeNode* node)
{
    if (node == NULL)
        return 0;

    int left_height = Height(node->left); // ��͸� ���� ���� ����Ʈ���� ���� ����
    int right_height = Height(node->right); // �����ʵ� ��������

    return left_height - right_height; // balance factor ��ȯ
}

//LLȸ�� �Լ�
treeNode* RotateLL(treeNode* node)
{
    treeNode* pNode; // parent
    treeNode* cNode; // child

    //��ġ�� �ٲٰ��� �ϴ� ��带 ����Ű�� ��
    pNode = node;
    cNode = pNode->left;

    //LLȸ�� ����
    pNode->left = cNode->right; // �ֿ� ����1
    if (pNode->left!=NULL)
        pNode->left->parent = pNode;

    cNode->parent = pNode->parent;

    cNode->right = pNode; // �ֿ� ����2
    pNode->parent = cNode;

    return cNode; // ��Ʈ ��尡 �ٲ�� ���� ����Ͽ�, ����� ��Ʈ ����� �ּ� �� ��ȯ
}

//RRȸ�� �Լ�
treeNode* RotateRR(treeNode* node)
{
    treeNode* pNode; // parent
    treeNode* cNode; // child

    //��ġ�� �ٲٰ��� �ϴ� ��带 ����Ű�� ��
    pNode = node;
    cNode = pNode->right;

    //RRȸ�� ����
    pNode->right = cNode->left; // �ֿ� ����1
    if (pNode->right != NULL)
        pNode->right->parent = pNode;

    cNode->parent = pNode->parent;

    cNode->left = pNode; // �ֿ� ����2
    pNode->parent = cNode;

    return cNode; // ��Ʈ ��尡 �ٲ�� ���� ����Ͽ�, ����� ��Ʈ ����� �ּ� �� ��ȯ
}

//LRȸ�� �Լ�
treeNode* RotateLR(treeNode* node)
{
    treeNode* pNode; // parent
    treeNode* cNode; // child

    //��ġ�� �ٲٰ��� �ϴ� ��带 ����Ű�� ��
    pNode = node;
    cNode = pNode->left;

    //�κ��� RRȸ�� ����
    pNode->left = RotateRR(cNode);

    //LLȸ��
    return RotateLL(pNode);
}

//RLȸ�� �Լ�
treeNode* RotateRL(treeNode* node)
{
    treeNode* pNode; // parent
    treeNode* cNode; // child

    //��ġ�� �ٲٰ��� �ϴ� ��带 ����Ű�� ��
    pNode = node;
    cNode = pNode->right;

    //�κ��� LLȸ�� ����
    pNode->right = RotateLL(cNode);

    //RRȸ��
    return RotateRR(pNode);
}

//LL, RR, LR, RLȸ���� ���� ����ϴ����� ���� �Լ�
treeNode* Rebalance(treeNode* Root)
{
    if (Root == NULL)
        return NULL;

    Root->left = Rebalance(Root->left);
    Root->right = Rebalance(Root->right);
    int bf = balanceFactor(Root); // ���� �μ� ���

    //�ڽĳ�尡 ���ʿ� ���� �޸� ���
    if (bf > 1)
    {
        if (balanceFactor(Root->left) > 0) // LL����
            Root = RotateLL(Root);
        else // LR����
            Root = RotateLR(Root);
    }

    //�ڽĳ�尡 �����ʿ� ���� �޸� ���
    if (bf < -1)
    {
        if (balanceFactor(Root->right) < 0) // RR����
            Root = RotateRR(Root);
        else // RL����
            Root = RotateRL(Root);
    }

    return Root;
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

    //��������� ���� ����.
    //�������ʹ� Ʈ�� ���뷱��

    Root = Rebalance(Root);
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
                key->data = NULL;
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

    //��������� ���� ����.
    //�������ʹ� Ʈ�� ���뷱��

    Root = Rebalance(Root);

}

//Ʈ�� ����
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Root = NULL;

    return Root;
}

//�� Ʈ�� ����
int isEmpty(treeNode* Root)
{
    int exist = -1;

    if (Root == NULL || Root->data == NULL)
        exist = 1;

    return exist;
}

//balance factor�� 0�� ���� ���
void ZeroFactor(treeNode* node)
{
    if (node == NULL)
        return; // ��� Ż��

    int bf = balanceFactor(node);

    //������ȸ ����
    ZeroFactor(node->left);
    if (bf == 0)
        printf("%d ", node->data);
    ZeroFactor(node->right);
}

//�˻��� ����� ���� ���� ���
void getAncestors(treeNode* key)
{
    if (key == NULL || key->parent == NULL)
        printf("Error");

    else
        key = key->parent;

    while (key != NULL) {
        if (key == NULL)
            break;
        printf("%d ", key->data);
        key = key->parent;
    }
}

//��� ����
void UserSetting()
{
    printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
    printf("��ɾ� : Q, +, P, B, I, R, N, X, F, H, G, L, #, D, C, E, Z, A\n\n");
    printf("��ɾ �켱 �Է� ��, ���ڸ��� �Է��ؾ� �մϴ�.\n\n");
    printf("Q : ���α׷� ����\n");
    printf("+: �Է¹��� ���ڿ� ���� ��� ���� or �Է¹��� ���ڸ� ��Ʈ�� �ϴ� Ʈ�� ����\n");
    printf("P : Ʈ�� ���\n");
    printf("B : ����� ���� �μ� ���\n");
    printf("I : ���� ��ȸ(��->��->��)\n");
    printf("R : ���� ��ȸ(��->��->��)\n");
    printf("N : �ּҰ� ���\n");
    printf("X : �ִ밪 ���\n");
    printf("F : ��� �˻�(��带 ã����, ��� ��ȯ)\n");
    printf("- : ��� ����\n");
    printf("H : Ʈ���� ���� ���(0�������� ���)\n");
    printf("G : �˻��� ����� ������ �ڽ� ���\n");
    printf("L : �˻��� ����� ���� �ڽ� ���\n");
    printf("# : Ʈ���� ��ü ��� ���� ���\n");
    printf("D : ��� ����\n");
    printf("C : Ʈ�� ��ü ����\n\n");
    printf("<���⼭���ʹ� �ڽŸ��� ���>\n");
    printf("E : �� Ʈ�� ����\n");
    printf("Z : ���� �μ��� 0�� ���� ���\n");
    printf("A : ����� ���� ��� ���\n");
    printf("�Է¹��� ���ڴ� �ߺ����� �ʵ��� �մϴ�.\n\n");
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

        if (order[0] == '+') {
            input = inputNum();
            if (Root == NULL)
                createNode(input);
            else if (Root->data == NULL)
                insertRoot(input);
            else
                insertNode(findParent(Root, input), input);
        }

        if (order[0] == 'P') {
            PrintTree(Root);
            printf("\n");
        }

        if (order[0] == 'B') {
            if (Root == NULL) {
                printf("Error\n");
                continue;
            }
            input = inputNum();
            if (isNode(Root, input) < 0) {
                printf("Not Found\n");
                continue;
            }
            printf("%d\n", balanceFactor(findNode2(Root, input)));
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

        if (order[0] == 'D') {
            input = inputNum();
            deleteNode(Root, input);
        }

        if (order[0] == 'C') {
            Root = Clear(Root);
        }

        if (order[0] == 'E') {
            if (isEmpty(Root) > 0)
                printf("True\n");
            else
                printf("False\n");
        }

        if (order[0] == 'Z') {
            ZeroFactor(Root);
            printf("\n");
        }

        if (order[0] == 'A') {
            input = inputNum();
            getAncestors(findNode2(Root, input));
            printf("\n");
        }

    }

    system("pause");
    return 0;
}