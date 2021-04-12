#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_TERMS 101
#define MAX_COL 20
#define MAX_ROW 20


typedef struct
{
	int row;
	int col;
	int value;
}term;

int main(void)
{
	term a[MAX_TERMS+1];

	int i, j, row_ind, col_ind, sp_ind;
	int sparse[MAX_ROW][MAX_COL] = { 0 };

	sp_ind = 0;
	// 첫번째 index의 row => the number of rows, col => the number of columns
	// value = the total number of nonzero entries
	printf("원소의 개수를 쓰시오 .. ");
	scanf_s("%d", &a[0].value);
	a[0].row = MAX_ROW; 
	a[0].col = MAX_COL;

	srand((unsigned)time(NULL));

	for (i = 0; i<a[0].value; i++)
	{
		row_ind = rand() % MAX_ROW; // row를 최대 범위 안에서 random으로 결정
		col_ind = rand() % MAX_COL; // col를 최대 범위 안에서 random으로 결정
		if (sparse[row_ind][col_ind] != 0) // random으로 생성됐으나 해당 항에 값이 혹시라도 있다면 다시
			i--;
		else // 해당 항에 값이 없다면
			sparse[row_ind][col_ind] = rand() % 100; // 0~99의 값 부여
	}

	// sparse matrix 출력
	printf("Random generated Matrix(%d,%d) \n",  MAX_ROW, MAX_COL);
	for (i = 0; i<MAX_ROW; i++)
	{
		for (j = 0; j<MAX_COL; j++)
			printf("%5d", sparse[i][j]);
		printf("\n");
	}

	// 구조체 a에 sparse matrix의 row, col, value를 순서대로 저장
	for (i = 0; i<MAX_ROW; i++)
	{
		for (j = 0; j<MAX_COL; j++)
			if (sparse[i][j] != 0) {
				a[++sp_ind].row = i;
				a[sp_ind].col = j;
				a[sp_ind].value = sparse[i][j];
			}
	}

	printf("\nsparce matrix \n");
	for (i = 0; i <= a[0].value; i++)
		printf("%5d, %5d %5d\n", a[i].row, a[i].col, a[i].value);
	return 0;
}