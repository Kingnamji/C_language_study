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

	fopen_s(&fp, "input.txt", "r"); // 파일을 열고
	if (fp == NULL) {
		exit(1);
	}

	printf("creating a complete binary tree\n\n"); // 트리를 만들거임

	fscanf_s(fp, "%c", &data, sizeof(char)); // 입력 파일의 데이터가 letter이므로 char형
	temp = createNode(data); // 입력받은 데이터로 Node를 만듬

	while (!feof(fp)) { // 파일이 끝날때까지
		insert(&root, temp); // 트리에 삽입
		fscanf_s(fp, "%c", &data, sizeof(char));
		temp = createNode(data); // 새로 받은 데이터로 노드를 만들고
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

treePointer createNode(char data) // Node를 만든다.
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
	if (front == rear)  // 큐가 비었다.
		return queueEmpty();

	front += 1;
	return queue[front];
}

treePointer queueEmpty()
{
	printf("Queue is empty.\n");
	return NULL; // 큐가 비었으니 아무것도 반환 못하도록
}

treePointer getFront() // 현재 front 보다 한칸 앞
{
	return queue[front + 1];
}

void insert(treePointer* root, treePointer node)
{
	treePointer front;
	if (!*root) // empty Binary tree라면
	{
		*root = node; // root가 node를 가짐
	}
	else // binary tree 가 비어있지 않으면
	{
		front = getFront();

		if (!front->leftChild) { // 왼쪽부터 지정
			front->leftChild = node;
		}
		else if (!front->rightChild) { // 왼쪽 자식이 있으면 오른쪽 확인
			front->rightChild = node;
		}

		if (front->leftChild && front->rightChild) // 왼쪽 오른쪽 자식이 모두 있다
			deleteq(); // 큐에서 빼낸다.
	}

	addq(node); // 큐에 노드 삽입
}

void addq(treePointer item)
{
	if (rear == MAX_QUEUE_SIZE - 1) // 가득 찬 경우
		queueFull();
	queue[++rear] = item; // 나머지 경우 rear 값을 1 올리고, item 을 추가 ( 여기서는 노드 )
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