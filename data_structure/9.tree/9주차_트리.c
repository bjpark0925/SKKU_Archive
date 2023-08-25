#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

//���� Ʈ���� ��带 ǥ���� ����ü
typedef struct _bTreeNode
{
    char data;
    struct _bTreeNode* parent;
    struct _bTreeNode* sibling; // right
    struct _bTreeNode* child; // left

}treeNode;

treeNode* Root; // root�� ���������� ����

//Ʈ���� ù ���(root) ����
void createNode(char data)
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    Root = newNode;
    newNode->data = data;
    newNode->parent = NULL;
    newNode->sibling = NULL;
    newNode->child = NULL;

}

// Ž�� �Լ�(���� Ư�� ��忡 �ڽĳ�带 �����ϰ� ���� ��� ���� �� �θ��尡 �Ǵ� ��带 ã�ƾ� �ϱ� ������ �ʿ�)
treeNode* searchNode(treeNode* R, char parent)
{
    if (R == NULL) // ��Ʈ�� ���� ���
        return NULL;

    if (R->data == parent) // ��Ʈ�� ã���� �ϴ� �θ��� ���
        return R;

    treeNode* right = searchNode(R->sibling, parent);
    treeNode* left = searchNode(R->child, parent);

    if (right != NULL) // sibling �� ã���� �ϴ� ��带 ã�� ���
        return right;
    if (left != NULL) // child �� ã���� �ϴ� ��带 ã�� ���
        return left;

    return NULL; // ã���� �ϴ� ��尡 ���� ���
}

//���ο� ��� ���� �� ����
void insertNode(treeNode* P, char data) // P�� �θ� ���
{
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->parent = P; // �θ� ����
    newNode->sibling = NULL;
    newNode->child = NULL;

    treeNode* cur = P->child;

    if (cur == NULL) // �θ� �ڽ��� ������
        P->child = newNode;

    while (cur != NULL) { // �θ� �̹� �ڽ��� �ִٸ�
        if (cur->sibling == NULL) { // ���� ����� ���� ������ ��ġ�� ����
            cur->sibling = newNode;
            break;
        }
        cur = cur->sibling;
    }
}

//���� ���迡 �ִ� ��� ���(�ڱ� �ڽŵ� ���)
void getSibling(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // S(D)�� �Է¹��� ���, key�� D��带 ����Ŵ

    if (key == NULL) {
        printf("sibling ����");
        return;
    }

    treeNode* P = key->parent; // P�� key����� parent���
    if (P == NULL && R != NULL) { // key��尡 root�� ���� ������ ���
        key = R;

        while (key != NULL) {
            if (key == NULL)
                break;
            printf("%c", key->data);
            key = key->sibling;
        }
    }

    else {
        treeNode* C = P->child; // C�� P�� ù��° child

        while (C != NULL) {
            if (C == NULL) { // C�� ���������� ���� ��ȸ
                break;
            }
            printf("%c", C->data);
            C = C->sibling;
        }
    }
}

//Ʈ�� ���
void PrintTree(treeNode* node)
{
    if (node == NULL)
        return; // ��� Ż��

    if (node == Root || (node->parent != NULL && node == node->parent->child))
        printf("(");

    printf("%c ", node->data); // ���� ��ȸ
    PrintTree(node->child);
    PrintTree(node->sibling);
    
    if (node->sibling==NULL)
        printf(")");
}

//�θ� ��� ���
void getParent(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // P(E)�� �Է¹��� ���, key�� E��带 ����Ŵ

    if (key == NULL || key->parent == NULL)
        printf("Error\n");

    else
        printf("%c\n", key->parent->data);
}

//�ڽ� ��� ���
void getChild(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // C(A)�� �Է¹��� ���, key�� A��带 ����Ŵ

    if (key == NULL || key->child == NULL)
        printf("Error");

    else {
        treeNode* C = key->child; // C�� key�� ù��° child

        while (C != NULL) {
            if (C == NULL)
                break;
            printf("%c", C->data);
            C = C->sibling;
        }
    }
}

//Ư�� ����� ����
int level_of_node(treeNode* R, char data)
{
    int cnt = 0;
    treeNode* key = searchNode(R, data); // L(G)�� �Է¹��� ���, key�� G��带 ����Ŵ

    if (key == NULL) // �Է��� ��尡 Ʈ���� ������ -1 ��ȯ
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

//����� ����
void DeleteNode(treeNode* Node)
{
    if (Node->sibling == NULL && Node->child == NULL) {
        if (Node->parent == NULL) {//root ���� ���� �������� ��带 �����ϴ� ���
            Node = Root; // ������ ��忡 ����� ������ ���� ���� Root���� Ž��
            while (Node->sibling->sibling != NULL) {
                if (Node->sibling->sibling == NULL)
                    break;
                Node = Node->sibling;
            }

            Node->sibling = NULL; // ������ ��忡 ����� ���� ����
        }

        else { // ���� 1 �̻��� ��带 �����ϴ� ���
            Node = Node->parent->child; // ������ ��忡 ����� ������ ���� ���� �����ϰ��� �ϴ� ����� ù° �������� Ž��
            while (Node->sibling->sibling != NULL) {
                if (Node->sibling->sibling == NULL)
                    break;
                Node = Node->sibling;
            }
            Node->sibling = NULL; // ������ ��忡 ����� ���� ����
        }
    }

    else
        printf("Error\n");
}

//���� ��� ���
void getAncestors(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // A(H)�� �Է¹��� ���, key�� H��带 ����Ŵ

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

//�ڼ� ��� ���
void getDescendants(treeNode* R, char data)
{
    treeNode* key = searchNode(R, data); // D(B)�� �Է¹��� ���, key�� B��带 ����Ŵ

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

//Ư�� ����� ����
int degree_of_node(treeNode* R, char data)
{
    int cnt = 0;
    treeNode* key = searchNode(R, data); // D(B)�� �Է¹��� ���, key�� B��带 ����Ŵ
    treeNode* C = key->child; // C�� key�� ù��° child

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

//���� Ʈ�� �ְ� ���� ����� ���� ���� ������ �Լ�
int degree_of_node2(treeNode* R)
{
    int cnt = 0;
    treeNode* C = R->child; // C�� key�� ù��° child

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

//Ʈ���� �ְ� ����
int degree_of_tree(treeNode* R)
{
    int size = level_of_tree(R);
    int* ptr = malloc(sizeof(int) * size); // �� ���� �� �������� �����ϴ� ������ �迭 ����
    int i = 0;

    if (R == NULL)
        return 0;

    for (int j = 0; j < size; j++) {
        ptr[i] = degree_of_node2(R);

        R = R->child;
        i++;
    }

    //������� array�� ��������, degree�� �ִ밪 ���ϱ�
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

//Ʈ���� ��� ����
int countNode(treeNode* R) // Ʈ���� �ְ� ���� ���ϴ� ����� ����
{
    int size = level_of_tree(R) + 1;
    int* ptr = malloc(sizeof(int) * size); // �� ���� �� �������� �����ϴ� ������ �迭 ����
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

    //������� array ��ҵ��� �� ���ϱ�

    int sum = 0;
    for (int k = 0; k < size; k++) {
        sum += ptr[k];
    }

    return sum;
}

//������忡 ���ο� ��� �߰�
void insertSibling(treeNode* R, char data[]) // insertNode�Լ��� getSibling�Լ��� ������ ����
{
    treeNode* key = searchNode(R, data[2]); // =+F(IJ)�� �Է¹��� ���, key�� F��带 ����Ŵ

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

            while (R != NULL) { // ���� ����� ���� ������ ��ġ�� �����ϴ� ����
                if (R->sibling == NULL) {
                    R->sibling = newNode;
                    break;
                }
                R = R->sibling;
            }
        }
    }

    else {
        treeNode* P = key->parent; // P�� key����� parent���
        for (int i = 4; i < strlen(data) - 1; i++) {
            treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
            newNode->data = data[i];
            newNode->parent = P; // �θ� ����
            newNode->sibling = NULL;
            newNode->child = NULL;

            treeNode* C = P->child; // C�� P�� ù��° child

            while (C != NULL) { // ���� ����� ���� ������ ��ġ�� �����ϴ� ����
                if (C->sibling == NULL) {
                    C->sibling = newNode;
                    break;
                }
                C = C->sibling;
            }
        }
    }

}

//joinTrees�Լ��� ���� �Լ���

//tree2 ������ �ʱ� ���� ����
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

void makeSiblingTree(treeNode* first, treeNode* second) // first, second�� ���� �� ù°, ��°�� �ǹ�
{
    first->sibling = second;
    second->parent = first->parent;
}

//Ʈ�� ����
treeNode* Clear(treeNode* Root)
{
    if (Root == NULL)
        return;

    Root = NULL;

    return Root;
}

//��� ����
void UserSetting()
{
    printf("<�Ϲ�Ʈ�� ADT>\n");
    printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
    printf("��ɾ� : +^, +, S(), T, P(), C(), L(), L, -, A(), D(), G(), G, #, =+, J, K\n\n");
    printf("Q : ���α׷� ����\n");
    printf("+^A: A��带 ��Ʈ�� �ϴ� Ʈ�� ����(A�� �ƴϾ ��)\n");
    printf("+A(BCD) : A�� �ڽĳ��� B, C, D ����(���� ���� ����)\n");
    printf("S(D) : D����� ������� ���(�ڱ� �ڽŵ� ���)\n");
    printf("T: Ʈ�� ���\n");
    printf("P(E) : E�� �θ��� ���(E�� �ƴϾ ��)\n");
    printf("C(A) : A�� �ڽĳ�� ���(A�� �ƴϾ ��)\n");
    printf("L(G) : G ����� ���� ���(G�� �ƴϾ ��)\n");
    printf("L : Ʈ���� �ְ� ����(����) ���\n");
    printf("-B : B��� ����(�ܸ� ��常 ���� ����)\n");
    printf("A(H) : H�� ������ ���(H�� �ƴϾ ��)\n");
    printf("D(B) : B�� �ļճ�� ���(B�� �ƴϾ ��)\n");
    printf("G(B) : B�� ���� ���(B�� child��� ����)\n");
    printf("G : Ʈ���� �ְ� ���� ���\n");
    printf("# : Ʈ���� ��ü ��� ���� ���\n");
    printf("=+F(IJ) : F�� �������� I, J�� ����(���� ���� ����)\n");
    printf("J(P) : P�� ���ο� ��Ʈ���� �Ͽ�, ���� ������ �ִ� ������ Ʈ���� ���� ���� Ʈ���� ����(P�� �ƴϾ ��)\n");
    printf("K : Ʈ�� ��ü ����\n\n");
    printf("<�Ϲ�Ʈ���� ����Ʈ���� �����߱� ������, ����Ʈ���� ���� ADT�� ���� ������ �ʾҽ��ϴ�.>\n");
    printf("<T �Է� �� Ʈ�� ����� �Ϻ��ϰ� �ǵ��� �����Ͽ���\n DELETE_NODE �� �������� �Ǵ� ��쳪 JOIN_TREE �� COUNT_NODE�� �ٸ� ���� �����ϴ� ��츦 ��� �����Ͽ����ϴ�.>\n\n");
}

int main() {

    UserSetting();

    char order[30];

    while (1)
    {
        printf("order: ");
        scanf("%s", order);

        if (order[0] == 'Q') {
            printf("���α׷��� �����մϴ�.\n");
            break;
        }//escape code

        if (order[0] == '+' && order[1] == '^' && strlen(order) == 3) {
            if (Root == NULL)
                createNode(order[2]);
            else
                printf("Root�� ���� �����մϴ�.\n");
        }

        if (order[0] == '+' && order[2] == '(' && order[strlen(order) - 1] == ')' && searchNode(Root, order[1]) != NULL) { // +A(BCD)�� �Է¹��� ���
            if (searchNode(Root, order[1]) == NULL) {
                printf("ã���� �ϴ� �θ� ��尡 �����ϴ�.\n");
                continue;
            }

            for (int i = 3; i < strlen(order) - 1; i++) {
                insertNode(searchNode(Root, order[1]), order[i]); // searchNode�� �θ��带 ã�� ��, �� �θ��忡 �Է¹��� �͵��� insert
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

        //insertSibling�� insertNode�� ����ϰ� ������
        if (order[0] == '=' && order[1] == '+' && order[strlen(order) - 1] == ')' && searchNode(Root, order[2]) != NULL) { // =+F(IJ)
            insertSibling(Root, order);
        }

        //���Ƿ� ���ο� Ʈ���� �����ؼ� ������ Ʈ���� ����
        if (order[0] == 'J' && order[1] == '(' && order[strlen(order) - 1] == ')') { // J(P)
            treeNode* t1 = makeTree2('1');
            treeNode* t2 = makeTree2('2');
            treeNode* t3 = makeTree2('3');
            treeNode* t4 = makeTree2('4');

            makeSiblingTree(t1, t2);
            makeSiblingTree(t2, t3);
            makeSiblingTree(t3, t4);
            //���ο� Ʈ���� (1, 2, 3, 4) ���·� ������

            treeNode* merge = makeTree2(order[2]);
            //merge�� ���� root��� ����
            merge->child = Root;
            Root->parent = merge;

            //merge�� ���� ���� tree2 ����
            makeSiblingTree(merge, t1);

            Root = merge; // Root�� merge�� ������Ʈ
        }

        if (order[0] == 'K') {
            Root = Clear(Root);
        }

    }

    system("pause");
    return 0;
}