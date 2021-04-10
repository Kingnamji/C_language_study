#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101

void sort(int[], int); /* selection sort*/
void swap(int*, int*);
int compare(int x, int y);
int binsearch(int list[], int searchnum, int left, int right);

void main(void)
{
	int i, n, searchnum, searchResult;
	int list[MAX_SIZE];

	// 생성할 난수의 개수 입력받기
	printf("Enter the number of numbers to generate: ");
	scanf_s("%d", &n);

	if (n < 1 || n > MAX_SIZE) // 난수의 개수가 제한을 벗어나면 프로그램 종료
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < n; i++) // 랜덤으로 0~999의 난수 넣기
	{
		list[i] = rand() % 1000;
		printf("%d  ", list[i]);
	}

	sort(list, n); // 선택정렬 시행

	printf("\n\nSorted array:\n");
	for (i = 0; i < n; i++)		/* print out sorted numbers */
		printf("%d  ", list[i]);
	printf("\n");

	printf("\nEnter the number to search: ");
	scanf_s("%d", &searchnum);

	searchResult = binsearch(list, searchnum, 0, n - 1);

	if (searchResult == -1)
		printf("The search number is not present\n");
	else
		printf("The search number is present in list[%d]\n", searchResult);

}

void sort(int list[], int n) //selection sort
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


int binsearch(int list[], int searchnum, int left, int right)
/* search list[0] <= list[1] <= ... <= list[n-1] for searchnum.
return its position if found. Otherwise return -1 */
{
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		switch (compare(list[middle], searchnum))
		{
		case -1: left = middle + 1;
			break;
		case 0: return middle;
		case 1: right = middle - 1;
		}
	}
	return -1; // 못 찾은 경우
}
