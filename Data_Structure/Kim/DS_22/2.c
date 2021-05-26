#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int sorted[MAX_SIZE];
int data[MAX_SIZE];

void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

int n;

int main(void)
{
	int i;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		printf("Cannot open the file");
		exit(1);
	}

	fscanf_s(fp, "%d", &n);

	printf("<<<<<<<<<<<<< Input List >>>>>>>>>>>>>>>>\n");
	for (i = 1; i <= n; i++) {
		fscanf_s(fp, "%d", &data[i]);
		printf("%d ", data[i]);
	}

	printf("\n\n<<<<< executing recursive merge sort >>>>>\n");

	merge_sort(data, 1, n);

	printf("<<<<<<<<<<<<< Sorted List >>>>>>>>>>>>>>>>\n");
	for (i = 1; i <= n; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	fclose(fp);

	return 0;
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

}
void merge_sort(int list[], int left, int right)
{
	int mid, i;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		printf("call merge(list, left=%d, mid=%d, right=%d)\n", left, mid, right);
		merge(list, left, mid, right);

		printf("result : ");
		for (i = 1; i <= n; i++)
			printf("%d ", list[i]);
		printf("\n\n");
	}
}
