#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if (!((p) = malloc(s))){\
		exit(1);\
	}

int** make2dArray(int, int);

int main()
{
	int** ipp;
	int i, j, rows, cols;

	printf("이차원 배열의 수를 입력하세요: ");
	scanf_s("%d %d", &rows, &cols);

	ipp = make2dArray(rows, cols);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("ipp[%d][%d] =%2d ", i, j, ipp[i][j]);

		}
		printf("\n");
	}

	for (i = 0; i < rows; i++)
	{
		free(ipp[i]);
	}
	free(ipp);

	return;
}


int** make2dArray(int R, int C)
{
	int** p; // 원소가 포인터인 배열의 시작주소
	int *ap=NULL;
	int i, j;

	MALLOC(((int**)p), sizeof(int*) * R); 

	for (i = 0; i < R; i++)
	{
		
		p[i] = (int*)malloc(sizeof(int) * C);
		for (j = 0; j < C; j++)
				p[i][j] = rand() % 100;
	}

	return p;
}