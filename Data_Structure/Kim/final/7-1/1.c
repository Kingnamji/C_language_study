#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
	int key;
	char name[20];
	int grade;
}element;

void insert(element e, element a[], int i);
void insertionSort(element a[], int n);
void printList(element a[], int n);

int main(void)
{
	int num;
	int i;
	element* pStd;
	FILE* fp;
	
	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open the File");
		exit(1);
	}

	fscanf_s(fp, "%d", &num);
	pStd = (element*)malloc((num + 1) * sizeof(element));

	for (i = 1; i <= num; i++) {
		fscanf_s(fp, "%d%s%d", &pStd[i].key, pStd[i].name, sizeof(pStd[i].name), &pStd[i].grade);
	}

	printf("<<<<<<<<<<<<<< Input List >>>>>>>>>>>>>\n");
	printList(pStd, num);

	printf("\n<<<<<<<<<<<<< Sorted List >>>>>>>>>>\n");
	insertionSort(pStd, num);
	printList(pStd, num);

	fclose(fp);

	return 0;
}


void insert(element e, element a[], int i)
{ 
	a[0] = e;
	while (e.key < a[i].key)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}

void insertionSort(element a[], int n)
{ 
	int j;
	for (j = 2; j <= n; j++)
	{
		element temp = a[j];
		insert(temp, a, j - 1); 
	}
}

void printList(element a[], int n)
{
	int i;
	for (i = 1; i <= n; i++)
		printf("( %d, %s, %d )\n", a[i].key, a[i].name, a[i].grade);
}