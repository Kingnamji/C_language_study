#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20
#define MAX_LEN 100


typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element queue[MAX_QUEUE_SIZE];

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;
	int temp;
	int rear = 0, front = 0; // ����ִ� queue�� rear, front �⺻��.
	// �Ϲ� ���
	printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3 >>\n");
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
			temp = rear; // Queue�� Full �̸� �ٽ� ������ ����
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			// rear�� MAX_QUEUE_SIZE���� ũ�ų� ������ ��� 
			if (rear == front)
			{
				printf("queue is full, not added\n");
				rear = temp;
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
			front = (front+1)%MAX_QUEUE_SIZE; //queue�� ������� ���� ���
		}
		else if (!strcmp(tok, "qprint"))
		{
			if (front<rear) // front ���� rear�� ���� Ŭ ��
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

	return 0;
}
