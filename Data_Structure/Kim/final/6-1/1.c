#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !((p)= malloc(s)) ){\
		exit(1);\
	}


typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer* adjList;

listPointer create(int vertex);
void insert(int vertex1, int vertex2);
void printList(listPointer* p);

int main(void)
{
	FILE* fp;
	char graph;
	int vertex1, vertex2;
	int v, e; // vertex, edge
	int i;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		exit(1);
	}
	
	fscanf_s(fp, "%c %d %d", &graph, 1, &v, &e);

	MALLOC(adjList, sizeof(listPointer*));
	MALLOC(*adjList, v * sizeof(listPointer**));
	for (i = 0; i < v; i++) {
		adjList[i] = NULL;
	}

	if (graph == 'u') {
		i = 0;
		while (i < e)
		{
			fscanf_s(fp, "%d %d ", &vertex1, &vertex2);
			// undirected
			insert(vertex1, vertex2);
			insert(vertex2, vertex1);
			i++;
		}
	}
	else if (graph == 'd') {
		i = 0;
		while (i < e)
		{
			fscanf_s(fp, "%d %d ", &vertex1, &vertex2);
			// directed
			insert(vertex1, vertex2);
			i++;
		}
	}
	else {
		printf("그래프의 종류를 다시 입력하세요.\n");
		exit(1);
		fclose(fp);
	}

	printf("<<<<<<<<<<<<<<<< Adjacency List >>>>>>>>>>>>>>>\n");
	for (i = 0; i < v; i++) {
		printf("adjList[%d] :", i);
		printList(adjList + i);
		printf("\n");
	}

	fclose(fp);

	return 0;
}


listPointer create(int vertex) {
	listPointer temp;

	MALLOC(temp, sizeof(*temp));

	temp->data = vertex;
	temp->link = NULL;

	return temp;
}


void insert(int vertex1, int vertex2) {
	listPointer temp;

	temp = create(vertex2);

	if (!(*(adjList + vertex1))) {
		*(adjList + vertex1) = temp;
	}
	else
	{
		temp->link = *(adjList + vertex1);
		*(adjList + vertex1) = temp;  
	}
}

void printList(listPointer* p)
{
	listPointer temp;

	for (temp = *p; temp; temp = temp->link)
		printf(" %4d", temp->data);
}