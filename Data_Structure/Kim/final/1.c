#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		exit(EXIT_FAILURE);\
	}
#define MAX_STACK_SIZE 100

typedef struct node* treePointer;
typedef struct node
{
	char data;		
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

treePointer stack[MAX_STACK_SIZE];
int top = -1;
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();

char expr[81];
int cnt;

typedef enum {
	lparen, rparen, plus, minus, times, divide,
	mod, eos, operand
} precedence;
precedence getToken(char* symbol, int* n);
treePointer createBinTree(void);

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void)
{
	FILE* fp;

	if (fopen_s(&fp, "input.txt", "r"))
	{
		printf("cannot open the file");
		exit(1);
	}

	printf("the length of input string should be less than 80\n");
	fgets(expr, 80, fp);
	printf("input string (postfix expression) : %s\n", expr);

	printf("creating its binary tree\n\n");
	root = createBinTree();

	printf("%-20s : ", "inorder traversal");
	cnt = 0;
	inorder(root); 	printf("\n");

	printf("%-20s : ", "preorder traversal");
	cnt = 0;
	preorder(root);	printf("\n");

	printf("%-20s : ", "postorder traversal");
	cnt = 0;
	postorder(root);	printf("\n");

	fclose(fp);
	return 0;
}

treePointer createBinTree(void)
{
	treePointer pNode;
	precedence token;
	char symbol;
	int n = 0; 
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
		//case '('		: return lparen;
		//case ')'		:  return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand; 
	}
}

void inorder(treePointer ptr)
{
	cnt++;
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{
	cnt++;
	if (ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	cnt++;
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

treePointer pop()
{
	if (top == -1)
		return stackEmpty();	
	return stack[top--];
}

treePointer stackEmpty()
{
	treePointer item;
	item = NULL;
	return item;
}

void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	printf("Stack is Full");
	exit(1);
}
