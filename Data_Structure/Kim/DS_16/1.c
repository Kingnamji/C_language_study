#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500

#define MALLOC(p,s)\
	if ( !( (p) = malloc(s) ) ) {\
		exit(1);\
	}

typedef int iType;
typedef struct {
	int key;
	iType item;
}element;

typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftChild, rightChild;
}tNode;
treePointer tree;

void inorder(treePointer ptr);
void insert(treePointer* node, int k, iType theItem);
element* iterSearch(treePointer tree, int k);
treePointer modifiedSearch(treePointer node, int k);

int nums[MAX_SIZE+1] = { 0 };

int main(void) {

	int n, i, key, seed;
	element* p;

	printf("random number generation (1 ~ %d)\n", MAX_SIZE);
	printf("the number of nodes in BST (less than and equal to 50) : ");
	scanf_s("%d", &n);
	printf("seed : ");
	scanf_s("%d", &seed);
	printf("\ncreating a BST from random numbers \n");
	srand(seed);

	printf("generating number : ");
	i = 0;
	while (i < n)
	{
		key = (rand() % MAX_SIZE) + 1; // key 값의 범위 1~500

		if ( !nums[key] )
		{
			nums[key]++;
			printf(" %3d", key);
			insert(&tree, key, (iType)key);
			i++;
		}
	}
	printf("\n");
	
	printf("the key to search : ");
	scanf_s("%d", &n);
	printf("the search process : ");
	p = iterSearch(tree, n);
	printf("\n");

	if (p)
		printf("the element is in BST\n");
	else
		printf("the element isn't in BST\n");

	printf("\ninorder traversal of the BST shows the sorted sequence\n");
	inorder(tree);
	

	return 0;
}

void inorder(treePointer ptr)
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		printf(" %3d", ptr->data.key);
		inorder(ptr->rightChild);
	}
}


element* iterSearch(treePointer tree, int k)
{
	while (tree)
	{
		printf("%d => ", tree->data);

		if (k == tree->data.key)
			return &(tree->data);

		if (k < tree->data.key)
			tree = tree->leftChild;
		else
			tree = tree->rightChild;
	}
	return NULL;
}

treePointer modifiedSearch(treePointer node, int k)
{
	treePointer temp;
	temp = NULL;
	
	if (!node) 
		return NULL;		

	while (node)
	{
		temp = node;

		if (k == node->data.key) 
			return NULL; 

		if (k < node->data.key)
			node = node->leftChild;
		else
			node = node->rightChild;
	}
	return temp;
}

void insert(treePointer* node, int k, iType theItem)
{ 
	treePointer ptr;
	treePointer temp = modifiedSearch(*node, k);

	if (temp || !(*node))
	{
		
		MALLOC(ptr, sizeof(*ptr));
		ptr->data.key = k;
		ptr->data.item = theItem;
		ptr->leftChild = ptr->rightChild = NULL;

		if (*node) 
		{
			if (k < temp->data.key)
				temp->leftChild = ptr;
			else
				temp->rightChild = ptr;
		}
		else 
		{
			*node = ptr;
		}
	}
}