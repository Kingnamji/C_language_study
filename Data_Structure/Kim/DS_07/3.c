#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 10
#define MAX_NAME_SIZE 20
#define MAX_LEN 100

typedef struct {
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top[MAX_STACK_SIZE], bot[MAX_STACK_SIZE], boundary[MAX_STACK_SIZE];
char input_name[MAX_NAME_SIZE];

int main()
{
	FILE* fp;
	int num, size, nth, i;
	char line[MAX_LEN];
	char* tok, * ntok;

	printf("How Many Stacks ? : "); 
	scanf_s("%d", &num); 

	size = MAX_STACK_SIZE / num;
	bot[0] = -1;
	// �Է¹��� ������ ������ŭ �����
	for (i = 1; i < num; i++)
		bot[i] = bot[i - 1] + size;

	for (i = 0; i < num - 1; i++)
		boundary[i] = bot[i] + size;
	boundary[i] = MAX_STACK_SIZE - 1;

	for (i = 0; i < num; i++)
		top[i] = bot[i];


	// �Ϲ� ���
	printf(" C Language program to implement the Multiple Stacks\n");
	printf("add stack_num(0-2) name : add 0 kim\n");
	printf("delete stack_num(0-2) : delete 0\n");
	printf("sprint stack_num(0-2) : sprint 0\n");
	printf("quit\n");
	printf("*****************************************************\n\n");

	// input.txt���� ������ �޾ƿ���
	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);
	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		nth = -1; // n��° �������� �Է¹ޱ���

		if (!strcmp(tok, "add")) // ����� add���
		{
			sscanf_s(line + strlen(tok) + 1, "%d%s", &nth, input_name, sizeof(input_name));
			if ((nth < 0) || (nth >= num)) {
				printf("stack number error, try again\n");
				//break;
			}
			else if (top[nth] == boundary[nth])
				printf("Stack %d is Full\n", nth);
			else
			{
				top[nth]++;
				strcpy_s(stack[top[nth]].name, sizeof(input_name), input_name);
				printf("%s is Pushed in Stack No.%d\n", input_name, nth);
			}
		}
		else if (!strcmp(tok, "delete"))
		{
			sscanf_s(line + strlen(tok) + 1, "%d", &nth);
			if ((nth < 0) || (nth >= num)) {
				printf("stack number error, try again\n");
			}
			else if (top[nth] == bot[nth])
				printf("Stack %d is Empty\n", nth);
			else 
			{
				strcpy_s(input_name, sizeof(stack[top[nth]].name), stack[top[nth]].name);
				top[nth]--; 
				printf("%s is Popped from Stack No.%d\n", input_name, nth);
			}
		}
		else if (!strcmp(tok, "sprint"))
		{
			sscanf_s(line + strlen(tok) + 1, "%d", &nth);
			if ((nth < 0) || (nth >= num)) {
				printf("stack number error, try again\n");
			}
			else if (top[nth] > bot[nth]) {
				printf("\n");
				for (i = top[nth]; i > bot[nth]; i--)
					printf("%s \n", stack[i].name);
				printf("\n");
			}
			else
				printf("stack %d is empty\n", nth);
		}
		else if (!strcmp(tok, "quit"))
		{
			printf("\nProgram end\n");

			for (int j = 0; j < num; j++) {
				printf("\n");
				printf("stack %d :\n", j);
				for (i = top[j]; i > bot[j]; i--)
					printf("%s \n", stack[i].name);
			}
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