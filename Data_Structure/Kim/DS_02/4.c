// 선택정렬 - 성능측정 "역정렬", "순정렬", "랜덤"
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
	int i, n, step = 10, count = 0, n_size_array[50]; // 정렬할 데이터의 크기
	int a[MAX_SIZE];  // 정렬할 데이터
	double duration, array[50][3]; // 역정렬, 순정렬, 랜덤시 수행 시간
//	clock_t start_t, end_t;
	double start_t, end_t;

	FILE* fp;
	fopen_s(&fp, "out.txt", "w");
	if (fp == NULL)
		exit(1);

	// times for n = 0, 10, ..., 100, 200, ..., 2000

	srand((unsigned int)time(NULL));

	fprintf(fp, "%10s %10s %12s %11s\n", "n size", "역정렬", "순정렬", "랜덤");
	printf("%10s %10s %12s %11s\n", "n size", "역정렬", "순정렬", "랜덤");
	// 역정렬
	//	duration = 0.0;
	for (n = 0; n <= 2000; n += step)
	{
		// get time for size n
		long repetitions = 0;
		duration = 0.0;

		do
		{
			repetitions++;

			// initialize  with reversed data			
			for (i = 0; i < n; i++)
				a[i] = n - i;

			start_t = (double)clock();
			sort(a, n);
			end_t = (double)clock();
			duration = duration + end_t - start_t;

		} while (duration < 1000);
		// repeat until enough time has elapsed

		duration = duration / CLOCKS_PER_SEC;
		duration /= repetitions;

		if (n == 100) step = 100;

		n_size_array[count] = n;
		array[count][0] = duration;

		count++;
		printf(".");
	}

	// 순정렬
	step = 10;
	count = 0;

	for (n = 0; n <= 2000; n += step)
	{
		// get time for size n
		duration = 0.0;
		long repetitions = 0;
		do
		{
			repetitions++;

			// initialize with sorted data		
			for (i = 0; i < n; i++)
				a[i] = i;

			start_t = (double)clock();
			sort(a, n);
			end_t = (double)clock();
			duration = duration + end_t - start_t;

		} while (duration < 1000);
		// repeat until enough time has elapsed

		duration = duration / CLOCKS_PER_SEC;
		duration /= repetitions;

		if (n == 100) step = 100;

		array[count][1] = duration;

		count++;
		printf(".");
	}

	//랜덤
	step = 10;
	count = 0;

	for (n = 0; n <= 2000; n += step)
	{
		// get time for size n
		long repetitions = 0;
		duration = 0.0;
		do
		{
			repetitions++;

			// initialize with random data			
			for (i = 0; i < n; i++)
				a[i] = rand();

			start_t = (double)clock();
			sort(a, n);
			end_t = (double)clock();
			duration = duration + end_t - start_t;

		} while (duration < 1000);
		// repeat until enough time has elapsed

		duration = duration / CLOCKS_PER_SEC;
		duration /= repetitions;

		if (n == 100) step = 100;

		array[count][2] = duration;
		count++;
		printf(".");
	}
	printf("\n");
	for (i = 0; i < count; i++) {
		fprintf(fp, "%10d %f     %f     %f\n", n_size_array[i], array[i][0], array[i][1], array[i][2]);
		printf("%7d       %f     %f     %f\n", n_size_array[i], array[i][0], array[i][1], array[i][2]);
	}

	fclose(fp);


}