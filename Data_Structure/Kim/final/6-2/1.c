#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !( (p) = malloc(s) ) ){\
		exit(1);\
	}

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct node* nodePointer;
typedef struct node
{
	int vertex;
	nodePointer link;
}Node;

nodePointer graph[MAX] = { NULL };
int visited[MAX] = { 0 };

nodePointer create(int vertex);
void insert(int n1, int n2);
void dfs(int v);
void printList(nodePointer p);

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

	printf("\n<<<<<<<<<< Depth First Search >>>>>>>>>>\n");
	for (i = 0; i < v; i++)
	{
		printf("dfs<%d> : ", i);
		dfs(i);
		printf("\n");

		for (j = 0; j < v; j++)
			visited[j] = 0;
	}

	fclose(fp);

	return 0;
}

nodePointer create(int vertex)
{
	nodePointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->vertex = vertex;
	temp->link = NULL;

	return temp;
}

void insert(int n1, int n2)
{
	nodePointer temp = create(n2);

	if (!graph[n1]->link)
		graph[n1]->link = temp;
	else
	{
		temp->link = graph[n1]->link;
		graph[n1]->link = temp;
	}
}

void dfs(int v)
{
	nodePointer w;
	visited[v] = TRUE;

	printf("%5d", v);

	for (w = graph[v]; w; w = w->link)
	{
		if (!visited[w->vertex])
			dfs(w->vertex);
	}
}

void printList(nodePointer p)
{
	for (; p; p = p->link)
		printf("%5d", p->vertex);
}