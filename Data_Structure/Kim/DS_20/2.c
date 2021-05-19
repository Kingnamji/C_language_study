#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 7
#define INF 999

int cost[MAX_VERTICES][MAX_VERTICES];
int A[MAX_VERTICES][MAX_VERTICES];

void floyd(int n);

int main(void)
{
	int v, e;
	int i, row, col, value;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		exit(1);
	}

	fscanf_s(fp, "%d %d", &v, &e);

	for (row = 0; row < v; row++) {
		for (col = 0; col < v; col++)
		{
			if (row == col)
				cost[row][col] = 0;
			else cost[row][col] = INF;
		}
	}

	for (i = 0; i < e; i++)
	{
		fscanf_s(fp, "%d %d %d", &row, &col, &value);
		cost[row][col] = value;
		cost[col][row] = value;
	}

	floyd(v);

	return 0;
}


void floyd(int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = cost[i][j];

	for (k = 0; k < n; k++) {
		printf("=====================================\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
				printf("%5d", A[i][j]);
			}
			printf("\n");
		}
		printf("=====================================\n");
	}
}