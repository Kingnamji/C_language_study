#include <stdio.h>

int main(void)
{
	int x = 50, y = 30;
	// x�� y�� ���� ���� ������ �ִ°�? x == y ?
	printf("x�� y�� ������? %d \n", x == y);
	printf("x�� y�� �ٸ���? %d \n", x != y);
	printf("x�� y���� ū��? %d \n", x > y);
	printf("x�� y���� ������? %d \n", x < y);
	printf("x�� y���� ������? %d \n", x = y);
	printf("�� �� x�� ����? %d \n", x);

	return 0;
}