#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getDays(int month, int day)
{
	int i, sum = 0;
	for (i = 1; i < month; i++)
	{
		if (i == 2) // ������ �����ϰ� ���� �Լ��Դϴ�.
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
	printf("month�� day�� �Է��ϼ��� : ");
	scanf("%d %d", &month, &day);

	printf("1�� 1�Ϻ��� �ش� ��¥������ �Ÿ��� %d�Դϴ�.", getDays(month, day));

	return 0;
}