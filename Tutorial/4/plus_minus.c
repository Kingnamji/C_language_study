#include <stdio.h>

int main(void)
{
	int x = 0;

	printf("������ x�� %d�Դϴ�.\n", x);

	x++;

	printf("������ x�� %d�Դϴ�.\n", x);
	printf("������ x�� %d�Դϴ�.\n", x--); // ��� �Ŀ� ���Ұ� �̷������.
	printf("������ x�� %d�Դϴ�.\n", x);
	printf("������ x�� %d�Դϴ�.\n", --x); // ��� ���� ���Ұ� �̷������.

	return 0;
}