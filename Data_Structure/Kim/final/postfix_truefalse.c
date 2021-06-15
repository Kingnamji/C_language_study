#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAX_LEN 80

#define MALLOC(p,s)\
	if( !((p) = malloc(s)) ){\
		printf("cannot malloc");\
		exit(1);\
	}

typedef enum {lparen, rparen, or, and, not, eos, operand }precedence;
typedef struct node* nodePointer;
typedef struct node {
	char data;
	int value;
	nodePointer leftChild, rightChild;
}node;
nodePointer root = NULL;

nodePointer stack[MAX_STACK_SIZE];
char expr[MAX_LEN];
int vtable[8][3] = { 0 };
int tcnt;
int top = -1;

precedence getToken(char* symbol, int* n);
nodePointer createBinTree();
nodePointer pop();
nodePointer stackEmpty();
void stackFull();
void push(nodePointer ptr);
void eval(nodePointer ptr);
void maketable();

int main() {
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		printf("cannot open the file");
		exit(1);
	}

	fgets(expr, MAX_LEN, fp);
	printf("input string(postfix)     :   %s\n", expr);
	maketable();
	root = createBinTree();

	printf("find true condition\n");

	for (tcnt = 0; tcnt < 8; tcnt++) {
		eval(root);
		if (root->value) { // true condition 인 경우만
			printf("a=%d, b=%d, c=%d\n", vtable[tcnt][0], vtable[tcnt][1], vtable[tcnt][2]);
		}
	}


	fclose(fp);
	return 0;
}


precedence getToken(char* symbol, int* n) {
	*symbol = expr[(*n)++];
	switch(*symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '|': return or;
	case '&': return and;
	case '~': return not;
	case'\0': return eos;
	default: return operand;
	}
}

nodePointer createBinTree() {
	nodePointer pNode;
	char symbol;
	precedence token;
	int n=0;
	top = -1;
	
	token = getToken(&symbol, &n);
	
	while (token != eos) {
		if (token == operand) {
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->rightChild = NULL;
			pNode->leftChild = NULL;
			push(pNode);
		}
		else {
			if (token == not) {
				MALLOC(pNode, sizeof(*pNode));
				pNode->data = symbol;
				pNode->rightChild = pop();
				pNode->leftChild = NULL;
				push(pNode);
			}
			else {
				MALLOC(pNode, sizeof(*pNode));
				pNode->data = symbol;
				pNode->rightChild = pop();
				pNode->leftChild = pop();
				push(pNode);
			}
		}
		token = getToken(&symbol, &n); // 새로운 토큰 받아와야함
	}
	return pop();
}

nodePointer pop() {
	if (top == -1) {
		return stackEmpty();
	}
	return stack[top--];
}

nodePointer stackEmpty() {
	return NULL;
}

void stackFull() {
	printf(" stack is full ");
	exit(1);
}
void push(nodePointer ptr)
{
	if (top == MAX_STACK_SIZE - 1) {
		stackFull();
	}
	top += 1;
	stack[top] = ptr;
}

void eval(nodePointer ptr) {
	if (ptr) { // Postorder
		eval(ptr->leftChild);
		eval(ptr->rightChild);

		switch(ptr->data) {
		case'&': 
			ptr->value = ptr->leftChild->value && ptr->rightChild->value;
			break;
		case'|':
			ptr->value = ptr->leftChild->value || ptr->rightChild->value;
			break;
		case'~':
			ptr->value = !(ptr->rightChild->value);
			break;
		case'a':
			ptr->value = vtable[tcnt][0];
			break;
		case'b':
			ptr->value = vtable[tcnt][1];
			break;
		case'c':
			ptr->value = vtable[tcnt][2];
			break;
		default:
			ptr->value = 1;
		}
	}
}

void maketable() {
	int row, col = 0;
	for (row = 0; row < 8; row++) {
		vtable[row][col] = (row >> 2) & 1;
		vtable[row][col + 1] = (row >> 1) & 1;
		vtable[row][col + 2] = row & 1;
		col = 0;
	}
}