#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct {
	int key;
}element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int* n);
element pop(int* n);

int main(void)
{
	FILE* fp;
	element item;

	fopen_s(&fp, "input1.txt", "r");

	if (fp == NULL) {
		exit(1);
	}
	printf("***** insertion into a max heap *****\n");

	fscanf_s(fp, "%d", &item.key);
	while (!feof(fp))
	{
		push(item, &n);
		
		for (int i = 1; i <= n; i++) {
			printf(" %d ", heap[i].key);
		}	
		printf("\n");

		fscanf_s(fp, "%d", &item.key);
	}
	push(item, &n);
	for (int i = 1; i <= n; i++) {
		printf(" %d ", heap[i].key);
	}
	printf("\n");

	printf("***** deletion from a max heap *****");
	while (n > 0) {
		item = pop(&n);
		printf("\n");
		printf("delete data = %d\n", item.key);
		for (int i = 1; i <= n; i++) {
			printf(" %d ", heap[i].key);
		}
		
	}	

	fclose(fp);

	return 0;
}

void push(element item, int* n) {
	int i;

	if (HEAP_FULL(*n)) {
		printf("The Heap is full.\n");
		exit(1);
	}

	i = ++(*n);

	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n) {
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		printf("The Heap is Empty\n");
		exit(1);
	}

	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent] = temp;
	return item;
}

