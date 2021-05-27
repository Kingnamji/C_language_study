#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p,s)\
	if (!((p) = malloc(s))) {\
		exit(1);\
	}

#define MAX_LEN 81
#define MAX_STACK_SIZE 100

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
void iterPreorder(treePointer node);
void iterPostorder(treePointer node);

treePointer stack[MAX_STACK_SIZE];
int cnt = 0;
int top = -1;
char expr[MAX_LEN];

int main(void) {

	FILE* fp;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		exit(1);

	printf("The length of input string should be less than %d\n", MAX_LEN - 1);
	printf("input string (postfix expression) : ");
	fgets(expr, MAX_LEN, fp);
	printf("%s\n", expr);

	root = create();
	printf("\n");

	printf("iterative preorder traversal  : ");
	iterPreorder(root);
	printf("\n");
	
	root = create();
	cnt = 0;
	printf("iterative preorder traversal  : ");
	iterPostorder(root);
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

void iterPreorder(treePointer node)
{
	top = -1;

	for (;;)
	{
		for (; node; node = node->leftChild)
		{
			push(node);
			cnt++;
			printf("%c", node->data);
		}
		node = pop();

		if (!node) break;
		node = node->rightChild;
	}
	printf("\npush_cnt = %d\n", cnt);
}
void iterPostorder(treePointer root)

{
	if (root == NULL)
		return;

	do
	{
		while (root)
		{
			if (root->rightChild)
			{
				push(root->rightChild);
				cnt++;
			}
			push(root);
			cnt++;

			root = root->leftChild;
		}

		root = pop();

		if ( root->rightChild && stack[top] == root->rightChild)
		{
			pop();
			push(root);
			cnt += 2;
			root = root->rightChild;
		}
		else
		{
			printf("%c", root->data);
			root = NULL;
		}
	} while (top != -1);

	printf("\npush_cnt = %d", cnt);
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
