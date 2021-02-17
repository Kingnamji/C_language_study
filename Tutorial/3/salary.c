#include <stdio.h>
#define MONTHS 12 // 상수를 정의해준다.

int main(void)
{
	double monthSalary = 1000.5;
	printf("$ %.2lf", monthSalary * MONTHS);

	return 0;
}