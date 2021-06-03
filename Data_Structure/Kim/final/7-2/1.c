#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element
{
	int key;
}element;

element a[MAX_SIZE];

void merge(element initList[], element mergedList[], int i, int m, int n);
void mergePass(element initList[], element mergedList[], int n, int s);
void printList(element a[], int num);
void mergeSort(element a[], int n);

int main(void)
{
	int i, num;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf(" Cannot Open The File");
		exit(1);
	}

	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	fscanf_s(fp, "%d", &num);

	for (i = 1; i <= num; i++)
		fscanf_s(fp, "%d", &a[i].key);
	printList(a, num);

	printf("\n<<<<< executing itterative merge sort >>>>>\n");
	mergeSort(a, num);

	printf("<<<<<<<<<<<<< Sorted List >>>>>>>>>>>\n");
	printList(a, num);
	printf("\n");

	fclose(fp);

	return 0;
}

void merge(element initList[], element mergedList[], int i, int m, int n)
{

	int j, k, t;
	j = m + 1;
	k = i;

	while (i <= m && j <= n)
	{
		if (initList[i].key <= initList[j].key)
			mergedList[k++] = initList[i++];
		else
			mergedList[k++] = initList[j++];
	}

	if (i > m)
	{
		for (t = j; t <= n; t++)
			mergedList[t] = initList[t];
	}
	else
	{
		for (t = i; t <= m; t++)
			mergedList[k + t - i] = initList[t];
	}
}

void mergePass(element initList[], element mergedList[], int n, int s)
{
	int i, j;

	for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
		merge(initList, mergedList, i, i + s - 1, i + 2 * s - 1);

	if (i + s - 1 < n)
		merge(initList, mergedList, i, i + s - 1, n);
	else
		for (j = i; j <= n; j++)
			mergedList[j] = initList[j];
}

void printList(element a[], int num)
{
	int i;
	for (i = 1; i <= num; i++)
		printf("%3d ", a[i].key);
	printf("\n");
}

void mergeSort(element a[], int n)
{
	int s = 1;
	int i;
	element extra[MAX_SIZE];

	while (s < n)
	{
		mergePass(a, extra, n, s);

		printf("segment size : %d\n", s);
		printf("           a : ");
		printList(a, n);
		printf("        temp : ");
		printList(extra, n);
		printf("\n");


		s *= 2;

		mergePass(extra, a, n, s);

		printf("segment size : %d\n", s);
		printf("        temp : ");
		printList(extra, n);
		printf("           a : ");
		printList(a, n);
		printf("\n");

		s *= 2;

	}
}