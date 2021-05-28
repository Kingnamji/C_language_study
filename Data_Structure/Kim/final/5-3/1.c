#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
	if( !((p) = malloc( s )) ){	\
		exit(1);\
	}
#define MAX_STACK_SIZE 101
#define MAX_LEN 80
#define CASE 8
#define VARIABLE 3

typedef struct node* treePointer;
typedef struct node
{
	char data;	
	int value;	
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

typedef enum { lparen, rparen, or , and, not, eos, operand } precedence;

char expr[81];
int TF[CASE][VARIABLE] = { 0 };
int cnt;
int top = -1;

treePointer createBinTree();
treePointer stack[MAX_STACK_SIZE];
treePointer pop();
treePointer stackEmpty();
precedence getToken(char* symbol, int* n);
void push(treePointer item);
void stackFull();
void inorder(treePointer ptr);
void eval(treePointer ptr);
void createTF();

int main(void)
{
	FILE* fp;

	fopen_s(&fp, "input1.txt", "r");
	
	if (fp == NULL)
		exit(1);
	
	fgets(expr, 80, fp);

	printf("input string(postfix)   : ");
	printf("%s\n", expr);
	root = createBinTree();

	createTF();
	printf("find true condition \n");

	for (cnt = 0; cnt < CASE; cnt++) {
		eval(root);
		if (root->value) {
			printf("a=%d, b=%d, c=%d", TF[cnt][0], TF[cnt][1], TF[cnt][2]);
			if (cnt < 6)
				printf("\n");
		}		
	}

	return 0;
}

void createTF()
{
	int row, col;
	col = 0;
	
	for (row = 0; row < CASE; row++)
	{
		TF[row][col] = (row >> 2) & 1;
		TF[row][col + 1] = (row >> 1) & 1;
		TF[row][col + 2] = (row) & 1;
		col = 0;
	}

}

treePointer createBinTree()
{
	treePointer pNode;
	precedence token;
	char symbol;
	int n = 0;
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand) // 피연산자인 경우
		{
			
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;

			push(pNode);
		}
		else {
			
			if (token == not ) // 연산자 중 not
			{
				MALLOC(pNode, sizeof(*pNode));
				pNode->data = symbol;			
				pNode->rightChild = pop();	// pop을 한번만 해준다.
				pNode->leftChild = NULL;
			}
			else
			{ 
				MALLOC(pNode, sizeof(*pNode));
				pNode->data = symbol;			
				pNode->rightChild = pop();	
				pNode->leftChild = pop();	
			}
			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop(); 
}

precedence getToken(char* symbol, int* n)
{ 	*symbol = expr[(*n)++];
	switch (*symbol)
	{
		case '&': return and;	
		case '|': return or ;	
		case '~': return not;	
		case '\0': return eos;
		default: return operand;
	}
}

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void eval(treePointer ptr)
{
	if (ptr)
	{
		eval(ptr->leftChild);
		eval(ptr->rightChild);
		switch (ptr->data)
		{
		case '&':
			ptr->value = ptr->leftChild->value && ptr->rightChild->value;
			break;
		case '|':
			ptr->value = ptr->leftChild->value || ptr->rightChild->value;
			break;
		case '~':
			ptr->value = !(ptr->rightChild->value);
			break;
		case 'a':
			ptr->value = TF[cnt][0];
			break;
		case 'b':
			ptr->value = TF[cnt][1];
			break;
		case 'c':
			ptr->value = TF[cnt][2];
			break;
		default:
			ptr->value = 1;
		}


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
	printf("Stack is Full\n");
	exit(1);
}
