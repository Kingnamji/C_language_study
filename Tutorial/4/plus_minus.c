#include <stdio.h>

int main(void)
{
	int x = 0;

	printf("현재의 x는 %d입니다.\n", x);

	x++;

	printf("현재의 x는 %d입니다.\n", x);
	printf("현재의 x는 %d입니다.\n", x--); // 출력 후에 감소가 이루어진다.
	printf("현재의 x는 %d입니다.\n", x);
	printf("현재의 x는 %d입니다.\n", --x); // 출력 전에 감소가 이루어진다.

	return 0;
}