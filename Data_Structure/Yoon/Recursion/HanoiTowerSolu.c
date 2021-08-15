#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("���� 1�� %c���� %c�� �̵�. \n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("���� %d��(��) %c���� %c�� �̵�. \n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void) {

	int n;
	
	printf("�� ���� �������� �Է� : ");
	scanf_s("%d", &n);

	HanoiTowerMove(n, 'A', 'B', 'C');

	return 0;
}