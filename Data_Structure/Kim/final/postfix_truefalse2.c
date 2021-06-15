#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_LEN 80

#define MALLOC(p,s)\
	if( !( (p) = malloc(s) ) ){\
		printf("cannot malloc");\
		exit(1);\
	}


typedef enum {lparen, rparen, or, and, not, eos, operand} precedence;
typedef struct node* nodePointer;
typedef struct node {
	int value;
	char data;
	nodePointer leftChild, rightChild;
}node;
nodePointer root = NULL;

nodePointer stack[MAX_STACK_SIZE];
char expr[MAX_LEN];
int top = -1;
int vtable[16][4] = { 0 };
int tcnt;

nodePointer createBinTree();
nodePointer pop();
nodePointer stackEmpty();
precedence getToken(char* symbol, int* n);
void stackFull();
void push(nodePointer item);
void eval(nodePointer ptr);
void maketable();

int main()
{
	FILE* fp;

	fopen_s(&fp, "input2.txt", "r");
	if (fp == NULL) {
		printf("cannot open the file");
		exit(1);
	}

	maketable();

	fgets(expr, MAX_LEN, fp);
	printf("input string(postfix)    :  %s\n\n", expr);
	
	root = createBinTree();

	printf("find true condition\n");
	for (tcnt = 0; tcnt < 16; tcnt++) {
		eval(root);
		if (root->value) {
			printf("a=%d, b=%d, c=%d, d=%d\n", vtable[tcnt][0], vtable[tcnt][1], vtable[tcnt][2], vtable[tcnt][3]);
		}
	}

	fclose(fp);

	return 0;
}


nodePointer createBinTree() {
	nodePointer pNode;
	precedence token;
	char symbol;
	int n=0;
	top = -1;

	token = getToken(&symbol, &n);

	while (token != eos) 
	{
		if (token == operand) {
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;
			push(pNode);
		}
		else {
			if (token == not) {
				MALLOC(pNode, sizeof(*pNode));
				pNode->data = symbol;
				pNode->rightChild = pop();
				pNode->leftChild = NULL;
			}
			else {
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

nodePointer pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

nodePointer stackEmpty()
{
	return NULL;
}

precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case'(': return lparen;
	case')': return rparen;
	case'&': return and;
	case'|': return or;
	case'~': return not;
	case'\0': return eos;
	default: return operand;
	}
}

void stackFull() {
	printf("stack is FUll");
	exit(1);
}

void push(nodePointer item) {
	if (top == MAX_STACK_SIZE - 1) {
		stackFull();
	}
	stack[++top] = item;
}
void maketable() {
	int row, col = 0;
	for (row = 0; row < 16; row++) {
		vtable[row][col] = (row >> 3) & 1;
		vtable[row][col+1] = (row >> 2) & 1;
		vtable[row][col+2] = (row >> 1) & 1;
		vtable[row][col+3] = (row) & 1;
		col = 0;
	}
}

void eval(nodePointer ptr) {
	if (ptr) {
		eval(ptr->leftChild);
		eval(ptr->rightChild);

		switch (ptr->data) {
		case '~':
			ptr->value = !(ptr->rightChild->value);
			break;
		case '&':
			ptr->value = ptr->leftChild->value && ptr->rightChild->value;
			break;
		case '|':
			ptr->value = ptr->leftChild->value || ptr->rightChild->value;
			break;
		
		case 'a':
			ptr->value = vtable[tcnt][0];
			break;
		case 'b':
			ptr->value = vtable[tcnt][1];
			break;
		case 'c':
			ptr->value = vtable[tcnt][2];
			break;
		case 'd':
			ptr->value = vtable[tcnt][3];
			break;
		defualt:
			ptr->value = 1;
		}
	}
}