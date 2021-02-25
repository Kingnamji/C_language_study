#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define NUMBER 5

int main(void)
{
	int i, max, min, index;
	// 배열은 다양한 데이터를 삽입할 수 있는 공간
	int array[NUMBER]; // 크기가 5인 배열 선언
	max = INT_MIN;
	index = 0;
	min = INT_MAX;
	// array[0] ~ array[4] : 총 5개가 들어갈 수 있는 크기의 배열 선언
	for (i = 0; i < NUMBER; i++)
	{
		scanf("%d", &array[i]);
		if (max < array[i])
		{
			max = array[i];
			index = i;
		}
	}
	printf("가장 큰 값은%d입니다. 그리고%d 번째에 있습니다.\n", max, index + 1);

	for (i = 0; i < NUMBER; i++)
	{
		scanf("%d", &array[i]);
		if (min > array[i])
		{
			min = array[i];
			index = i;
		}
	}
	printf("가장 작은 값은%d입니다. 그리고%d 번째에 있습니다.\n", min, index + 1);

	return 0;
}