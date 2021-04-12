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
	// ù��° index�� row => the number of rows, col => the number of columns
	// value = the total number of nonzero entries
	printf("������ ������ ���ÿ� .. ");
	scanf_s("%d", &a[0].value);
	a[0].row = MAX_ROW; 
	a[0].col = MAX_COL;

	srand((unsigned)time(NULL));

	for (i = 0; i<a[0].value; i++)
	{
		row_ind = rand() % MAX_ROW; // row�� �ִ� ���� �ȿ��� random���� ����
		col_ind = rand() % MAX_COL; // col�� �ִ� ���� �ȿ��� random���� ����
		if (sparse[row_ind][col_ind] != 0) // random���� ���������� �ش� �׿� ���� Ȥ�ö� �ִٸ� �ٽ�
			i--;
		else // �ش� �׿� ���� ���ٸ�
			sparse[row_ind][col_ind] = rand() % 100; // 0~99�� �� �ο�
	}

	// sparse matrix ���
	printf("Random generated Matrix(%d,%d) \n",  MAX_ROW, MAX_COL);
	for (i = 0; i<MAX_ROW; i++)
	{
		for (j = 0; j<MAX_COL; j++)
			printf("%5d", sparse[i][j]);
		printf("\n");
	}

	// ����ü a�� sparse matrix�� row, col, value�� ������� ����
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