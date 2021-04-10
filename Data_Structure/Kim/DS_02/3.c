// 역순정렬된 데이터에 대한 선택정렬 - 성능측정
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

#define MAX_SIZE 2001


void sort(int list[], int n)
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

void main(void)
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
	fprintf(fp, "    n       repetitions        time\n");
	printf("    n       repetitions        time\n");

	for (n = 0; n <= 2000; n += step)
	{
		// get time for size n
		long repetitions = 0;
		clock_t start = clock();
		do
		{
			repetitions++;

			// initialize with worst-case data
			for (i = 0; i < n; i++)
				a[i] = n - i;

			sort(a, n);
		} while (clock() - start < 1000);
		// repeat until enough time has elapsed

		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		duration /= repetitions;

		fprintf(fp, "%6d      %9d     %f\n", n, repetitions, duration);
		printf("%6d      %9d     %f\n", n, repetitions, duration);
		if (n == 100) step = 100;
	}
}
