#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 101
#define ROW 20
#define COL 20

typedef struct {
	int row;
	int col;
	int value;
}term;

term a[MAX_TERMS];

int main(void)
{
	int i, j;
	int row_idx, col_idx, a_idx;
	int sparse[ROW][COL] = { 0 };
	a_idx = 0;
	srand((time(NULL)));

	printf("원소의 개수를 쓰시오.. ");
	scanf_s("%d", &a[0].value);
	a[0].row = ROW;
	a[0].col = COL;

	printf("Random generated Maxtrix(%d,%d)\n", a[0].row, a[0].col);

	for (i = 0; i < a[0].value; i++) {
		row_idx = rand() % 20;
		col_idx = rand() % 20;

		if (sparse[row_idx][col_idx] != 0)
			i--;
		else
			sparse[row_idx][col_idx] = rand() % 100;
	}


	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%5d", sparse[i][j]);
			if (sparse[i][j] != 0) {
				a[++a_idx].row = i;
				a[a_idx].col = j;
				a[a_idx].value = sparse[i][j];
			}
		}
		printf("\n");
	}

	printf("sparse matrix\n");

	for (i = 0; i <= a[0].value; i++) {
		printf("%5d, %5d, %5d\n", a[i].row, a[i].col, a[i].value);
	}

	return 0;
}