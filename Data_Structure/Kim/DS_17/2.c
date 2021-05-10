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
	edgePointer Node[MAX_SIZE];  // �̰��� insert�Լ����� first�迭�� ���̰� ��.

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

	// ������ Node���� �ε��� ������� Ž��
	//     -> ���� ������ �����ϰ� �Ǵ� Node�� ã�´ٸ�, �װ��� link�� �߰��ϱ�
	// Node�� �ִ� �ϳ��� ������ �߽����� �Ͽ�, �װ��� ���������� ������ �� ������ ��ο� ���غ���(������ �׷���)
	for (i = 0; i<u - 1; i++)
	{
		for (j = i + 1; j<u; j++)
		{
			// ������(Node)���� ���� ��ġ�� �� ���ϱ�
			//Node[0]�� �߽����� �ؼ� �״����� �ε��� +1�Ͽ� ���������� ����

			if (Node[i]->v1 == Node[j]->v1 || Node[i]->v1 == Node[j]->v2) //Node�� ù��° ������ �ٸ������ �������� ���ϱ�
			{
				Node[i]->link1 = Node[j]; //ù��° ��ũ
				break;
			}
		}
		for (j = i + 1; j<u; j++)
		{
			if (Node[i]->v2 == Node[j]->v1 || Node[i]->v2 == Node[j]->v2) //Node�� �ι�° ������ �ٸ������� �������� ���ϱ�
			{
				Node[i]->link2 = Node[j]; //�ι�° ��ũ
				break;
			}
		}
	}

	printf("<<<<<<<<<< edges incident to each vertex >>>>>>>>>>\n\n");
	printf("������ ���� ��� ���� - �Է� ������ �������\n");

	for (i = 0; i<v; i++)
	{
		printf("edges incident to vertex %d : ", i); 
		printE(i, *(adjMulList + i), 1);   // �� ������ (0,1) (0,2) (0,3) �� ��ü�� ��Ÿ��
	}

	printf("������ ���� ��� ���� - ������ ������ ���� ����\n");
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


// adjList �迭������ & Node�� �̿��ؼ� �����͸� ��忡 �����Ű�� 
void insertE(edgePointer *first, int n1, int n2)
{
	int i = 0;
	edgePointer temp = createE(n1, n2);

	if (!*(adjMulList + n1))
		*(adjMulList + n1) = temp;  //������ ����!
	if (!*(adjMulList + n2))
		*(adjMulList + n2) = temp;

	if (first[i])  //Node�� �ε��� �ű��
	{
		while (first[i])
			i++;
	}

	first[i] = temp;  //List������ ���� Node�� �����Ŵ
}

void printE(int i, edgePointer p, int choice)
{
	switch (choice)
	{
	case 1:  //�Է� ������ �������
		for (; p; )  // �� �̻� ������ ������ ��尡 ���� ������
		{
			printf("<%d, %d>", p->v1, p->v2);  // �켱 ���� �����
			if (i == p->v1)                    // ���Ŀ� ���������� ù��° �������� Ž���ؼ� �� ������ ��ũ�� Ÿ�� ��.
				p = p->link1;
			else if (i == p->v2)
				p = p->link2;
		}
		printf("\n");
		break;
	case 2:  //������ ������ ���� �����ϱ�
		for (; p; )
		{
			if (i == p->v1)                    // ���⼭�� ���� ����ϴ� ���� �ƴ�! ( but, ������ �����ϸ� �� ������ ��ũ��带 ���󰡴� ���� ������)
				                               // ���� ù��° ������ �ִ��� �Ǵ��ϰ� ������ ���
			{                                  // ������ �� ��° �������� ���� ���
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