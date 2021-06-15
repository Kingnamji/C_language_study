#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX_STACK_SIZE 100
#define MAX_QUEUE_SIZE 100

// tree node & pointer
typedef struct node* treePointer;
typedef struct node
{
	char data;		// operator or operand in char type
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

// stack
treePointer stack[MAX_STACK_SIZE];
int top = -1;
void push(treePointer item);
void stackFull();
treePointer pop();
treePointer stackEmpty();

// circualr queue
treePointer queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;
void addq(treePointer item);
void queueFull();
treePointer deleteq();
treePointer queueEmpty();

// postfix expression 
char expr[81];

// binary tree of an arithmetic expression
typedef enum {
	lparen, rparen, plus, minus, times, divide,
	mod, eos, operand
} precedence;
precedence getToken(char* symbol, int* n);
treePointer createBinTree(void);

// binary tree traversals
void iterInorder(treePointer ptr); // using a user-defined stack
void levelOrder(treePointer ptr); // using a circualr queue

int main(void)
{
	int result;
	FILE* fp;

	if (fopen_s(&fp, "input.txt", "r"))
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	printf("the length of input string should be less than 80\n");
	fgets(expr, 80, fp);
	printf("input string (postfix expression) : %s\n", expr);

	printf("creating its binary tree\n\n");
	root = createBinTree();

	printf("%-30s : ", "iterative inorder traversal");
	iterInorder(root); 	printf("\n");

	printf("%-30s : ", "level order traversal");
	levelOrder(root); 	printf("\n\n");

	return 0;
}

// create a binary tree from a postfix arithmetic expression
treePointer createBinTree(void)
{
	treePointer pNode;
	precedence token;
	char symbol;
	int n = 0; /* counter for the expression string */
	top = -1;
	token = getToken(&symbol, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			// operand node
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;

			push(pNode); /* stack insert */
		}
		else {
			// operator node
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;			// operator
			pNode->rightChild = pop();	// link operand
			pNode->leftChild = pop();		// link operand

			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop(); /* return result, that is, root pointer */
}

precedence getToken(char* symbol, int* n)
{ 
	*symbol = expr[(*n)++];
	switch (*symbol)
	{
	case '(': return lparen;
	case ')':  return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand; 
	}
}

void iterInorder(treePointer node)
{	
	int push_cnt = 0;
	top = -1;
	for (;;)
	{
		for (; node; node = node->leftChild) {
			++push_cnt;
			push(node);
		}
		node = pop();	
		if (!node) break;
		printf("%c", node->data);
		node = node->rightChild;
	}
}

// Level-order traversal of a binary tree
void levelOrder(treePointer ptr)
{ /* level order tree traversal */

	// 아래 두 줄은 잘못 된 것. 교재 코드 수정
	//int front = 0, rear = 0;		/* circular queue */
	//treePointer queue[MAX_QUEUE_SIZE];	

	front = rear = 0;	/* global circular queue */

	if (!ptr) return; /* empty tree */

	addq(ptr);

	for (;; )
	{
		ptr = deleteq();
		if (ptr)
		{
			printf("%c", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else	/* empty queue */
		{
			break;
		}
	}
}

void push(treePointer item)
{
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}

treePointer pop()
{
	if (top == -1)
		return stackEmpty();	
	return stack[top--];
}

treePointer stackEmpty()
{
	return NULL;
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
	fprintf(stderr, "queue is full, cannot add item\n");
	exit(EXIT_FAILURE);
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