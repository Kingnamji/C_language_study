#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];

void inc_insertion_sort(int list[], int first, int last, int gap);
void shell_sort(int list[], int n);

void main()
{
	int i, num;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot open the File");
		exit(1);
	}

	fscanf_s(fp, "%d", &num);

	for (i = 0; i < num; i++)
		fscanf_s(fp, "%d", &list[i]);

	printf("list[] data\n");
	for (i = 0; i < num; i++)
		printf("%5d", list[i]);

	shell_sort(list, num); 
}


void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}


void shell_sort(int list[], int n)  
{
	int i, gap;
	
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;

		for (i = 0; i < gap; i++)	
			inc_insertion_sort(list, i, n - 1, gap);

		printf("\n\ngap is %5d ====>\n", gap);

		for (i = 0; i < n; i++)
			printf("%5d", list[i]);

		printf("\n");
	}

}