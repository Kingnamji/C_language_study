#include <stdio.h>
#define SECOND_PER_MINUTE 60

int main(void)
{
	int input = 1000;
	int minute = input / SECOND_PER_MINUTE;
	int second = input % SECOND_PER_MINUTE;
	printf("%d�ʴ� %d�� %d�� �Դϴ�. \n", input, minute, second);

	return 0;
}