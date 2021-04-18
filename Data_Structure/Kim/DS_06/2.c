#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 20
#define MAX_LEN 100
#define EXIT_ROW 4
#define EXIT_COL 5


typedef struct {
	short int vert;
	short int horiz;
}offsets;

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;

element stack[MAX_STACK_SIZE];
offsets move[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int maze[6][7] = { {1, 1, 1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1, 1, 1},
						{1, 1, 1, 1, 1, 1, 1}, };

int mark[6][7] = { {0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0}, };
int top;

int main(void)
{
	FILE* fp;
	char line[MAX_LEN];
	int row, col;
	int nextRow, nextCol, dir, found = 0;
	element position = { 1, 1, 0 };
	mark[1][1] = 1; top = 0; // 스택에 초기 값 추가
	stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
	
	fopen_s(&fp, "input.txt", "r");
	fscanf_s(fp, "%d %d\n", &row, &col);

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++)
			fscanf_s(fp, "%d", &maze[i][j]);
	}
	
	
	while (top > -1 && !found) {
		// pop
		top--;
		row = position.row; col = position.col;
		dir = position.dir;

		while(dir < 8 && !found){
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;
			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				found = 1;
			else if ((!maze[nextRow][nextCol]) && (!mark[nextRow][nextCol]))
			{
				mark[nextRow][nextCol] = 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				//push
				top++;
				stack[top].row = position.row;
				stack[top].col = position.col;
				stack[top].dir = position.dir;

				row = nextRow; col = nextCol; dir = 0;
			}
			else ++dir;
		}	
	}

	if (found)
	{
		printf("The path is:\n");
		printf("row col\n");
		for (int i = 0; i <= top; i++)
			printf("%2d%5d\n", stack[i].row, stack[i].col);
		printf("%2d%5d\n", row, col);
		printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
	}
	else
		printf("The maze does not have a path\n");


	fclose(fp);

	return 0;
}