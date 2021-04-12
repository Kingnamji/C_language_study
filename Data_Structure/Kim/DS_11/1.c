#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 24
#define MAX_STACK_SIZE 100
#define FALSE 0
#define TRUE 1

#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
		exit(1);\
	}

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
}node;

// stack
int stack[MAX_STACK_SIZE];
int top = -1;

void push(int item);
int stackEmpty();
int pop();
void stackFull();

int main(void)
{
	FILE* fp;
	int out[MAX_SIZE];
	int i, j, x, y, size;
	nodePointer seq[MAX_SIZE];
	nodePointer temp;
	

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		exit(1);
	}
	fscanf_s(fp, "%d", &size);
	
	for (i = 0; i < size; i++)
	{ 
		out[i] = FALSE;
		seq[i] = NULL;
	}
	
	// size 관련 출력
	printf("/* MAX_SIZE of a set S : %d*/\n", MAX_SIZE);
	printf("current size of S : %d\n", size);
	printf("S = { 0");
	for (i = 1; i < size; i++) {
		printf(", %d", i);
	}
	printf(" }\n");		

	// 순서쌍 데이터 입력 및 출력
	printf("input pairs :");
	fscanf_s(fp, "%d %d", &x, &y);
	while (!feof(fp)) {
		printf(" %dR%d", x, y);
		MALLOC(temp, sizeof(*temp));
		temp->data = y; temp->link = seq[x]; seq[x] = temp;
		MALLOC(temp, sizeof(*temp));
		temp->data = x; temp->link = seq[y]; seq[y] = temp;
		fscanf_s(fp, "%d %d", &x, &y);
	}
	fclose(fp); // file close

	printf("\n\nsymmetric 관계 linked List\n");

	for (i = 0; i < size; i++) {
		printf("%d : symmetric 관계 : \n", i);
		temp = seq[i];
		while (temp) {
			printf("(%p %2d %p)  ", temp, temp->data, temp->link);
			temp = temp->link;
		}
		printf("\n");
	}

	for (i = 0; i < size; i++)
	{
		if (out[i] == FALSE)
		{
			printf("\n");
			printf("New class: %4d", i);
			out[i] = TRUE;		
			temp = seq[i]; 
			top = -1;
			for (;;){
				while (temp){
					j = temp->data;
					if (out[j] == FALSE){
						printf("%4d", j); 
						out[j] = TRUE;
						push(j);
						temp = temp->link;
					}
					else
					{
						temp = temp->link;
					}
				} 

				if (top == -1) 
					break;
				temp = seq[pop()];
				
			}
		}
	}
	printf("\n");


	return 0;
}


void push(int item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

int stackEmpty()
{
	int item;
	item = -1;  
	return item;
}

int pop() {
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}

void stackFull() {
	int item;

	printf("current stack elements : \n");
	while (top > -1)
	{
		item = pop();
		printf("%d\n", item);
	}
	exit(1);
}