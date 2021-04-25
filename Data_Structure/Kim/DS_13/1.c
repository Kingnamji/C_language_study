#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}
#define MAX_STACK_SIZE 100

// tree node & header
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

// postfix expression 
char expr[81];
int cnt;

// binary tree of an arithmetic expression
typedef enum { lparen, rparen, plus, minus, times, divide, 
							mod, eos, operand } precedence;
precedence getToken(char *symbol, int *n);
treePointer createBinTree(void);

// binary tree traversals
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void)
{
	FILE *fp;	

	if(fopen_s(&fp, "input.txt", "r") )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	printf("the length of input string should be less than 80\n");
	fgets(expr, 80, fp);
	printf("input string (postfix expression) : %s\n", expr);

	printf("creating its binary tree\n\n");
	root = createBinTree();

	printf("%-20s : ", "inorder traversal");
	cnt = 0;
	inorder(root); 	printf("\n");

	printf("%-20s : ","preorder traversal");
	cnt = 0;
	preorder(root);	printf("\n");

	printf("%-20s : ","postorder traversal");
	cnt = 0;
	postorder(root);	printf("\n");

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
	while( token != eos )
	{
		if( token == operand )
		{
			// operand node
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;
			pNode->leftChild = NULL;
			pNode->rightChild = NULL;
			
			push(pNode); /* stack insert */
		}
		else{ 
			// operator node
			MALLOC(pNode, sizeof(*pNode));
			pNode->data = symbol;			// operator
			pNode->rightChild =  pop();	// link operand
			pNode->leftChild = pop();		// link operand

			push(pNode);
		}
		token = getToken( &symbol, &n);
	}
	return pop(); /* return result, that is, root pointer */
}

// Program 3.14: Function to get a token from the input string
precedence getToken(char *symbol, int *n)
{ /* get the next token, symbol is the character representation, 
	whichis returned, the tokenis represented by its enumerated value, 
	which is returned inthe function name */
	*symbol = expr[ (*n)++ ];
	switch ( *symbol) 
	{
			//case '('		: return lparen;
			//case ')'		:  return rparen;
			case '+'		: return plus;
			case '-'		: return minus;
			case '/'		: return divide;
			case '*'		: return times;
			case '%'	: return mod;
			case '\0'	: return eos;
			default		: return operand; /* no error checking, default is operand */
	}
}

///////////////////// binary tree traversals //////////////////////////////
void inorder(treePointer ptr)
{ 
	cnt++;
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{ 
	cnt++;
	if(ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{ 
	cnt++;
	if(ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

treePointer pop()
{/* delete and return the top int from the stack */
	if ( top == -1 )
		return stackEmpty();	/* returns an error key */
	return stack[top--];
}

treePointer stackEmpty()
{
	treePointer item;
	item = NULL;  // error key value - null pointer
	return item;
}

void push(treePointer item)
{/* add an item to the global stack */
	if ( top >= MAX_STACK_SIZE-1 )
		stackFull();
	stack[++top] = item;
}

void stackFull()
{
	fprintf(stderr, "stack is full, cannot add item\n");
	exit(EXIT_FAILURE);
}
