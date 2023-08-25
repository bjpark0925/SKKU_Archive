#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>//malloc
#include<string.h>//strlen

#define Max_vetex 30

// 그래프 형식 정의
typedef struct {
	int vertexCount; // 정점 개수
	int edgeCount; // 간선 개수
	int matrix[Max_vetex][Max_vetex]; // 그래프 인접 행렬
}graphType;

//그래프 생성
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

//정점 삽입
void insert_vertex(graphType* g, char vertex[], char order[])
{
	if (order[1] == NULL)
		return;
	g->vertexCount++;
	vertex[strlen(vertex)] = order[1];
}

//정점 출력
void print_vertex(char vertex[])
{
	printf("%s\n", vertex);
}

//정점 존재 여부
int vertex_exist(char vertex[], char search)
{
	int v1 = -1; // vertex의 index번호를 저장
	int len = strlen(vertex);

	//입력받은 search정점이 vertex배열에 있는지 확인
	for (int i = 0; i < len; i++) {
		if (search == vertex[i]) {
			v1 = i;
		}
	}

	return v1;
}

//간선 연결
void add_edge(graphType* g, char vertex[], char order[])
{
	//order가 E(AB)일 때, order[2]와 order[3]에 있는 요소가 vertex배열에 있는지 확인
	int v1 = vertex_exist(vertex, order[2]);
	int v2 = vertex_exist(vertex, order[3]);
	
	if (v1 == -1 || v2 == -1) { // 존재하지 않는 vertex인 경우
		printf("Error\n");
		return;
	}

	//행렬의 값을 1로 바꿈
	g->matrix[v1][v2] = 1;
	g->matrix[v2][v1] = 1;

	g->edgeCount++;
}

//그래프 출력
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

//입력한 정점에 연결된 다른 정점들의 개수
int degree_of_vertex(graphType* g, char vertex[], char order[])
{
	int cnt = 0;
	int len = strlen(vertex);

	//order가 V(A)일 때, order[2]에 있는 요소가 vertex배열에 있는지 확인
	int v1 = vertex_exist(vertex, order[2]);

	if (v1 == -1) { // 존재하지 않는 vertex인 경우
		printf("Error\n");
		return -1;
	}

	for (int i = 0; i < len; i++) {
		if (g->matrix[v1][i] == 1)
			cnt++;
	}

	return cnt;
}

//동떨어진 정점 없이 모든 정점이 연결되었는지 여부
int is_connected(graphType* g, char vertex[])
{
	int len = strlen(vertex);

	for (int i = 0; i < len; i++) {
		int connected = 0;
		for (int j = 0; j < len; j++) { // 한 행을 모두 더함
			connected += g->matrix[i][j];
		}
		if (connected == 0) { // 한 행을 모두 더해서 나온 값이 0이면 unconnected
			return -1;
		}
	}

	return 1;
}

//빈 그래프 여부
int is_empty(graphType* g)
{
	if (g->vertexCount == 0)
		return 1;
	else
		return -1;
}

//인접 정점 출력
void adjacent(graphType* g, char vertex[], char order[])
{
	int len = strlen(vertex);

	//order가 A(A)일 때, order[2]에 있는 요소가 vertex배열에 있는지 확인
	int v1 = vertex_exist(vertex, order[2]);
	
	if (v1 == -1) { // 존재하지 않는 vertex인 경우
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

//정점 삭제
void delete_vertex(graphType* g, char vertex[], char order[])
{
	int len = strlen(vertex);

	int v1 = vertex_exist(vertex, order[1]);

	if (v1 == -1) { // 존재하지 않는 vertex인 경우
		printf("Error\n");
		return;
	}

	//1. graph의 vertex, edge 개수 업데이트
	g->vertexCount--;
	for (int i = 0; i < len; i++) {
		if (g->matrix[v1][i] == 1)
			g->edgeCount--;
	}

	//2. 행렬에서 삭제할 vertex의 정보를 없애기 위해 삭제할 vertex 이후의 행렬을 shift
	/*
	0 1 0
	1 0 0
	0 0 0
	에서 첫번째 vertex를 삭제한다면,
	0 0
	0 0
	이 됨.
	*/
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1; j++) {
			g->matrix[v1 + i][v1 + j] = g->matrix[v1 + i + 1][v1 + j + 1];
		}
	}

	//행렬의 마지막 테두리들을 0으로 초기화함
	for (int i = 0; i < len; i++) {
		g->matrix[i][len - 1] = 0;
		g->matrix[len - 1][i] = 0;
	}

	//3. vertex배열에서 memmove함수 이용, 삭제할 vertex인덱스 이후의 배열을 앞으로 한 칸씩 옮김
	memmove(vertex + v1, vertex + v1 + 1, len - v1);
}

//BFS를 위한 enqueue함수
int enqueue(int data, int queue[], int tail, int visited[])
{
	//이미 방문한 요소이면 enqueue하지 않음
	for (int i = 0; i < strlen(visited); i++) {
		if (data == visited[i]) {
			return tail;
		}
	}

	queue[tail + 1] = data;
	tail++;

	return tail;
}

//BFS를 위한 dequeue함수
int dequeue(int queue[], int head, int visited[])
{
	head++;

	visited[strlen(visited)] = queue[head]; // dequeue되는 요소는 visited배열에 추가

	queue[head] = '\0'; // 삭제

	return head;
}

//경로 존재 여부
void path_exist(graphType* g, char vertex[], char start, char destination)
{
	int len = strlen(vertex);

	//입력받은 start와 destination요소가 vertex배열에 있는지 확인
	int s = vertex_exist(vertex, start); // start의 index번호
	int d = vertex_exist(vertex, destination); // destination의 index번호

	if (s == -1 || d == -1) { // 존재하지 않는 vertex인 경우
		printf("Error\n");
		return;
	}

	//BFS(큐를 이용한 너비 우선 탐색)
	int visited[Max_vetex]; // 방문 여부 정보를 넣을 배열
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
		} // 탐색 성공

		if (head == tail) {
			break;
		} // 탐색에 실패한 채로 while문 탈출

		for (int i = 0; i < len; i++) {
			if (g->matrix[queue[head + 1]][i] == 1) {
				tail = enqueue(i, queue, tail, visited);
			}
		}

		head = dequeue(queue, head, visited);
	}

	printf("False\n");
}

//정점 개수
void num_of_vertex(graphType* g)
{
	printf("%d\n", g->vertexCount);
}

//간선 개수
void num_of_edge(graphType* g)
{
	printf("%d\n", g->edgeCount);
}

//간선 삭제
void delete_edge(graphType* g, char vertex[], char start, char destination)
{
	//입력받은 start와 destination요소가 vertex배열에 있는지 확인
	int v1 = vertex_exist(vertex, start);
	int v2 = vertex_exist(vertex, destination);

	if (v1 == -1 || v2 == -1) { // 존재하지 않는 vertex인 경우
		printf("Error\n");
		return;
	}

	//행렬의 값을 0으로 바꿈
	g->matrix[v1][v2] = 0;
	g->matrix[v2][v1] = 0;

	g->edgeCount--;
}

//정점의 이름 변경
void rename_vertex(char vertex[], char pre, char next)
{
	int old = vertex_exist(vertex, pre);
	int new = vertex_exist(vertex, next);

	if (old == -1 || new != -1) { // 바꿀 요소가 그래프 내에 존재하지 않거나, 바뀔 요소가 그래프 내에 존재하는 경우
		printf("Error\n");
		return;
	}

	vertex[old] = next;
}

//그래프 전체 삭제
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

//완전 그래프 여부
int is_completeGraph(graphType* g)
{
	int len = g->vertexCount;

	for (int i = 0; i < len; i++) {
		int cnt = 0;
		for (int j = 0; j < len; j++) { // 한 행을 모두 더함
			cnt += g->matrix[i][j];
		}
		if (cnt != len-1) { // 한 행을 모두 더해서 나온 값이 len-1과 다르면 false
			return -1;
		}
	}

	return 1;
}

//무방향 그래프 여부
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

//기능 설명
void UserSetting()
{
	printf("사용자는 다음의 명령어를 사용할 수 있습니다.\n");
	printf("명령어 : Q, G, +, E, L, V, C, N, A, P, -, X, H, D, R, K, T, M, U\n\n");
	printf("Q : 프로그램 종료\n");
	printf("G : 그래프 생성\n");
	printf("+A : 정점 삽입(정점은 하나만 입력해야 함)\n");
	printf("E(AB) : 간선 삽입(두 정점 사이에 간선 연결)\n");
	printf("L: 그래프 출력(인접행렬과 함께 출력)\n");
	printf("V(A) : 입력한 정점에 연결된 다른 정점들의 개수\n");
	printf("C : 동떨어진 정점 없이 모든 정점이 연결되었는지 여부\n");
	printf("N : 빈 그래프 여부\n");
	printf("A(A) : 인접 정점 출력\n");
	printf("-A : 정점 삭제\n");
	printf("P(AB) : 경로 존재 여부\n");
	printf("X : 정점 개수\n");
	printf("H : 간선 개수\n");
	printf("D(AB) : 간선 삭제\n");
	printf("R(AF) : A의 이름을 F로 변경(A는 바꿀 정점, F는 바뀌는 정점)\n");
	printf("K : 그래프 전체 삭제\n\n");
	printf("<여기서부터는 자신만의 기능>\n");
	printf("T(A) : 그래프 내 정점 존재 여부\n");
	printf("M : 완전 그래프 여부(각 정점에서 다른 모든 정점이 연결되었는지)\n");
	printf("U : 무방향 그래프 여부\n");
	printf("!: vertex배열 출력\n");
	printf("입력받을 vertex는 중복되지 않도록 합니다.\n\n");
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
			printf("프로그램을 종료합니다.\n");
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

		if (order[0] == 'E' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // E(AB)로 입력받은 경우
			add_edge(graph, vertex, order);
		}

		if (order[0] == 'L') {
			print_graph(graph, vertex);
		}

		if (order[0] == 'V' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // V(A)로 입력받은 경우
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

		if (order[0] == 'A' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // A(A)로 입력받은 경우
			adjacent(graph, vertex, order);
		}

		if (order[0] == '-') {
			delete_vertex(graph, vertex, order);
		}

		if (order[0] == 'P' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // P(AB)로 입력받은 경우
			path_exist(graph, vertex, order[2], order[3]);
		}

		if (order[0] == 'X') {
			num_of_vertex(graph);
		}

		if (order[0] == 'H') {
			num_of_edge(graph);
		}

		if (order[0] == 'D' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // D(AB)로 입력받은 경우
			delete_edge(graph, vertex, order[2], order[3]);
		}

		if (order[0] == 'R' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 5) { // R(AF)로 입력받은 경우
			rename_vertex(vertex, order[2], order[3]);
		}

		if (order[0] == 'K') {
			clear(graph);
			for (int i = strlen(vertex - 1); i >= 0; i--) {
				vertex[i] = NULL;
			}
		}

		if (order[0] == 'T' && order[1] == '(' && order[strlen(order) - 1] == ')' && strlen(order) == 4) { // T(A)로 입력받은 경우
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