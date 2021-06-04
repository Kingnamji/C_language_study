#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct element {
	int key;
}element;
element a[MAX_SIZE];
int link[MAX_SIZE] = { 0 };

void printList(element a[], int link[], int first, int n);
void saveList(element a[], int link[], int first, int n);
int digit(element e, int i, int d, int r);
void radixSort(element a[], int link[], int d, int r, int n);
void printQueues(int front[], int rear[], int r);

int main(void)
{
	int digits;			
	const int r = 10;	
	int n, i;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}

	fscanf_s(fp, "%d%d", &digits, &n);

	for (i = 1; i <= n; i++)
		fscanf_s(fp, "%d", &a[i].key);

	radixSort(a, link, digits, r, n);

	fclose(fp);
	return 0;
}

void printList(element a[], int link[], int first, int n)
{
	int i, current;

	printf("%7s ", "");
	for (i = 1; i <= n; i++) {
		printf(" [%2d]", i);
		if (i == n)
			printf("\n");
	}

	printf("%7s:", "link");
	for (i = 1; i <= n; i++) {
		printf("%5d", link[i]);
		if (i == n)
			printf("\n");
	}

	printf("%7s:", "a");
	for (i = 1; i <= n; i++) {
		printf("%5d", a[i].key);
		if (i == n)
			printf("\n");
	}

	printf("%7s:%5d\n", "first", first);

	current = first;
	printf("%s%7s:", "\n", "result");
	while (current != 0)
	{
		printf("%5d", a[current].key);
		current = link[current];
	}
	printf("\n");

}


int digit(element e, int i, int d, int r)
{
	int m, quotient;

	quotient = e.key;
	for (m = 0; m < d - i - 1; m++)
		quotient = quotient / r;

	return  quotient % r;
}

void radixSort(element a[], int link[], int digits, int r, int n)
{ 
	int* front, * rear;	
	int i, bin, current, first, last;

	front = (int*)malloc(sizeof(int) * r);
	rear = (int*)malloc(sizeof(int) * r);

	first = 1;
	for (i = 1; i < n; i++)
		link[i] = i + 1;
	link[n] = 0;

	printf("************************* initial chain *************************\n");
	printList(a, link, first, n);

	for (i = digits - 1; i >= 0; i--)
	{ 
		for (bin = 0; bin < r; bin++)
		{
			front[bin] = rear[bin] = 0;
		}

		for (current = first; current; current = link[current])
		{
			bin = digit(a[current], i, digits, r);
			if (front[bin] == 0)
				front[bin] = current;
			else
				link[rear[bin]] = current;
			rear[bin] = current;
		}

		for (bin = 0; !front[bin]; bin++);
		first = front[bin];
		last = rear[bin];

		for (bin++; bin < r; bin++)
		{
			if (front[bin])
			{
				link[last] = front[bin];
				last = rear[bin];
			}
		}
		link[last] = 0;

		printf("\n**************************** pass %d *****************************\n", digits - i);
		printList(a, link, first, n);
		printQueues(front, rear, r);
	}

	free(front);
	free(rear);

	return;
}

void printQueues(int front[], int rear[], int r)
{
	int i;

	printf("%s%7s ", "\n", "");

	for (i = 0; i < r; i++) {
		printf(" [%2d]", i);
		if (i == r - 1)
			printf("\n");
	}

	printf("%7s:", "rear");
	for (i = 0; i < r; i++) {
		printf("%5d", rear[i]);
		if (i == r - 1)
			printf("\n");
	}

	printf("%7s:", "front");
	for (i = 0; i < r; i++) {
		printf("%5d", front[i]);
		if (i == r - 1)
			printf("\n");
	}

}
