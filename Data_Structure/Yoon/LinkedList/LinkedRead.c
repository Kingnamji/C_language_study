#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

int main(void)
{
	Node* head = NULL; // ����Ʈ�� �Ӹ��� ����Ű�� ������ ����
	Node* tail = NULL; // ����Ʈ�� ������ ����Ű�� ������ ����
	Node* cur = NULL; // ����� �������� ��ȸ�� ���Ǵ� ������ ����

	Node* newNode = NULL;
	int readData;

	// ������ �Է�
	while (1)
	{
		printf("�ڿ����� �Է��ϻ�� : ");
		scanf("%d", &readData);
		if (readData < 1) // stop
			break;

		// ��� �߰�
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL) // ù ��° �����
			head = newNode; // ù ��° ��带 head�� ����Ű�� ��
		else
			tail->next = newNode;

		tail = newNode; // ����� ���� tail�� ����Ű�� ��
	}
	printf("\n");

	// �Է� ���� �������� ��°���
	printf("�Է� ���� �������� ��ü ���! \n");
	
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�.\n");
	}
	else {
		cur = head;
		printf("%d ", cur->data); // ù ��° ������ ���
	
		while (cur->next != NULL) // �� ��° ���� �� ���
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// �޸� ����
	if (head == NULL)
	{
		printf("�޸� ������ ��尡 ����. \n");
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		// ù ��° ��� ����
		printf("%d�� �����մϴ�. \n", head->data);
		free(delNode); 

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d�� �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}