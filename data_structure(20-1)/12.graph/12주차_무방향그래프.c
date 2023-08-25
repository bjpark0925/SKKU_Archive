#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

#define Max_vetex 30

// �׷��� ���� ����
typedef struct {
	int vertexCount; // ���� ����
	int edgeCount; // ���� ����
	int matrix[Max_vetex][Max_vetex]; // �׷��� ���� ���
}graphType;

//�׷��� ����
void createGraph(graphType* g)
{
	g->vertexCount = 0;
	g->edgeCount = 0;
	for (int i = 0; i < Max_vetex; i++) {
		for (int j = 0; j < Max_vetex; j++) {
			g->matrix[i][j] = 0;
		}
	}
}

//���� ����
void insert_vertex(graphType* g, char vertex[], char order[])
{
	if (order[1] == NULL)
		return;
	g->vertexCount++;
	vertex[strlen(vertex)] = order[1];
}

//���� ���
void print_vertex(char vertex[])
{
	printf("%s\n", vertex);
}

//���� ���� ����
int vertex_exist(char vertex[], char search)
{
	int v1 = -1; // vertex�� index��ȣ�� ����
	int len = strlen(vertex);

	//�Է¹��� search������ vertex�迭�� �ִ��� Ȯ��
	for (int i = 0; i < len; i++) {
		if (search == vertex[i]) {
			v1 = i;
		}
	}

	return v1;
}

//���� ����
void add_edge(graphType* g, char vertex[], char order[])
{
	//order�� E(AB)�� ��, order[2]�� order[3]�� �ִ� ��Ұ� vertex�迭�� �ִ��� Ȯ��
	int v1 = vertex_exist(vertex, order[2]);
	int v2 = vertex_exist(vertex, order[3]);
	
	if (v1 == -1 || v2 == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return;
	}

	//����� ���� 1�� �ٲ�
	g->matrix[v1][v2] = 1;
	g->matrix[v2][v1] = 1;

	g->edgeCount++;
}

//�׷��� ���
void print_graph(graphType* g, char vertex[])
{
	int len = g->vertexCount;

	if (g->edgeCount == 0) {
		print_vertex(vertex);
		return;
	}

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			printf("%d", g->matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < len; i++) {
		printf("%c -> ", vertex[i]);
		for (int j = 0; j < len; j++) {
			if (g->matrix[i][j] == 1) {
				printf("%c ", vertex[j]);
			}
		}
		printf("\n");
	}
}

//�Է��� ������ ����� �ٸ� �������� ����
int degree_of_vertex(graphType* g, char vertex[], char order[])
{
	int cnt = 0;
	int len = strlen(vertex);

	//order�� V(A)�� ��, order[2]�� �ִ� ��Ұ� vertex�迭�� �ִ��� Ȯ��
	int v1 = vertex_exist(vertex, order[2]);

	if (v1 == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return -1;
	}

	for (int i = 0; i < len; i++) {
		if (g->matrix[v1][i] == 1)
			cnt++;
	}

	return cnt;
}

//�������� ���� ���� ��� ������ ����Ǿ����� ����
int is_connected(graphType* g, char vertex[])
{
	int len = strlen(vertex);

	for (int i = 0; i < len; i++) {
		int connected = 0;
		for (int j = 0; j < len; j++) { // �� ���� ��� ����
			connected += g->matrix[i][j];
		}
		if (connected == 0) { // �� ���� ��� ���ؼ� ���� ���� 0�̸� unconnected
			return -1;
		}
	}

	return 1;
}

//�� �׷��� ����
int is_empty(graphType* g)
{
	if (g->vertexCount == 0)
		return 1;
	else
		return -1;
}

//���� ���� ���
void adjacent(graphType* g, char vertex[], char order[])
{
	int len = strlen(vertex);

	//order�� A(A)�� ��, order[2]�� �ִ� ��Ұ� vertex�迭�� �ִ��� Ȯ��
	int v1 = vertex_exist(vertex, order[2]);
	
	if (v1 == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return;
	}

	for (int i = 0; i < len; i++) {
		if (g->matrix[v1][i] == 1) {
			printf("%c ", vertex[i]);
		}
	}
	printf("\n");
}

//���� ����
void delete_vertex(graphType* g, char vertex[], char order[])
{
	int len = strlen(vertex);

	int v1 = vertex_exist(vertex, order[1]);

	if (v1 == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return;
	}

	//1. graph�� vertex, edge ���� ������Ʈ
	g->vertexCount--;
	for (int i = 0; i < len; i++) {
		if (g->matrix[v1][i] == 1)
			g->edgeCount--;
	}

	//2. ��Ŀ��� ������ vertex�� ������ ���ֱ� ���� ������ vertex ������ ����� shift
	/*
	0 1 0
	1 0 0
	0 0 0
	���� ù��° vertex�� �����Ѵٸ�,
	0 0
	0 0
	�� ��.
	*/
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1; j++) {
			g->matrix[v1 + i][v1 + j] = g->matrix[v1 + i + 1][v1 + j + 1];
		}
	}

	//����� ������ �׵θ����� 0���� �ʱ�ȭ��
	for (int i = 0; i < len; i++) {
		g->matrix[i][len - 1] = 0;
		g->matrix[len - 1][i] = 0;
	}

	//3. vertex�迭���� memmove�Լ� �̿�, ������ vertex�ε��� ������ �迭�� ������ �� ĭ�� �ű�
	memmove(vertex + v1, vertex + v1 + 1, len - v1);
}

//BFS�� ���� enqueue�Լ�
int enqueue(int data, int queue[], int tail, int visited[])
{
	//�̹� �湮�� ����̸� enqueue���� ����
	for (int i = 0; i < strlen(visited); i++) {
		if (data == visited[i]) {
			return tail;
		}
	}

	queue[tail + 1] = data;
	tail++;

	return tail;
}

//BFS�� ���� dequeue�Լ�
int dequeue(int queue[], int head, int visited[])
{
	head++;

	visited[strlen(visited)] = queue[head]; // dequeue�Ǵ� ��Ҵ� visited�迭�� �߰�

	queue[head] = '\0'; // ����

	return head;
}

//��� ���� ����
void path_exist(graphType* g, char vertex[], char start, char destination)
{
	int len = strlen(vertex);

	//�Է¹��� start�� destination��Ұ� vertex�迭�� �ִ��� Ȯ��
	int s = vertex_exist(vertex, start); // start�� index��ȣ
	int d = vertex_exist(vertex, destination); // destination�� index��ȣ

	if (s == -1 || d == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return;
	}

	//BFS(ť�� �̿��� �ʺ� �켱 Ž��)
	int visited[Max_vetex]; // �湮 ���� ������ ���� �迭
	int queue[Max_vetex] = { '\0', };
	int head = -1;
	int tail = -1;

	visited[0] = s;
	visited[1] = d;

	for (int i = 0; i < len; i++) {
		if (g->matrix[s][i] == 1) {
			tail = enqueue(i, queue, tail, visited);
		}
	}

	while (1) {
		if (queue[head + 1] == d) {
			printf("True\n");
			return;
		} // Ž�� ����

		if (head == tail) {
			break;
		} // Ž���� ������ ä�� while�� Ż��

		for (int i = 0; i < len; i++) {
			if (g->matrix[queue[head + 1]][i] == 1) {
				tail = enqueue(i, queue, tail, visited);
			}
		}

		head = dequeue(queue, head, visited);
	}

	printf("False\n");
}

//���� ����
void num_of_vertex(graphType* g)
{
	printf("%d\n", g->vertexCount);
}

//���� ����
void num_of_edge(graphType* g)
{
	printf("%d\n", g->edgeCount);
}

//���� ����
void delete_edge(graphType* g, char vertex[], char start, char destination)
{
	//�Է¹��� start�� destination��Ұ� vertex�迭�� �ִ��� Ȯ��
	int v1 = vertex_exist(vertex, start);
	int v2 = vertex_exist(vertex, destination);

	if (v1 == -1 || v2 == -1) { // �������� �ʴ� vertex�� ���
		printf("Error\n");
		return;
	}

	//����� ���� 0���� �ٲ�
	g->matrix[v1][v2] = 0;
	g->matrix[v2][v1] = 0;

	g->edgeCount--;
}

//������ �̸� ����
void rename_vertex(char vertex[], char pre, char next)
{
	int old = vertex_exist(vertex, pre);
	int new = vertex_exist(vertex, next);

	if (old == -1 || new != -1) { // �ٲ� ��Ұ� �׷��� ���� �������� �ʰų�, �ٲ� ��Ұ� �׷��� ���� �����ϴ� ���
		printf("Error\n");
		return;
	}

	vertex[old] = next;
}

//�׷��� ��ü ����
void clear(graphType* g)
{
	g->vertexCount = 0;
	g->edgeCount = 0;
	for (int i = 0; i < Max_vetex; i++) {
		for (int j = 0; j < Max_vetex; j++) {
			g->matrix[i][j] = 0;
		}
	}
}

//���� �׷��� ����
int is_completeGraph(graphType* g)
{
	int len = g->vertexCount;

	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = 0; j < len; j++) { // �� ���� ��� ����
			cnt += g->matrix[i][j];
		}
		if (cnt != len-1) { // �� ���� ��� ���ؼ� ���� ���� len-1�� �ٸ��� false
			return -1;
		}
	}

	return 1;
}

//������ �׷��� ����
int is_undirectedGraph(graphType* g)
{
	int len = g->vertexCount;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (g->matrix[i][j] != g->matrix[j][i])
				return -1;
		}
	}

	return 1;
}

//��� ����
void UserSetting()
{
	printf("����ڴ� ������ ��ɾ ����� �� �ֽ��ϴ�.\n");
	printf("��ɾ� : Q, G, +, E, L, V, C, N, A, P, -, X, H, D, R, K, T, M, U\n\n");
	printf("Q : ���α׷� ����\n");
	printf("G : �׷��� ����\n");
	printf("+A : ���� ����(������ �ϳ��� �Է��ؾ� ��)\n");
	printf("E(AB) : ���� ����(�� ���� ���̿� ���� ����)\n");
	printf("L: �׷��� ���(������İ� �Բ� ���)\n");
	printf("V(A) : �Է��� ������ ����� �ٸ� �������� ����\n");
	printf("C : �������� ���� ���� ��� ������ ����Ǿ����� ����\n");
	printf("N : �� �׷��� ����\n");
	printf("A(A) : ���� ���� ���\n");
	printf("-A : ���� ����\n");
	printf("P(AB) : ��� ���� ����\n");
	printf("X : ���� ����\n");
	printf("H : ���� ����\n");
	printf("D(AB) : ���� ����\n");
	printf("R(AF) : A�� �̸��� F�� ����(A�� �ٲ� ����, F�� �ٲ�� ����)\n");
	printf("K : �׷��� ��ü ����\n\n");
	printf("<���⼭���ʹ� �ڽŸ��� ���>\n");
	printf("T(A) : �׷��� �� ���� ���� ����\n");
	printf("M : ���� �׷��� ����(�� �������� �ٸ� ��� ������ ����Ǿ�����)\n");
	printf("U : ������ �׷��� ����\n");
	printf("!: vertex�迭 ���\n");
	printf("�Է¹��� vertex�� �ߺ����� �ʵ��� �մϴ�.\n\n");
}

int main(void) {

	UserSetting();

	char order[30];
	char vertex[Max_vetex] = { '\0', };
	graphType* graph = (graphType*)malloc(sizeof(graphType));

	while (1)
	{
		printf("order: ");
		scanf("%s", order);

		if (order[0] == 'Q') {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}

		if (order[0] == '!') {
			print_vertex(vertex);
		}

		if (order[0] == 'G') {
			createGraph(graph);
		}

		if (order[0] == '+') {
			if (graph == NULL) {
				printf("Error\n");
				continue;
			}
			insert_vertex(graph, vertex, order);
		}

		if (order[0] == 'E' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // E(AB)�� �Է¹��� ���
			add_edge(graph, vertex, order);
		}

		if (order[0] == 'L') {
			print_graph(graph, vertex);
		}

		if (order[0] == 'V' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // V(A)�� �Է¹��� ���
			if (degree_of_vertex(graph, vertex, order) == -1) {
				continue;
			}
			printf("%d\n", degree_of_vertex(graph, vertex, order));
		}

		if (order[0] == 'C') {
			if (is_connected(graph, vertex) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == 'N') {
			if (is_empty(graph) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == 'A' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // A(A)�� �Է¹��� ���
			adjacent(graph, vertex, order);
		}

		if (order[0] == '-') {
			delete_vertex(graph, vertex, order);
		}

		if (order[0] == 'P' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // P(AB)�� �Է¹��� ���
			path_exist(graph, vertex, order[2], order[3]);
		}

		if (order[0] == 'X') {
			num_of_vertex(graph);
		}

		if (order[0] == 'H') {
			num_of_edge(graph);
		}

		if (order[0] == 'D' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // D(AB)�� �Է¹��� ���
			delete_edge(graph, vertex, order[2], order[3]);
		}

		if (order[0] == 'R' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // R(AF)�� �Է¹��� ���
			rename_vertex(vertex, order[2], order[3]);
		}

		if (order[0] == 'K') {
			clear(graph);
			for (int i = strlen(vertex - 1); i >= 0; i--) {
				vertex[i] = NULL;
			}
		}

		if (order[0] == 'T' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // T(A)�� �Է¹��� ���
			if (vertex_exist(vertex, order[2]) == -1)
				printf("Not Exist\n");
			else
				printf("Exist\n");
		}

		if (order[0] == 'M') {
			if (is_completeGraph(graph) == 1)
				printf("True\n");
			else
				printf("False\n");
		}

		if (order[0] == 'U') {
			if (is_undirectedGraph(graph) == 1)
				printf("True\n");
			else
				printf("False\n");
		}
	}

	system("pause");
	return 0;
}