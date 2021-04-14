#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

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
treePointer queue[MAX_QUEUE_SIZE];

treePointer deleteq();
treePointer queueEmpty();
treePointer getFront();
treePointer createNode(char data);

void addq(treePointer item);
void queueFull();
void insert(treePointer* root, treePointer node);
void inorder(treePointer ptr);
void preorder(treePointer ptr);
void postorder(treePointer ptr);

int rear = -1;
int front = -1;

int main(void) {

	char data;
	treePointer temp;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL){
		exit(1);
	}
	
	printf("creating a complete binary tree\n\n");

	fscanf_s(fp, "%c", &data, sizeof(char));
	temp = createNode(data);

	while (!feof(fp)) {
		insert(&root, temp);
		fscanf_s(fp, "%c", &data, sizeof(char));
		temp = createNode(data);
	}

	printf("three binary tree traversals\n");
	printf("inorder traversal    :");
	inorder(root);
	printf("\n");
	printf("preorder traversal   :");
	preorder(root);
	printf("\n");
	printf("postorder traversal  :");
	postorder(root);
	printf("\n");

	free(temp);

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

treePointer deleteq()
{
	if (front == rear)
		return queueEmpty();

	front += 1;
	return queue[front];
}

treePointer queueEmpty()
{
	printf("Queue is empty.\n");
	return NULL;
}

treePointer getFront()
{
	return queue[front + 1];
}

void insert(treePointer* root, treePointer node)
{
	treePointer front;
	if (!*root)
	{
		*root = node;
	}
	else
	{
		front = getFront();

		if (!front->leftChild) {
			front->leftChild = node;
		}
		else if (!front->rightChild) {
			front->rightChild = node;
		}

		if (front->leftChild && front->rightChild)
			deleteq();
	}

	addq(node);
}

void addq(treePointer item)
{
	if (rear == MAX_QUEUE_SIZE - 1)
		queueFull();
	queue[++rear] = item;
}

void queueFull()
{
	printf("Queue is full.\n");
	exit(1);
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf(" %c",ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		printf(" %c", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf(" %c", ptr->data);
	}
}