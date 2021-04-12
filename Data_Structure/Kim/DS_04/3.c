#include <stdio.h>
#define MAX_TERMS 101
#define MAX_COL 10

typedef struct
{
	int row;
	int col;
	int value;
}term;

void fastTranspose1(term *a, term *b);
void fastTranspose2(term *a, term *b);
void printMatrix(term matrix[]);

int main(void)
{
	term a[MAX_TERMS];
	term b[MAX_TERMS];
	int i, numTerms;
	FILE *fpA;
	FILE *fpB;

	fopen_s(&fpA, "a.txt", "r");
	fopen_s(&fpB, "b.txt", "w");

	// input a.txt
	fscanf_s(fpA, "%d%d%d", &a[0].row, &a[0].col, &a[0].value);
	numTerms = a[0].value;
	for (i = 1; i <= numTerms; i++)
		fscanf_s(fpA, "%d%d%d", &a[i].row, &a[i].col, &a[i].value);


	fastTranspose2(a, b);

	// output b.txt
	for (i = 0; i <= numTerms; i++)
		fprintf_s(fpB, "%d %d %d\n", b[i].row, b[i].col, b[i].value);

	printf("A\n");
	printMatrix(a);

	printf("B\n");
	printMatrix(b);

	fclose(fpA);
	fclose(fpB);

	return 0;
}

void fastTranspose1(term *a, term *b)
{	/*  the transpose of a is placed in b */
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = a->col, numTerms = a->value;

	b->row = numCols;
	b->col = a->row;
	b->value = numTerms;

	if (numTerms > 0)
	{
		// calculationof rowTerms
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[(a + i)->col]++;
		// calculation of startingPos
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		//a(i, j) -->b(j, i)
		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[(a + i)->col]++;
			(b + j)->row = (a + i)->col;
			(b + j)->col = (a + i)->row;
			(b + j)->value = (a + i)->value;
		}
	}
}

void fastTranspose2(term *a, term *b)
{	/*  the transpose of a is placed in b */
	int rowTerms[MAX_COL], startingPos[MAX_COL];
	int i, j, numCols = (*a).col, numTerms = (*a).value;

	(*b).row = numCols;
	(*b).col = (*a).row;
	(*b).value = numTerms;

	if (numTerms > 0)
	{
		// calculationof rowTerms
		for (i = 0; i < numCols; i++)
			rowTerms[i] = 0;
		for (i = 1; i <= numTerms; i++)
			rowTerms[(*(a + i)).col]++;
		// calculation of startingPos
		startingPos[0] = 1;
		for (i = 1; i < numCols; i++)
			startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];

		//a(i, j) -->b(j, i)
		for (i = 1; i <= numTerms; i++)
		{
			j = startingPos[(*(a + i)).col]++;
			(*(b + j)).row = (*(a + i)).col;
			(*(b + j)).col = (*(a + i)).row;
			(*(b + j)).value = (*(a + i)).value;
		}
	}
}

void printMatrix(term matrix[])
{
	int row, col, i, j, element, p;
	row = matrix[0].row;
	col = matrix[0].col;

	element = 0;
	p = 1;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == matrix[p].row && j == matrix[p].col)
				element = matrix[p++].value;
			else
				element = 0;
			printf("%4d", element);
		}
		printf("\n");
	}
}