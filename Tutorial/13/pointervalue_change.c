#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>

int main(void)
{
	int i = 10;
	int* p = &i;
	printf("i = %d\n", i);
	printf("i狼 林家 = %d\n", p);
	*p = 20;
	printf("i = %d\n", i);
	printf("i狼 林家 = %d\n", &i);

	return 0;
}