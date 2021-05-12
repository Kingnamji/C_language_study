#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100
#define MALLOC(p,s) ((p) = malloc(s))

typedef struct list *listPointer;
typedef struct list
{
	int data;
	listPointer link;
}List;

listPointer graph[MAX_SIZE] = { 0, };
int visited[MAX_SIZE] = { 0, };

listPointer createL(int);
void insertL(int, int);
void dfs(int);
void printL(listPointer);
void connected(int);

int main()
{
	FILE *fp = fopen("input3.txt", "r");
	//   FILE *fp = fopen("input2.txt", "r");

	int v, e;
	int i, j;
	int n1, n2;

	visited[-1] = TRUE;

	fscanf(fp, "%d %d", &v, &e);
	for (i = 0; i<v; i++)
		graph[i] = createL(-1);

	for (i = 0; i<e; i++)
	{
		fscanf(fp, "%d %d", &n1, &n2);
		insertL(n1, n2);
		insertL(n2, n1);
	}

	printf("<<<<<<<<<< Adjacency List >>>>>>>>>>\n");
	for (i = 0; i<v; i++)
	{
		printf("graph[%d] : ", i);
		printL(graph[i]->link);
		printf("\n");
	}

	printf("\n<<<<<<<<<< Connected Components >>>>>>>>>>\n");
	connected(v);

	return 0;
}

listPointer createL(int data)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->data = data;
	temp->link = NULL;

	return temp;
}

void insertL(int n1, int n2)
{
	listPointer temp = createL(n2);

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
	listPointer temp;

	visited[v] = TRUE;
	printf("%5d", v);

	for (temp = graph[v]; temp; temp = temp->link)
	{
		if (!visited[temp->data])
			dfs(temp->data);
	}
}

void printL(listPointer p)
{
	for (; p; p = p->link)
		printf("%5d", p->data);
}


void connected(int v)
{
	int i;
	int count = 0;

	for (i = 0; i<v; i++)
	{
		if (!visited[i])
		{
			printf("connected component %d : ", ++count);
			dfs(i);
			printf("\n");
		}
	}
}