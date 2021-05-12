#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1
#define MAX_SIZE 100
#define MALLOC(p,s) ((p) = malloc(s))

typedef struct queue *queuePointer;
typedef struct queue
{
	int data;
	queuePointer link;
}Queue;

queuePointer graph[MAX_SIZE] = { 0, };
int visited[MAX_SIZE] = { 0, };
queuePointer front, rear;

void addq(int);
int deleteq();
queuePointer createL(int);
void insertL(int, int);
void bfs(int);
void printL(queuePointer);

int main()
{
	FILE *fp = fopen("input2.txt", "r");
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

	printf("<<<<<<<<<< Adjacency queue >>>>>>>>>>\n");
	for (i = 0; i<v; i++)
	{
		printf("graph[%d] : ", i);
		printL(graph[i]->link);
		printf("\n");
	}

	printf("\n<<<<<<<<<< Breadth First Search >>>>>>>>>>\n");
	for (i = 0; i<v; i++)
	{
		printf("bfs<%d> : ", i);
		bfs(i);
		printf("\n");

		for (j = 0; j<v; j++)
			visited[j] = 0;
	}

	return 0;
}

void addq(int data)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->data = data;
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
	int deleted;  

	if (!temp)
		exit(EXIT_FAILURE);

	deleted = front->data;
	front = temp->link; 
	free(temp); 

	return deleted; 
}

queuePointer createL(int data)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->data = data;
	temp->link = NULL;

	return temp;
}

void insertL(int n1, int n2)
{
	queuePointer temp = createL(n2);

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
	queuePointer temp;
	front = rear = NULL;

	visited[v] = TRUE;
	printf("%5d", v);
	addq(v);    

	while (front)
	{
		v = deleteq();  

		for (temp = graph[v]; temp; temp = temp->link) 
		{
			if (!visited[temp->data])
			{
				printf("%5d", temp->data);
				addq(temp->data);
				visited[temp->data] = TRUE;
			}
		}
	}
}

void printL(queuePointer p)
{
	for (; p; p = p->link)
		printf("%5d", p->data);
}