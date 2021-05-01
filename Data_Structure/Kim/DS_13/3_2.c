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
typedef struct node *treePointer;
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
precedence getToken(char *symbol, int *n);
treePointer createBinTree(void);

// binary tree traversals
void iterpostorder(treePointer ptr); // using a user-defined stack
void iterInorder(treePointer ptr); // using a user-defined stack
void iterpreorder(treePointer node);
void levelOrder(treePointer ptr); // using a circualr queue

int main(void)
{
	FILE *fp;

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

	printf("%-30s : ", "iterative preorder traversal");
	iterpreorder(root); 	printf("\n");

	printf("%-30s : ", "iterative postorder traversal");
	iterpostorder(root); 	printf("\n");

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
			// operator node
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;			// operator
			pNode->rightChild = pop();	// link operand
			pNode->leftChild = pop();		// link operand

			push(pNode);
		}
		token = getToken(&symbol, &n);
	}
	return pop();

precedence getToken(char *symbol, int *n)
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

/
void iterInorder(treePointer node)
{
	int push_cnt = 0;
	top = -1; // global stack

	for (;;)
	{
		for (; node; node = node->leftChild) {
			++push_cnt;
			push(node);		/* add to stack */
		}
		node = pop();		/* delete from stack */
		if (!node) break;	/* empty stack */
		printf("%c", node->data);
		node = node->rightChild;
	}
	printf("\n push_cnt = %d\n", push_cnt);
}

void iterpreorder(treePointer node)
{
	int push_cnt = 0;
	top = -1; // global stack

	for (;;)
	{
		for (; node; node = node->leftChild) {
			printf("%c", node->data);
			++push_cnt;
			push(node);		/* add to stack */
		}
		node = pop();		/* delete from stack */
		if (!node) break;	/* empty stack */		
		node = node->rightChild;
	}
	printf("\n push_cnt = %d\n", push_cnt);
}

void iterpostorder(treePointer node)
{
	int push_cnt = 0;
	top = -1; // global stack
	treePointer node2;
	int i;
	

	for (;;)
	{
		for (; node; ) {
			++push_cnt;
			node2 = node->leftChild;
			node->leftChild = NULL;
			push(node);    /* add to stack */
			node = node2;

		}
		node = pop();		/* delete from stack */

		if (!node) break;	/* empty stack */
		if (node->rightChild) {
			++push_cnt;
			node2 = node->rightChild;
			node->rightChild = NULL;
			push(node);
			node = node2;

		}
		else {
			printf("%c", node->data);
			node = pop();
		}

	}
	printf("\n push_cnt = %d\n", push_cnt);
}



void levelOrder(treePointer ptr)
{ 
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
{/* add an item to the global stack */
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
	treePointer item;
	item = NULL;  
	return item;
}


void addq(treePointer item)
{ 
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queueFull(); /* print error and exit */
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
		return queueEmpty(); /* return an error key */
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

treePointer queueEmpty()
{
	treePointer item;
	item = NULL;  // error key value - null pointer
	return item;
}
