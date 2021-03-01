#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) 
{
	int i, j;
	int gugudan[10][10];
	for (i = 1; i <= 9; i++)
	{
		printf("\n[ %d ] ´Ü\n\n", i);
		for (j = 1; j <= 9; j++)
		{
			gugudan[i][j] = i * j;
			printf("%d X %d = %d \n", i, j, gugudan[i][j]);
		}
	}

	return 0;
}