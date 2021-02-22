#include <stdio.h>
// 윤년 판독 알고리즘 -> 4년마다 But 100년 단위에는 윤년에 해당x
// 윤년 => 400년 단위일 때는 어떤 상황이든 윤년으로 해당
int main(void)
{
	int year = 2016;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d년은 윤년입니다.\n", year);
	}
	else
	{
		printf("%d년은 윤년이 아닙니다.\n", year);
	}

	return 0;
}