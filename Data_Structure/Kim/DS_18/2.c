#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !( (p) = malloc(s) ) ){\
		exit(1);\
	}

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct queue* queuePointer;
typedef struct queue
{
	int vertex;
	queuePointer link;
}queue;

queuePointer front, rear;
queuePointer graph[MAX] = { NULL };
int visited[MAX] = { 0 };

queuePointer create(int vertex);
void addq(int);
int deleteq();
void insert(int n1, int n2);
void bfs(int v);
void printList(queuePointer p);

int main(void)
{
	FILE* fp;
	int i, j;
	int n1, n2;
	int v, e; // vertex, edge

	visited[-1] = 1;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		exit(1);
	}

	fscanf_s(fp, "%d %d", &v, &e);
	for (i = 0; i < v; i++)
		graph[i] = create(-1);

	for (i = 0; i < e; i++)
	{
		fscanf_s(fp, "%d %d", &n1, &n2);
		insert(n1, n2);
		insert(n2, n1);
	}

	printf("<<<<<<<<<< Adjacency List >>>>>>>>>>\n");
	for (i = 0; i < v; i++)
	{
		printf("graph[%d] : ", i);
		printList(graph[i]->link);
		printf("\n");
	}

	printf("\n<<<<<<<<<< Breadth First Search >>>>>>>>>>\n");
	for (i = 0; i < v; i++)
	{
		printf("bfs<%d> : ", i);
		bfs(i);
		printf("\n");

		for (j = 0; j < v; j++)
			visited[j] = 0;
	}

	fclose(fp);

	return 0;
}

queuePointer create(int vertex) {
	queuePointer temp;

	MALLOC(temp, sizeof(*temp));

	temp->vertex = vertex;
	temp->link = NULL;

	return temp;
}

void addq(int vertex)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->vertex = vertex;
	temp->link = NULL;

	if (front)
		rear->link = temp;
	else
		front = temp;

	rear = temp;
}

int deleteq()
{
	queuePointer temp = front;
	int delete_v;

	if (!temp) // queue가 비었을 때 
		exit(1);

	delete_v = front->vertex;
	front = temp->link;

	free(temp);

	return delete_v;
}

void insert(int n1, int n2) {
	queuePointer temp = create(n2);

	if (!graph[n1]->link)
		graph[n1]->link = temp;
	else
	{
		temp->link = graph[n1]->link;
		graph[n1]->link = temp;
	}
}

void bfs(int v)
{
	queuePointer w;
	front = rear = NULL;

	printf("%5d", v);
	visited[v] = TRUE;

	addq(v);
	while (front) {
		v = deleteq();
		for (w = graph[v]; w; w = w->link)
		{
			if (!visited[w->vertex]) {
				printf("%5d", w->vertex);
				addq(w->vertex);
				visited[w->vertex] = TRUE;
			}
		}
	}
}

void printList(queuePointer p)
{
	for (; p; p = p->link)
		printf("%5d", p->vertex);
}