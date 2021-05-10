#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MALLOC(p,s) ((p) = malloc(s))
#define MAX_SIZE 100

typedef enum { FALSE, TRUE } tBoolean;
typedef struct edge *edgePointer;

typedef struct edge
{
	tBoolean marked;
	int v1;
	int v2;
	edgePointer link1;
	edgePointer link2;
}Edge;

edgePointer *adjMulList;

edgePointer createE(int, int);
void insertE(edgePointer *, int, int);
void printE(int, edgePointer, int);

int main()
{
	FILE *fp = fopen("input2.txt", "r");

	int i, j;
	int v, u;
	int n1, n2;
	edgePointer Node[MAX_SIZE];  // 이것이 insert함수에서 first배열로 쓰이게 됨.

	fscanf(fp, "%d %d", &v, &u);
	MALLOC(adjMulList, sizeof(*adjMulList));

	for (i = 0; i<v; i++)
		*(adjMulList + i) = NULL;
	for (i = 0; i<u; i++)
		*(Node + i) = NULL;

	i = 0;

	while (i<u)
	{
		fscanf(fp, "%d %d", &n1, &n2);
		insertE(Node, n1, n2);
		i++;
	}

	// 각각의 Node들을 인덱스 순서대로 탐색
	//     -> 같은 정점을 공유하게 되는 Node를 찾는다면, 그것을 link에 추가하기
	// Node에 있는 하나의 정점을 중심으로 하여, 그것을 순차적으로 노드들의 두 정점들 모두와 비교해보기(무방향 그래프)
	for (i = 0; i<u - 1; i++)
	{
		for (j = i + 1; j<u; j++)
		{
			// 간선들(Node)끼리 정점 겹치는 것 구하기
			//Node[0]를 중심으로 해서 그다음것 인덱스 +1하여 순차적으로 구함

			if (Node[i]->v1 == Node[j]->v1 || Node[i]->v1 == Node[j]->v2) //Node의 첫번째 정점과 다른노드의 정점들을 비교하기
			{
				Node[i]->link1 = Node[j]; //첫번째 링크
				break;
			}
		}
		for (j = i + 1; j<u; j++)
		{
			if (Node[i]->v2 == Node[j]->v1 || Node[i]->v2 == Node[j]->v2) //Node의 두번째 정점과 다른노드들의 정점들을 비교하기
			{
				Node[i]->link2 = Node[j]; //두번째 링크
				break;
			}
		}
	}

	printf("<<<<<<<<<< edges incident to each vertex >>>>>>>>>>\n\n");
	printf("간선의 정점 출력 순서 - 입력 데이터 순서대로\n");

	for (i = 0; i<v; i++)
	{
		printf("edges incident to vertex %d : ", i); 
		printE(i, *(adjMulList + i), 1);   // 이 한줄이 (0,1) (0,2) (0,3) 이 전체를 나타냄
	}

	printf("간선의 정점 출력 순서 - 헤더노드 정점이 먼저 오게\n");
	for (i = 0; i<v; i++)
	{
		printf("edges incident to vertex %d : ", i);
		printE(i, *(adjMulList + i), 2);
	}
	return 0;
}

edgePointer createE(int n1, int n2)
{
	edgePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->v1 = n1;
	temp->v2 = n2;

	temp->link1 = NULL;
	temp->link2 = NULL;

	return temp;
}


// adjList 배열포인터 & Node를 이용해서 포인터를 노드에 연결시키기 
void insertE(edgePointer *first, int n1, int n2)
{
	int i = 0;
	edgePointer temp = createE(n1, n2);

	if (!*(adjMulList + n1))
		*(adjMulList + n1) = temp;  //포인터 순서!
	if (!*(adjMulList + n2))
		*(adjMulList + n2) = temp;

	if (first[i])  //Node에 인덱스 매기기
	{
		while (first[i])
			i++;
	}

	first[i] = temp;  //List포인터 값을 Node와 연결시킴
}

void printE(int i, edgePointer p, int choice)
{
	switch (choice)
	{
	case 1:  //입력 데이터 순서대로
		for (; p; )  // 더 이상 정점을 포함한 노드가 없을 때까지
		{
			printf("<%d, %d>", p->v1, p->v2);  // 우선 먼저 출력함
			if (i == p->v1)                    // 이후에 끝날때까지 첫번째 정점부터 탐색해서 그 정점의 링크를 타고 감.
				p = p->link1;
			else if (i == p->v2)
				p = p->link2;
		}
		printf("\n");
		break;
	case 2:  //헤더노드 정점이 먼저 오게하기
		for (; p; )
		{
			if (i == p->v1)                    // 여기서는 먼저 출력하는 것이 아님! ( but, 정점을 결정하면 그 정점의 링크노드를 따라가는 것은 동일함)
				                               // 먼저 첫번째 정점이 있는지 판단하고 있으면 출력
			{                                  // 없으면 두 번째 정점으로 가서 출력
				printf("<%d, %d> ", p->v1, p->v2);
				p = p->link1;
			}
			else if (i == p->v2)
			{
				printf("<%d, %d> ", p->v2, p->v1);
				p = p->link2;
			}
		}
		printf("\n");
		break;
	}
}