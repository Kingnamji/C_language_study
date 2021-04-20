#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if ( !((p) = malloc(s)) ){\
		exit(1);\
}
#define MAX_NUM 100

void swap(int* x, int* y);
void sort(int list[], int n);
int compare(int x, int y);
int Bsearch(int list[], int searchnum, int left, int right);

int main(void)
{
	int num, searchnum, idx;
	int a[MAX_NUM];
	int i;

	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &num);

	for (i = 0; i < num; i++) {
		a[i] = rand() % 1000;
		printf("%d ", a[i]);
	}

	sort(a, num);

	printf("\nsorted array:\n");
	for (i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
	printf("\n\n");
	printf("Enter the number to search: ");
	scanf_s("%d", &searchnum);
	
	idx = Bsearch(a, searchnum, 0, num - 1);
	printf("The search number is present in list[%d]\n\n", idx);

	return 0;
}

void swap(int *x, int *y) 
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int list[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
		}
		swap(list+i, list+min);
	}
}

int compare(int x, int y) {
	if (x < y) return -1;
	else if (x == y) return 0;
	else return 1;
}

int Bsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	int result;

	while (left <= right)
	{
		middle = (left + right) / 2;

		result = compare(list[middle], searchnum);
		if (result == -1)
			left = middle + 1;
		else if (result == 0)
			return middle;
		else
			right = middle - 1;
	}
	return -1; // 못 찾은 경우
}