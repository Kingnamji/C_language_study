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

	fopen_s(&fp, "input.txt", "r"); // ������ ����
	if (fp == NULL) {
		exit(1);
	}

	printf("creating a complete binary tree\n\n"); // Ʈ���� �������

	fscanf_s(fp, "%c", &data, sizeof(char)); // �Է� ������ �����Ͱ� letter�̹Ƿ� char��
	temp = createNode(data); // �Է¹��� �����ͷ� Node�� ����

	while (!feof(fp)) { // ������ ����������
		insert(&root, temp); // Ʈ���� ����
		fscanf_s(fp, "%c", &data, sizeof(char));
		temp = createNode(data); // ���� ���� �����ͷ� ��带 �����
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

treePointer createNode(char data) // Node�� �����.
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
	if (front == rear)  // ť�� �����.
		return queueEmpty();

	front += 1;
	return queue[front];
}

treePointer queueEmpty()
{
	printf("Queue is empty.\n");
	return NULL; // ť�� ������� �ƹ��͵� ��ȯ ���ϵ���
}

treePointer getFront() // ���� front ���� ��ĭ ��
{
	return queue[front + 1];
}

void insert(treePointer* root, treePointer node)
{
	treePointer front;
	if (!*root) // empty Binary tree���
	{
		*root = node; // root�� node�� ����
	}
	else // binary tree �� ������� ������
	{
		front = getFront();

		if (!front->leftChild) { // ���ʺ��� ����
			front->leftChild = node;
		}
		else if (!front->rightChild) { // ���� �ڽ��� ������ ������ Ȯ��
			front->rightChild = node;
		}

		if (front->leftChild && front->rightChild) // ���� ������ �ڽ��� ��� �ִ�
			deleteq(); // ť���� ������.
	}

	addq(node); // ť�� ��� ����
}

void addq(treePointer item)
{
	if (rear == MAX_QUEUE_SIZE - 1) // ���� �� ���
		queueFull();
	queue[++rear] = item; // ������ ��� rear ���� 1 �ø���, item �� �߰� ( ���⼭�� ��� )
}

void queueFull()
{
	printf("Queue is full.\n"); 
	exit(1);
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		printf(" %c", ptr->data);
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