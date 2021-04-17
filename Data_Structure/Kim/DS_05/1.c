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
int top = -1; // 처음에는 스택이 비어있으므로 -1로 초기화

void printStack();
void push();

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;	
	
	// 일반 출력
	printf("<< stack operations where MAX_STACK_SIZE is 5 >>\n");
	printf("The format of the stack operation is as follows!!\n");
	printf("push 1 Jung \npop\n\n");
	printf("*****************************************************\n");

	// input.txt에서 데이터 받아오기
	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);
	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		if (!strcmp(tok, "push")) // 명령이 push라면
		{
			top++;
			// 가득 차 있는 경우 top = MAX_STACK_SIZE -1
			// 해당 경우에 위의 연산이 합해져 top = MAX_STACK_SIZE가 된다.
			if (top >= MAX_STACK_SIZE) // 따라서 가득 찬 경우에 해당
			{
				top--; // top이 ++ 연산으로 인해 최대 크기보다 커졌으므로 다시 줄여준다.
				printf("stack is full, cannot add element\n");
				printf("current stack elements :\n");
				for (int i = 0; i <= top; i++) // 현재 스택의 내용을 출력
					printf("%d %s\n", stack[top - i].id, stack[top - i].name);				
				break;
			}
			sscanf_s(line + strlen(tok) + 1, "%d%s", &stack[top].id, stack[top].name, sizeof(stack[top].name));
		}
		else if (!strcmp(tok, "pop"))
		{
			if (top == -1) // stack이 empty이면
			{
				printf("\nstack is empty\n");
				break;
			}
			// stack이 비어있지 않은 경우
			top--; // top을 줄여준다.
		}
		else if (!strcmp(tok, "sprint"))
		{
			for (int i = 0; i <= top; i++) // 현재 스택의 내용을 출력
				printf("%d %s\n", stack[top-i].id, stack[top-i].name);
			printf("\n\n");
		}
		else if (!strcmp(tok, "quit"))
		{
			exit(1);
		}
		else // 위의 어떤 command에도 해당하지 않는 경우
		{
			printf("wrong command! try again!\n\n");
		}
		
		// 명령어에 관한 실행이 끝난 후
		if (!(fgets(line, sizeof(line), fp))) // 다음 줄을 받아온다
			break;
	}
	
	fclose(fp); 

	return 0;
}