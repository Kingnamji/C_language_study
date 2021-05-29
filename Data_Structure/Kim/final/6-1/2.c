#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !((p)= malloc(s)) ){\
		exit(1);\
	}

#define MAX_SIZE 100

typedef struct edgeNode* edgePointer;
typedef struct edgeNode {
	int head;
	int vert1;
	int vert2;
	edgePointer link1;
	edgePointer link2;
}edgeNode;
edgePointer* adjMulList;

edgePointer create(int vertex1, int vertex2);
void insert(edgePointer* first, int vertex1, int vertex2);
void printList(int i, edgePointer p, int order);

int main(void)
{
	FILE* fp;
	int vertex1, vertex2;
	int v, e; // vertex, edge
	int i, j;
	edgePointer Node[MAX_SIZE];

	fopen_s(&fp, "input1.txt", "r");
	//fopen_s(&fp, "input2.txt", "r"); 

	if (fp == NULL) {
		exit(1);
	}
	fscanf_s(fp, "%d %d", &v, &e);

	MALLOC(adjMulList, sizeof(edgePointer*));

	for (i = 0; i < v; i++) {
		*(adjMulList+i) = NULL;
	}

	for (i = 0; i < e; i++) {
		*(Node+i) = NULL;
	}

	i = 0;

	while (i < e)
	{
		fscanf_s(fp, "%d %d", &vertex1, &vertex2);
		insert(Node, vertex1, vertex2);
		i++;
	}

	
	for (i = 0; i < e - 1; i++)
	{
		for (j = i + 1; j < e; j++)
		{
			if (Node[i]->vert1 == Node[j]->vert1 || Node[i]->vert1 == Node[j]->vert2) 
			{
				Node[i]->link1 = Node[j]; 
				break;
			}
		}
		for (j = i + 1; j < e; j++)
		{
			if (Node[i]->vert2 == Node[j]->vert1 || Node[i]->vert2 == Node[j]->vert2) 
			{
				Node[i]->link2 = Node[j];
				break;
			}
		}
	}

	printf("<<<<<<<<<<<<<<<< edges incident to each vertex >>>>>>>>>>>>>>>\n\n");

	printf("간선의 정점 출력 순서 - 입력데이터 순서대로\n");
	for (i = 0; i < v; i++)
	{
		printf("edges incident to vertex %d : ", i);
		printList(i, adjMulList[i], 1);   
	}

	printf("\n간선의 정점 출력 순서 - 헤더노드 정점이 먼저 오게\n");
	for (i = 0; i < v; i++)
	{
		printf("edges incident to vertex %d : ", i);
		printList(i, adjMulList[i], 2);
	}

	fclose(fp);

	return 0;
}

edgePointer create(int vertex1, int vertex2)
{
	edgePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->vert1 = vertex1;
	temp->vert2 = vertex2;

	temp->link1 = NULL;
	temp->link2 = NULL;

	return temp;
}


void insert(edgePointer* first, int vertex1, int vertex2)
{
	int i = 0;
	edgePointer temp = create(vertex1, vertex2);

	if (!*(adjMulList + vertex1))
		*(adjMulList + vertex1) = temp;  
	if (!*(adjMulList + vertex2))
		*(adjMulList + vertex2) = temp;

	if (first[i]) 
	{
		while (first[i])
			i++;
	}

	first[i] = temp;
}

void printList(int i, edgePointer p, int order)
{
	switch (order)
	{
	case 1: 
		for (; p; )  
		{
			printf("(%d, %d) ", p->vert1, p->vert2); 
			if (i == p->vert1)                   
				p = p->link1;
			else if (i == p->vert2)
				p = p->link2;
		}
		printf("\n");
		break;
	case 2:  
		for (; p; )
		{
			if (i == p->vert1)       
									
			{                       
				printf("(%d, %d) ", p->vert1, p->vert2);
				p = p->link1;
			}
			else if (i == p->vert2)
			{
				printf("(%d, %d) ", p->vert2, p->vert1);
				p = p->link2;
			}
		}
		printf("\n");
		break;
	}
}