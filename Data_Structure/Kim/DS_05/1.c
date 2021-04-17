#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20
#define MAX_LEN 100

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top = -1; // ó������ ������ ��������Ƿ� -1�� �ʱ�ȭ

void printStack();
void push();

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;	
	
	// �Ϲ� ���
	printf("<< stack operations where MAX_STACK_SIZE is 5 >>\n");
	printf("The format of the stack operation is as follows!!\n");
	printf("push 1 Jung \npop\n\n");
	printf("*****************************************************\n");

	// input.txt���� ������ �޾ƿ���
	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);
	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		if (!strcmp(tok, "push")) // ����� push���
		{
			top++;
			// ���� �� �ִ� ��� top = MAX_STACK_SIZE -1
			// �ش� ��쿡 ���� ������ ������ top = MAX_STACK_SIZE�� �ȴ�.
			if (top >= MAX_STACK_SIZE) // ���� ���� �� ��쿡 �ش�
			{
				top--; // top�� ++ �������� ���� �ִ� ũ�⺸�� Ŀ�����Ƿ� �ٽ� �ٿ��ش�.
				printf("stack is full, cannot add element\n");
				printf("current stack elements :\n");
				for (int i = 0; i <= top; i++) // ���� ������ ������ ���
					printf("%d %s\n", stack[top - i].id, stack[top - i].name);				
				break;
			}
			sscanf_s(line + strlen(tok) + 1, "%d%s", &stack[top].id, stack[top].name, sizeof(stack[top].name));
		}
		else if (!strcmp(tok, "pop"))
		{
			if (top == -1) // stack�� empty�̸�
			{
				printf("\nstack is empty\n");
				break;
			}
			// stack�� ������� ���� ���
			top--; // top�� �ٿ��ش�.
		}
		else if (!strcmp(tok, "sprint"))
		{
			for (int i = 0; i <= top; i++) // ���� ������ ������ ���
				printf("%d %s\n", stack[top-i].id, stack[top-i].name);
			printf("\n\n");
		}
		else if (!strcmp(tok, "quit"))
		{
			exit(1);
		}
		else // ���� � command���� �ش����� �ʴ� ���
		{
			printf("wrong command! try again!\n\n");
		}
		
		// ��ɾ ���� ������ ���� ��
		if (!(fgets(line, sizeof(line), fp))) // ���� ���� �޾ƿ´�
			break;
	}
	
	fclose(fp); 

	return 0;
}