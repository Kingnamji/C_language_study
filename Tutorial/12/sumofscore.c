#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int score[5][2];
	int total[2] = { 0, };
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("%d�� �л��� ����, ���� ���� : ", i + 1);
		scanf("%d %d", &score[i][0], &score[i][1]);
	}

	for (i = 0; i < 5; i++)
	{
		total[0] += score[i][0];
		total[1] += score[i][1];
	}
	printf("\n\n5���� ���� ���� �հ� : %d\n", total[0]);
	printf("5���� ���� ���� �հ� : %d\n", total[1]);
	return 0;
}
