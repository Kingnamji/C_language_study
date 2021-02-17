#include <stdio.h>

int main(void)
{
	int x = 100;

	printf("10진수로 출력 : %d\n", x);
	printf("8진수로 출력 : %o\n", x); // %o로 출력하면 8진수로 나온다.
	printf("16진수로 출력 : %x\n", x); // %x로 출력하면 16진수로 나온다.

	return 0;
}