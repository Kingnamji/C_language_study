#include <stdio.h>
#include <time.h>

#define MAX_SIZE 2001

void swap(int* x, int* y);
void sort(int list[], int n);

int main(void)
{
	int i, n, step = 10;
	int a[MAX_SIZE];
	double duration;
	clock_t start;

	printf("    n    time\n");
	for (n = 0; n <= MAX_SIZE - 1; n += step)
	{
		for (i = 0; i < n; i++)
		{
			a[i] = n - i;
		}
		start = clock();
		sort(a, n);
		duration = ((double)(clock() - start)) / CLOCKS_PER_SEC;

		printf("%6d     %f\n", n, duration);
		if (n == 100)
			step = 100;
	}

	return 0;
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int list[], int n)
{
	int i, j;
	int min;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] = list[min])
				min = j;
		}
		swap(list + i, list + min);
	}
}
