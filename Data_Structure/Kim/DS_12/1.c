#include <stdio.h>
#include <stdlib.h>

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

treePointer createNode( char data );
treePointer createBinTree();
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int main(void)
{
	printf("creating a binary tree\n\n");
	root = createBinTree();

	printf("three binary tree traversals\n");
	printf("%-20s : \n", "inorder traversal");
	inorder(root); 	printf("\n");

	printf("%-20s : \n","preorder traversal");
	preorder(root);	printf("\n");

	printf("%-20s : \n","postorder traversal");
	postorder(root);	printf("\n\n");

	return 0;
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


treePointer createBinTree()
{
	treePointer pNodeA, pNodeB, pNodeC, pNodeD, pNodeE;

	pNodeA = createNode('A');
	pNodeB = createNode('B');
	pNodeC = createNode('C');
	pNodeD = createNode('D');
	pNodeE = createNode('E');

	pNodeA->leftChild = pNodeB;
	pNodeA->rightChild = pNodeC;
	pNodeB->leftChild = pNodeD;
	pNodeB->rightChild = pNodeE;	

	return pNodeA;
}

void inorder(treePointer ptr)
{ 
	if(ptr)
	{
		inorder(ptr->leftChild);
		printf("(%p : %p  %c  %p) \n",ptr,  ptr->leftChild, ptr->data, ptr->rightChild);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr)
{ 
	if(ptr)
	{
		printf("(%p : %p  %c  %p) \n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
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
		printf("(%p : %p  %c  %p) \n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
	}
}
