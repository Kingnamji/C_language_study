#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))

typedef struct element
{
	int key;
}element;

element a[MAX_SIZE]; 

int adjust(element a[], int root, int n);
void printList(element a[], int num);
void heapSort(element a[], int n);

int main(void)
{
	int num;
	int i;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}

	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	fscanf_s(fp, "%d", &num);

	for (i = 1; i <= num; i++) {
		fscanf_s(fp, "%d", &a[i].key);
		printf("%d ", a[i].key);
	}
	printf("\n");

	printf("\n<<<<<<< executing heap sort >>>>>>>>>>\n");
	heapSort(a, num);

	printf("\n<<<<<<<<<<<<< Sorted List >>>>>>>>>>>\n");

	for (i = 1; i <= num; i++) {
		printf("%d ", a[i].key);
	}
	printf("\n");

	fclose(fp);

	return 0;
}

int adjust(element a[], int root, int n)
{

	int child, rootkey;
	element temp;

	temp = a[root];
	rootkey = a[root].key;
	child = 2 * root;

	while (child <= n)
	{
		if ((child < n) && (a[child].key < a[child + 1].key))
			child++;

		if (rootkey > a[child].key)
			break;

		else
		{
			a[child / 2] = a[child];
			child *= 2;
		}
	}
	a[child / 2] = temp;
}

void printList(element a[], int num)
{
	int i;
	for (i = 1; i <= num; i++)
		printf("%d ", a[i].key);
	printf("\n");
}

void heapSort(element a[], int n)
{
	int i, j;
	element temp;

	for (i = n / 2; i > 0; i--)
		adjust(a, i, n);

	printf("after initialization of max heap...\n");
	printList(a, n);
	printf("\n");

	for (i = n - 1; i > 0; i--)
	{
		SWAP(a[1], a[i + 1], temp);
		adjust(a, 1, i);

		printf("\nstep  %d: ", n-i);
		printf("Ãâ·Â %d : ", a[i+1].key);

		for (j = 1; j <= i; j++)
			printf("%4d", a[j].key);

	}
}
