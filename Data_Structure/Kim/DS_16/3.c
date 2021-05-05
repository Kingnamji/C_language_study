#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 500
#define INF_NUM 10000

int sort(int k, int nums[][11], int winTree[], int sortidx[]);

int nums[MAX_SIZE + 1][11], sortedIdx[MAX_SIZE + 1];
int winTree[MAX_SIZE * 2], result[MAX_SIZE * 10 + 1];

int main()
{
	FILE* fp;
	unsigned seed;
	int i, j, cnt;
	int k = 8;
	int col = 10;
	
	fopen_s(&fp, "input3.txt", "r");
	printf("<<<<<<<<<<<<< run data >>>>>>>>>>>>>\n\n");

	for (i = 1; i <= k; i++)
	{
		printf("%d-th run:\n", i);
		sortedIdx[i] = 1;
		for (j = 1; j <= col; j++) {
			fscanf_s(fp, "%d", &nums[i][j]);
			printf("%5d", nums[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");

	for (cnt = 2 * k - 1, i = k; cnt >= k && i >= 1; cnt--, i--) {
		winTree[cnt] = i;
	}

	for (i = 2 * k - 1; i > 1; i -= 2)
	{
		if (nums[winTree[i - 1]][sortedIdx[winTree[i - 1]]] < nums[winTree[i]][sortedIdx[winTree[i]]])
			winTree[(i - 1) / 2] = winTree[i - 1];
		else
			winTree[(i - 1) / 2] = winTree[i];
	}

	printf("Leve-order traversal for initial min-winner tree\n");
	for (i = 1; i <= 2 * k - 1; i++) {
		printf("%d ", nums[winTree[i]][1]);
	}

	printf("\n\nsorting with min-winner tree...\n\n");
	printf("sorted result\n");
	for (i = 1; i <= k * col; i++)
	{
		result[i] = sort(k, nums, winTree, sortedIdx);
		printf("%3d ", result[i]);
		
		if (i % 8 == 0)
			printf("\n");
	}

	fclose(fp);

	return 0;
}

int sort(int k, int nums[][11], int winTree[], int sortidx[])
{
	int min = nums[winTree[k]][sortidx[winTree[k]]], minIdex = winTree[k];
	for (int i = k + 1; i < 2 * k; i++)
	{
		if (min > nums[winTree[i]][sortidx[winTree[i]]])
		{
			min = nums[winTree[i]][sortidx[winTree[i]]];
			minIdex = winTree[i];
		}
	}

	sortidx[minIdex]++;
	if (sortidx[minIdex] > 10)
		nums[minIdex][--sortidx[minIdex]] = INF_NUM;

	for (int i = 2 * k - 1; i > 1; i -= 2)
	{
		if (nums[winTree[i - 1]][sortidx[winTree[i - 1]]] < nums[winTree[i]][sortidx[winTree[i]]])
			winTree[(i - 1) / 2] = winTree[i - 1];
		else
			winTree[(i - 1) / 2] = winTree[i];
	}

	return min;
}