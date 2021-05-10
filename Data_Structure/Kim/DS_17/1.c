#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MALLOC(p,s) ((p) = malloc(s))

typedef struct listNode *listPointer;
typedef struct listNode
{
	int data;
	listPointer link;
}ListNode;

listPointer *adjList;

void insertL(int, int);
listPointer createL(int);
void printL(listPointer *);

int main()
{
	FILE *fp = fopen("input.txt", "r");
	char menu;
	int i;
	int v, u;
	int n1, n2;
	listPointer temp;

	fscanf(fp, "%c %d %d", &menu, &v, &u);
	MALLOC(adjList, sizeof(*adjList));
	MALLOC(*adjList, v * sizeof(**adjList));

	for (i = 0; i<v; i++)
		*(adjList + i) = NULL;  //�迭 ������ �ʱ�ȭ

	if (menu == 'd')
	{
		i = 0;
		while (i<u)
		{
			fscanf(fp, "%d %d", &n1, &n2);
			insertL(n1, n2);
			i++;
		}
	}
	else if (menu == 'u')
	{
		i = 0;
		while (i<u)
		{
			fscanf(fp, "%d %d ", &n1, &n2);

			insertL(n1, n2);
			insertL(n2, n1);
			i++;
		}
	}

	printf("<<<<<<<<<< Adjacency List >>>>>>>>>>\n");
	for (i = 0; i<v; i++)
	{
		printf("adjList[%d] : ", i);
		printL(adjList + i);
		printf("\n");
	}
	return 0;
}

void insertL(int n1, int n2)
{
	listPointer temp = createL(n2);

	if (!(*(adjList + n1)))
		*(adjList + n1) = temp;
	else
	{
		temp->link = *(adjList + n1);  // ���ο� temp�� �ְ� �װ��� link�� ����Ű�� ���� *(adjList + n1)�� ����Ű�� ������ �Ű���.
		*(adjList + n1) = temp;  // �ᱹ, ������ *(adjList + n1)�� ������ �Ű����� �տ� �߰��Ǿ��� temp�� ����Ű�� ��. (�갡 ���ο�  *(adjList + n1)��)
	}
}

listPointer createL(int data)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp));

	temp->data = data;
	temp->link = NULL;

	return temp;
}

void printL(listPointer *p)
{
	listPointer temp;

	for (temp = *p; temp; temp = temp->link)
		printf("%5d", temp->data);
}
