#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node *treePointer;
typedef struct node
{
	char data;		
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

treePointer queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;
void addq(treePointer item);
void queueFull();
treePointer deleteq();
treePointer queueEmpty();
treePointer getFront(); 

treePointer createNode( char data );
treePointer createCompBinTree(FILE *fp);
int hasBothChild(treePointer pNode);
void insert( treePointer *pRoot, treePointer pNode );

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

void main(void)
{
	char data;
	FILE *fp ;
	
	if(fopen_s(&fp,"input.txt", "r") )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	printf("creating a complete binary tree\n\n");
	root = createCompBinTree(fp);

	printf("three binary tree traversals\n");
	printf("%-20s : ", "inorder traversal");
	inorder(root); 	printf("\n");

	printf("%-20s : ","preorder traversal");
	preorder(root);	printf("\n");

	printf("%-20s : ","postorder traversal");
	postorder(root);	printf("\n\n");

	fclose(fp);
}


void addq(treePointer item)
{
	if ( rear == MAX_QUEUE_SIZE-1 )
		queueFull();
	queue[++rear] = item;
}

void queueFull()
{		
	fprintf(stderr, "queue is full, cannot add element\n");
	exit(1);
}

treePointer deleteq()
{
	if ( front == rear )
		return queueEmpty();
	return queue[++front];
}

treePointer queueEmpty()
{
		fprintf(stderr, "queue is empty, cannot delete element\n");
		return NULL;
}

treePointer getFront()
{
	return queue[front+1];
}

treePointer createNode( char data )
{
	treePointer pNode;

	MALLOC(pNode, sizeof(*pNode));
	pNode->data = data;
	pNode->leftChild = NULL;
	pNode->rightChild = NULL;
	
	return pNode;
}


treePointer createCompBinTree( FILE * fp)
{
	treePointer pNode;
	char data;

	fscanf_s(fp,"%c", &data, sizeof(char));
	pNode = createNode(data);
		
	while(!feof(fp))
	{
		insert( &root, pNode);
		fscanf_s(fp, "%c", &data, sizeof(char));
		pNode = createNode(data);
	}
	free(pNode); 

	return root;
}

int hasBothChild(treePointer pNode)
{
	return pNode->leftChild && pNode->rightChild;
}

void insert( treePointer *pRoot, treePointer pNode )
{
	if( !*pRoot )
	{
		*pRoot = pNode;
	}
	else
	{
		treePointer pfront = getFront();

		if( !pfront->leftChild )
			pfront->leftChild = pNode;
		else if( !pfront->rightChild )
			pfront->rightChild = pNode;

		if( hasBothChild( pfront ) )
			deleteq();
	}

	addq(pNode);
}

void inorder(treePointer ptr)
{ 
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("%c", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{ 
	if(ptr)
	{
		printf("%c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{ 
	if(ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}
