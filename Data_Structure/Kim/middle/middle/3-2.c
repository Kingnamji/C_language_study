#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if ( !((p) = malloc(s)) ){\
		exit(1);\
}

int** make2dArray(int row, int col);

int main(void) {
	int** ipp;
	int i, j, rows, cols;
	printf("이차원 배열의 행과 열의 수를 입력 하세요 : ");
	scanf_s("%d %d", &rows, &cols);

	ipp = make2dArray(rows, cols);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("ipp[%d][%d] = %3d ", i,j, ipp[i][j]);
		}
		printf("\n");
	}

	return 0;
}

int** make2dArray(int row, int col) {
	int** p;
	int i, j;

	MALLOC(p, sizeof(int) * row);
	
	for (i = 0; i < row; i++)
		MALLOC(*(p + i), sizeof(int) * col);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) {
			*(*(p + i) + j) = rand() % 100;
		}
	}

	return p;
}