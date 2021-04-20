#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 5
#define MAX_NAME_SIZE 20

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

void sprint();
void stackFull();


int main(void)
{
	FILE* fp;
	char line[100];
	char* tok, * ntok;

	printf("<< stack operations where MAX_STACK_SIZE is %d>>\n ", MAX_STACK_SIZE);
	printf("The format of the stack operation is as follows!!\n");
	printf("push 1 Jung\n");
	printf("pop\n\n");

	printf("**************************************************\n");

	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);

	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		if (!(strcmp(tok, "push"))) {

			top++;
			if (top >= MAX_STACK_SIZE) {
				top--;
				stackFull();
			}
			else
				sscanf_s(line + strlen(tok) + 1, "%d%s", &stack[top].id, stack[top].name, sizeof(stack[top].name));
		}
		else if (!(strcmp(tok, "pop"))) {
			if (top == -1)
				printf("Stack is Empty\n");
			else
				top--;
		}
		else if (!(strcmp(tok, "sprint"))) {
			sprint();
		}
		else if (!(strcmp(tok, "quit"))) {
			exit(1);
		}
		else {
			printf("Wrong command! try again!\n\n");
		}

		if (!(fgets(line, sizeof(line), fp)))
			break;
	}

	return 0;
}

void sprint() {
	int i;
	for (i = 0; i <= top; i++) {
		printf("%d %s\n", stack[top-i].id, stack[top-i].name);
	}
	printf("\n");
}


void stackFull() {
	printf("\nstack is full, cannot add element\n");
	printf("current stack elements : \n");
	sprint();
}