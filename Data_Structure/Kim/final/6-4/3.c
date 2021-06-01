#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s)\
	if ( !((p) = malloc(s)) ){\
		exit(1);\
	}
#define MAX_VERTICES 100

typedef struct node* nodePointer;
typedef struct node
{
	int vertex;
	nodePointer link;
}Node;

typedef struct
{
	int count;
	nodePointer link;
}hdnodes;

hdnodes graph[MAX_VERTICES] = { NULL };

nodePointer createNode(int item);
void insert(int e1, int e2);
void topSort(int n);

int main()
{
	FILE* fp;
	int v;
	int e1, e2;
	int i;

	for (i = 0; i < 6; i++)
		graph[i].count = 0;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		printf("cannot open the file");
		exit(1);
	}
	fscanf_s(fp, "%d", &v);

	while (!feof(fp))
	{
		fscanf_s(fp, "%d %d ", &e1, &e2);
		insert(e1, e2);
	}

	topSort(v);

	return 0;
}

nodePointer createNode(int item)
{
	nodePointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->vertex = item;
	temp->link = NULL;

	return temp;
}

void insert(int e1, int e2)
{
	nodePointer item = createNode(e2);

	graph[e2].count++;

	if (!graph[e1].link)
		graph[e1].link = item;
	else
	{
		item->link = graph[e1].link; 
		graph[e1].link = item;
	}
}

void topSort(int n)
{
	int i, j, k, top;
	nodePointer ptr;

	top = -1;
	for (i = 0; i < n; i++)
	{
		if (!graph[i].count)
		{  //push
			graph[i].count = top; 
			top = i;
		}
	}

	for (i = 0; i < n; i++)
	{
		if (top == -1)
		{
			printf("Network has a cycle.");
			exit(1);
		}
		else
		{ // pop
			j = top;  
			top = graph[top].count; 
			printf("%d", j);

			for (ptr = graph[j].link; ptr; ptr = ptr->link)
			{
				k = ptr->vertex; 
				graph[k].count--; 

				if (!graph[k].count)
				{
					graph[k].count = top;
					top = k;
				}
			}
			if (i != n - 1)  
				printf(" -> ");
		}
	}
}