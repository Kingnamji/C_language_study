#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 20
#define MAX_ROW_SIZE 4
#define MAX_COL_SIZE 5

int maze[MAX_ROW_SIZE][MAX_COL_SIZE];
int mark[MAX_ROW_SIZE][MAX_COL_SIZE] = { 0 };

typedef struct {
	int vert;
	int horiz;
}offsets;

typedef struct {
	int row;
	int col;
	int dir;
}element;

element stack[MAX_STACK_SIZE];
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0,-1}, {-1, -1} };

int top;

int main(void)
{
	int r, c, d;
	int rows, cols;
	int nextRow, nextCol;
	int EXIT_ROW, EXIT_COL;
	int found = 0;
	FILE* fp;
	element position = { 0, 0, 0 };
	mark[0][0] = 1; top = 0;
	stack[0].row = 0; stack[0].col = 0; stack[0].dir = 1;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
		exit(1);

	fscanf_s(fp, "%d %d", &rows, &cols);
	EXIT_ROW = rows-1;
	EXIT_COL = cols-1;

	for (r = 0; r < rows; r++) {
		for (c = 0; c < cols; c++) {
			fscanf_s(fp, "%d", &maze[r][c]);
		}
	}

	while (top > -1 && !found) {
		// pop
		top--;
		r = position.row; c = position.col;
		d = position.dir;
		
		while (d < 8 && !found) {
			if (position.row == 0 && (d == 0 || d==1))
				d = 2;
			else if (position.col == MAX_COL_SIZE - 1 && d == 1)
				d = 4;
			nextRow = r + move[d].vert;
			nextCol = c + move[d].horiz;
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				found = 1;
			else if ((!maze[nextRow][nextCol]) && (!mark[nextRow][nextCol]))
			{
				mark[nextRow][nextCol] = 1;
				position.row = r;
				position.col = c;
				position.dir = ++d;
				//push
				top++;
				stack[top].row = position.row;
				stack[top].col = position.col;
				stack[top].dir = position.dir;

				r = nextRow; c = nextCol; d = 0;
			}
			else ++d;
		}
	}

	if (found)
	{
		printf("The path is:\n");
		printf("row col\n");
		for (int i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", r, c);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path\n");


	fclose(fp);
}