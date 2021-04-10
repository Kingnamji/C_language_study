#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101

void sort(int[], int); /* selection sort*/
void swap(int*, int*);
int compare(int x, int y);
int binsearch_recur(int list[], int searchnum, int left, int right);

void main(void)
{
	int i, n, searchnum;
	int search_flag = 0;
	int list[MAX_SIZE];

	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);

	if (n < 1 || n > MAX_SIZE)
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++)			/* randomly generate numbers */
	{
		list[i] = rand() % 1000;
		printf("%d  ", list[i]);
	}

	sort(list, n);

	printf("\n\nSorted array:\n");
	for (i = 0; i < n; i++)		/* print out sorted numbers */
		printf("%d  ", list[i]);
	printf("\n");

	printf("\nEnter the number to search: ");
	scanf_s("%d", &searchnum);

	printf("call binsearch_recur, left=%d, right=%d\n", 0, n - 1);
	n = binsearch_recur(list, searchnum, 0, n - 1);
	if (n < 0)
		printf("Thers is no searchnum : %d\n", searchnum);
	else
		printf("Thers is searchnum in the list[%d]\n", n);


}

void sort(int list[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(&list[i], &list[min]);
	}
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int compare(int x, int y)
{
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int binsearch_recur(int list[], int searchnum, int left, int right)
{
	int middle;
	if ((left <= right)) {
		middle = (left + right) / 2;
		if (list[middle] == searchnum) {
			printf("The search number is present in list[%d]\n", middle);
			return middle;
		}
		else if (list[middle] > searchnum)
			{
				printf("call binsearch_recur, left=%d, right=%d\n", left, middle - 1);
				return binsearch_recur(list, searchnum, left, middle - 1);
			}
		else
		{
			printf("call binsearch_recur, left=%d, right=%d\n", middle + 1, right);
			return binsearch_recur(list, searchnum, middle + 1, right);
		}
	}
	return -1;

}