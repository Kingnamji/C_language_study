#include <stdio.h>
// ���� �ǵ� �˰��� -> 4�⸶�� But 100�� �������� ���⿡ �ش�x
// ���� => 400�� ������ ���� � ��Ȳ�̵� �������� �ش�
int main(void)
{
	int year = 2016;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d���� �����Դϴ�.\n", year);
	}
	else
	{
		printf("%d���� ������ �ƴմϴ�.\n", year);
	}

	return 0;
}