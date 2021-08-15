#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동. \n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d을(를) %c에서 %c로 이동. \n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void) {

	int n;
	
	printf("몇 개로 실행할지 입력 : ");
	scanf_s("%d", &n);

	HanoiTowerMove(n, 'A', 'B', 'C');

	return 0;
}