#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !((p) = malloc(s)) ){\
		exit(1);\
	}

typedef struct node* treePointer;
typedef struct node {
	char data;
	treePointer leftChild, rightChild;
}node;
treePointer root = NULL;

void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);
treePointer createNode(char data);

int main(void) {
	
	treePointer nodeA, nodeB, nodeC, nodeD, nodeE;

	printf("creating a binary tree\n\n");

	nodeA = createNode('A');
	nodeB = createNode('B');
	nodeC = createNode('C');
	nodeD = createNode('D');
	nodeE = createNode('E');
	
	nodeA->leftChild = nodeB;
	nodeA->rightChild = nodeC;
	nodeB->leftChild = nodeD;
	nodeB->rightChild = nodeE;

	root = nodeA;

	printf("three binary tree traversals\n");
	printf("inorder traversal    :\n");
	inorder(root);
	printf("\n");
	printf("preorder traversal    :\n");
	preorder(root);
	printf("\n");
	printf("postorder traversal    :\n");
	postorder(root);
	printf("\n");
	
	free(nodeA);
	free(nodeB);
	free(nodeC);
	free(nodeD);
	free(nodeE);

	return 0;
}

treePointer createNode(char data)
{
	treePointer ptr;

	MALLOC(ptr, sizeof(*ptr));
	ptr->data = data;
	ptr->leftChild = NULL;
	ptr->rightChild = NULL;

	return ptr;
}

void inorder(treePointer ptr) {
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf("(%p : %p %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("(%p : %p  %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		printf("(%p : %p  %c %p)\n", ptr, ptr->leftChild, ptr->data, ptr->rightChild);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}