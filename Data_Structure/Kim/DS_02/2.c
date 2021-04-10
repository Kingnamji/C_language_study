#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

#define MAX_SIZE 2001


void sort(int list[], int n) // selection sort;
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;

		SWAP(list[i], list[min], temp);
	}
}

void main()
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;
	FILE *fp;
	
	fopen_s(&fp, "out.txt", "w");
	if (fp == NULL)
		exit(1);

	// times for n = 0, 10, ..., 100, 200, ..., 2000
	fprintf(fp, "      n         time\n");
	printf("      n         time\n");

	for (n = 0; n <= 2000; n += step)
	{// get time for size n 

	 // initialize with worst-case data
		for (i = 0; i < n; i++)
			a[i] = n - i; // 내림차순 데이터

		start = clock();
		sort(a, n); // 오름차순 정렬
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		fprintf(fp, "%6d       %f\n", n, duration);
		printf("%6d       %f\n", n, duration);
		if (n == 100) step = 100; // n = 100부터 step을 100으로
	}

	fclose(fp);
}