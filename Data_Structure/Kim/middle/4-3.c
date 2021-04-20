#include <stdio.h>

#define MAX_TERMS 100
#define MAX_COL 10

typedef struct {
	int row;
	int col;
	int value;
}term;

term a[MAX_TERMS];
term b[MAX_TERMS];

void fastTranspose(term *a, term *b);
void printmatrix(term matrix[]);


int main(void)
{
	FILE* fp1, * fp2;
	int i;

	fopen_s(&fp1, "a.txt", "r");
	fopen_s(&fp2, "b.txt", "w");

	if (fp1 == NULL) {
		exit(1);
	}
	if (fp2 == NULL) {
		exit(1);
	}

	fscanf_s(fp1, "%d %d %d", &a[0].row, &a[0].col, &a[0].value);

	for (i = 1; i <= a[0].value; i++)
	{
		fscanf_s(fp1, "%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}

	fastTranspose(a, b);
	printf("A\n");
	printmatrix(a);
	printf("B\n");
	printmatrix(b);

	for (i = 0; i <= a[0].value; i++) {
		fprintf(fp2, "%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}

	fclose(fp1);
	fclose(fp2);


	return 0;
}

void fastTranspose(term *a, term *b) {
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a->col, numTerms = a->value;

	b->row = numCols;
	b->col = a->row;
	b->value = numTerms;

	if (numTerms > 0)
	{
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[(a+i)->col]++;

		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];


		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[(a + i)->col]++;
			(b+j)->row = (a+i)->col;
			(b+j)->col = (a + i)->row;
			(b+j)->value = (a + i)->value;
		}
	}
}


void printmatrix(term matrix[]) {
	int row, col, i, j, idx;

	row = matrix[0].row;
	col = matrix[0].col;

	idx = 1;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++) {
			if (i == matrix[idx].row && j == matrix[idx].col) {
				printf("%4d", matrix[idx].value);
				idx++;
			}
			else
				printf("%4d", 0);
		}
		printf("\n");
	}
}