#include <stdio.h>
#include <stdlib.h>

#define SIZE 12
#define SWAP(x, y, temp) ((temp) = (x), (x) = (y), (y)=(temp))


typedef struct element
{
	int key;
}element;

void printList(element a[], int n);
void quickSort(element a[], int left, int right);

int cnt = 0;
int num;

int main(void)
{
	int i;
	FILE* fp;
	element ary[SIZE];

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open the File");
		exit(1);
	}

	fscanf_s(fp, "%d", &num);

	for (i = 1; i <= num; i++)
		fscanf_s(fp, "%d", &ary[i].key);

	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	printList(ary, num);

	printf("\n\nexecution of quick sort ... \n");
	quickSort(ary, 1, num);

	printf("\ncalls of quick sort: %d \n", cnt);
	printf("\n<<<<<<<<<<<<<< Sorted List >>>>>>>>>>\n");

	printList(ary, num);
	printf("\n");

	fclose(fp);

	return 0;
}

void printList(element a[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("%2d ", a[i].key);
}


void quickSort(element a[], int left, int right)
{ 
	int pivot, i, j;
	element temp;

	cnt++; // counting calls of quit sort
	printf("pivot = %d : ", a[left].key);

	if (left < right)
	{
		i = left; j = right + 1;
		pivot = a[left].key;

		do { 
			do i++; while (a[i].key < pivot);
			do j--; while (a[j].key > pivot);
			if (i < j) SWAP(a[i], a[j], temp);
		} while (i < j);

		SWAP(a[left], a[j], temp);

		printList(a, num);
		printf("\n");

		if (left < j - 1)
			quickSort(a, left, j - 1);
		if (j + 1 < right)
			quickSort(a, j + 1, right);
	}
}

