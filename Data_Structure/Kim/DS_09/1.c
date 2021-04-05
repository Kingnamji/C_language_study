#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 3
#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct {
	int class; // 학반
	int grade; // 성적
}element;

typedef struct stack* stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
};

stackPointer top[MAX_STACK_SIZE]; // Linked Stacks

void push(int i, element item);
element stackEmpty();
element pop(int i);

int main()
{
	FILE* fp;
	element data_f;
	int i;
	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);


	fscanf_s(fp, "%d %d %d", &i, &data_f.class, &data_f.grade);
	while (!feof(fp))
	{
		push(i, data_f);
		fscanf_s(fp, "%d %d %d", &i, &data_f.class, &data_f.grade);
	}

	printf("과목번호,  학반,  성적\n");
	for (i = 0; i < MAX_STACK_SIZE; i++)
	{
		printf("************************\n");
		while (top[i])
		{
			data_f = pop(i);
			printf("%8d%7d%7d\n", i, data_f.class, data_f.grade);
		}
	}
	
	fclose(fp);

	return 0;
}

void push(int i, element item)
{
	stackPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element stackEmpty()
{
	element item;
	item.grade = -1;
	return item;
}

element pop(int i)
{
	element item;
	stackPointer temp = top[i];

	if (!temp)
		return stackEmpty();
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}