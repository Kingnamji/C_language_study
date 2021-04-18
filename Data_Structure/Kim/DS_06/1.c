#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20
#define MAX_LEN 100
#define MALLOC(p,s)  \
	if (! ((p) = malloc(s))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

void copy(element* a, element* b, element* c);
void queueFull();

element *queue;
int capacity = 2;
int rear = 0, front = 0; // ����ִ� queue�� rear, front �⺻��.

int main()
{
	MALLOC(queue, sizeof(element) * capacity); // �ʱ��� �޸� �Ҵ�
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;
	
	// �Ϲ� ���
	printf("<< Circular queue operations using dynamic allocated array, where the initial capacity is 2 >>\n");
	printf("add 1 Jung \ndelete\n\n");
	printf("*****************************************************\n");

	// input.txt���� ������ �޾ƿ���
	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);

	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		if (!strcmp(tok, "add")) // ����� add���
		{
			rear = (rear + 1) % capacity;
			// rear�� capacity ���� ũ�ų� ������ ��� 
			if (rear == front)
			{
				queueFull(); // �Լ� ����				
				rear = rear+1;
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
				
				printf("queue capacity is doubled, \n"); // ���� ���
				printf("current queue capacity is %d\n", capacity);
				if (front < rear) // front ���� rear�� ���� Ŭ ��
				{
					for (int i = front + 1; i <= rear; i++)
						printf("%d, %s\n", queue[i].id, queue[i].name);
					printf("\n\n");
				}
				else if (rear < front) // rear ���� front �� ���� ���� ��
				{
					for (int i = 0; i <= rear; i++)
						printf("%d, %s\n", queue[i].id, queue[i].name);
					printf("\n\n");
				}
			}
			else {
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
			}
		}
		else if (!strcmp(tok, "delete"))
		{
			if (front == rear) // queue�� empty
			{
				printf("queue is empty. cannot delete element.\n");
				break;
			}
			front = (front + 1) % capacity; //queue�� ������� ���� ���
		}
		else if (!strcmp(tok, "qprint"))
		{
			if (front < rear) // front ���� rear�� ���� Ŭ ��
			{
				for (int i = front + 1; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n\n");
			}
			else if (rear < front) // rear ���� front �� ���� ���� ��
			{
				for (int i = 0; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n\n");
			}
			// rear�� front ���� �������� ���� ����
		}
		else if (!strcmp(tok, "quit"))
		{
			printf("end of program!!\n");
			exit(1);
		}
		else // ���� � command���� �ش����� �ʴ� ���
		{
			printf("wrong command! try again!\n");
		}

		// ��ɾ ���� ������ ���� ��
		if (!(fgets(line, sizeof(line), fp))) // ���� ���� �޾ƿ´�
			break;

	}

	fclose(fp);
	free(queue);

	return 0;
}

void copy(element* a, element* b, element* c)
{
	while (a != b)
		*c++ = *a++;
}

void queueFull()
{ 
	int start;
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	if (start < 2)
		copy(queue + start, queue + start + capacity - 1, newQueue);
	else
	{
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
	free(queue);
	queue = newQueue;
}
