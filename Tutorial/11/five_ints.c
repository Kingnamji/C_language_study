#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define NUMBER 5

int main(void)
{
	int i, max, min, index;
	// �迭�� �پ��� �����͸� ������ �� �ִ� ����
	int array[NUMBER]; // ũ�Ⱑ 5�� �迭 ����
	max = INT_MIN;
	index = 0;
	min = INT_MAX;
	// array[0] ~ array[4] : �� 5���� �� �� �ִ� ũ���� �迭 ����
	for (i = 0; i < NUMBER; i++)
	{
		scanf("%d", &array[i]);
		if (max < array[i])
		{
			max = array[i];
			index = i;
		}
	}
	printf("���� ū ����%d�Դϴ�. �׸���%d ��°�� �ֽ��ϴ�.\n", max, index + 1);

	for (i = 0; i < NUMBER; i++)
	{
		scanf("%d", &array[i]);
		if (min > array[i])
		{
			min = array[i];
			index = i;
		}
	}
	printf("���� ���� ����%d�Դϴ�. �׸���%d ��°�� �ֽ��ϴ�.\n", min, index + 1);

	return 0;
}