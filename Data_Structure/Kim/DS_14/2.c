#include <stdio.h>
#include <stdlib.h>

typedef struct threadedTree* threadedPointer;
typedef struct threadedTree {
	int leftThread; 
	threadedPointer leftChild;
	char data; 
	threadedPointer rightChild;
	int rightThread; 
} threadedTree;


threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);


main()
{
	threadedPointer root=NULL;
	int cnt = 0;

	threadedTree n1 = { 0, NULL, 'A', NULL, 0 };
	threadedTree n2 = { 0, NULL, 'B', NULL, 0 };
	threadedTree n3 = { 0, NULL, 'C', NULL, 0 };
	threadedTree n4 = { 0, NULL, 'D' , NULL, 0 };
	threadedTree n5 = { 1, NULL, 'E', NULL, 1 };
	threadedTree n6 = { 1, NULL, 'F', NULL, 1 };
	threadedTree n7 = { 1, NULL, 'G', NULL, 1 };
	threadedTree n8 = { 1, NULL, 'H', NULL, 1 };
	threadedTree n9 = { 1, NULL, 'I', NULL, 1 };
	threadedTree head = { 0, &n1, ' ', &head, 0 };

	n1.leftChild = &n2;
	n1.rightChild = &n3;

	n2.leftChild = &n4;
	n2.rightChild = &n5;

	n3.leftChild = &n6;
	n3.rightChild = &n7;

	n4.leftChild = &n8;
	n4.rightChild = &n9;

	n5.leftChild = &n2;
	n5.rightChild = &n1;

	n6.leftChild = &n1;
	n6.rightChild = &n3;

	n7.leftChild = &n3;
	n7.rightChild = &head;

	n8.leftChild = &head;
	n8.rightChild = &n4;

	n9.leftChild = &n4;
	n9.rightChild = &n2;

	printf("%p(%d, %p, %c, %d, %p)\n", &head, head.leftThread, head.leftChild, head.data, head.rightThread, head.rightChild);
	root = &head;
	tinorder(root);

	return 0;
}

threadedPointer insucc(threadedPointer tree) {
	threadedPointer temp;
	temp = tree->rightChild;
	if (!tree->rightThread)
		while (!temp->leftThread) 
			temp = temp->leftChild;
	return temp;
}

void tinorder(threadedPointer tree) {
	threadedPointer temp = tree;
	for (;;) {
		temp = insucc(temp);
		if (temp == tree)
			break;
		printf("%p(%d, %p, %c, %d, %p)\n", temp, temp->leftThread, temp->leftChild, temp->data, temp->rightThread, temp->rightChild);
	}
}