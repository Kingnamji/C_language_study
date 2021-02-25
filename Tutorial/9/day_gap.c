#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getDays(int month, int day)
{
	int i, sum = 0;
	for (i = 1; i < month; i++)
	{
		if (i == 2) // 윤년을 무시하고 만든 함수입니다.
		{
			sum += 28;
		}
		else if (i % 2 == 0)
		{
			sum += 30;
		}
		else
		{
			sum += 31;
		}
	}
	return sum + day;
}

int main(void)
{
	int month, day;
	printf("month와 day를 입력하세요 : ");
	scanf("%d %d", &month, &day);

	printf("1월 1일부터 해당 날짜까지의 거리는 %d입니다.", getDays(month, day));

	return 0;
}