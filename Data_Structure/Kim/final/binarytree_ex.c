#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define MALLOC(p,s)\
	if( !((p) = malloc(s) ) ){\
		printf("cannot malloc");\
		exit(1);\
	}

typedef struct node* treePointer;
typedef struct node {
	char name[50];
	char gender;
	int age;
	treePointer leftChild, rightChild;
}node;

treePointer root = NULL;
treePointer queue[MAX_QUEUE_SIZE];

int rear = -1, front = -1;

treePointer createNode(char fname[], char fgender, int fage);
treePointer qempty();
treePointer deleteq();
treePointer getFront();
treePointer insert(treePointer* root, treePointer node);
void addq(treePointer item);

void inorder(treePointer ptr);
void postorder(treePointer ptr);

int main()
{
	FILE* fp;
	treePointer temp;
	char fname[50];
	char fgender;
	int fage;

	fopen_s(&fp, "input1.txt", "r");
	if (fp == NULL) {
		printf("cannot open the file");
		exit(1);
	}

	printf("input data :\n");
	fscanf_s(fp, "%s %c %d", fname, 50, &fgender, sizeof(char), &fage);
	printf(" %s,    %c,   %d\n", fname, fgender, fage);
	temp = createNode(fname, fgender, fage);

	while (!feof(fp)) {
		insert(&root, temp);
		fscanf_s(fp, "%s %c %d", fname, 50, &fgender, sizeof(char), &fage);
		printf(" %s,    %c,   %d\n", fname, fgender, fage);
		temp = createNode(fname, fgender, fage);
	}
	insert(&root, temp);

	printf("\ninorder traversal : 사람의 이름을 출력\n");
	inorder(root);

	printf("\n\npostorder traversal : 사람의 나이를 출력\n\n");
	postorder(root);


	fclose(fp);
	return 0;
}
treePointer createNode(char fname[], char fgender, int fage) {
	treePointer ptr;
	MALLOC(ptr, sizeof(*ptr));
	strcpy_s(ptr->name, 50, fname);
	ptr->gender = fgender;
	ptr->age = fage;
	ptr->leftChild = NULL;
	ptr->rightChild = NULL;

	return ptr;
}

treePointer qempty() {
	return NULL;
}
treePointer deleteq() {
	if (rear == front) {
		return qempty();
	}
	front += 1;
	return queue[front];
}
treePointer getFront() {
	return queue[front + 1];
}
treePointer insert(treePointer* root, treePointer node) {
	treePointer front;

	if (!*root) {
		*root = node;
	}
	else {
		front = getFront();
		if (!front->leftChild) {
			front->leftChild = node;
		}
		else if (!front->rightChild) {
			front->rightChild = node;
		}
		if (front->leftChild && front->rightChild) {
			deleteq();
		}
	}
	addq(node);
}

void addq(treePointer item) {
	if (rear == MAX_QUEUE_SIZE - 1) {
		printf("queue is FULL");
		exit(1);
	}

	queue[++rear] = item;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf("%s -> ", ptr->name);
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr)
{
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d -> ", ptr->age);
	}
}