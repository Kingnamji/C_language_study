#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
	if (!((p) = malloc(s))) {\
		exit(1);\
	}

#define MAX_LEN 81
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

typedef struct node* treePointer;
typedef struct node
{
	char data;
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand }precedence;

precedence getToken(char* symbol, int* n);
treePointer create();
treePointer pop();
treePointer stackEmpty();
void push(treePointer item);
void stackFull();
void addq(treePointer item);
void queueFull();
treePointer queueEmpty();
treePointer deleteq();

void iterinorder(treePointer node);
void levelOrder(treePointer ptr);

treePointer stack[MAX_STACK_SIZE];
treePointer queue[MAX_QUEUE_SIZE];

int front=0, rear=0;
int cnt = 0;
int top = -1, i = -1;

char order[MAX_LEN];
char expr[MAX_LEN];

int main(void) {

	FILE* fp;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		exit(1);

	printf("The length of input string should be less than %d\n", MAX_LEN-1);
	printf("input string (postfix expression) from input.txt : ");
	fgets(expr, MAX_LEN, fp);
	printf("%s\n", expr);

	root = create();
	printf("\n");

	printf("iterative inorder traversal      : ");
	iterinorder(root);
	printf("\n");

	printf("스택에 들어가는 데이터의 순서    : ");
	for (int j = 0; j < i; j++) {
		printf("%c ", order[j]);
	}
	printf("\n\n");

	printf("level order traversal            : ");
	levelOrder(root);
	printf("\n");


	fclose(fp);

	return 0;
}

treePointer create(void)
{
	treePointer pNode;
	precedence token;
	char symbol;
	int n = 0;

	printf("creating its binary tree\n");
	top = -1;

	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{

			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;

			push(pNode);
		}
		else {

			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->rightChild = pop();
			pNode->leftChild = pop();

			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}


precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}


treePointer stackEmpty()
{
	treePointer item = NULL;
	return item;
}

treePointer pop()
{
	if (top == -1)
		return stackEmpty();
	return stack[top--];
}


void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	
	stack[++top] = item;
}

void stackFull()
{
	printf("Stack is full\n");
	exit(1);
}

void addq(treePointer item)
{ 
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queueFull(); 
	queue[rear] = item;
}

void queueFull()
{
	fprintf(stderr, "queue is full\n");
	exit(1);
}

treePointer deleteq()
{ 
	if (front == rear)
		return queueEmpty(); 
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

treePointer queueEmpty()
{
	treePointer item;
	item = NULL;  
	return item;
}


void iterinorder(treePointer node)
{
	order[i++] = node->data;
	for (;;) {
		for (; node; node = node->leftChild) {
			push(node);			
			order[i++] = node->data;
		}
		node = pop();
		if (!node)
			break;
		printf("%c ", node->data);
		node = node->rightChild;
	}
}

void levelOrder(treePointer ptr)
{
	if (!ptr)
		return;

	addq(ptr);

	for (;;) {
		ptr = deleteq();
		if (ptr) {
			printf("%c ", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else 
			break;
	}
}
