#include <stdio.h>
#define MONTHS 12 // ����� �������ش�.

int main(void)
{
	double monthSalary = 1000.5;
	printf("$ %.2lf", monthSalary * MONTHS);

	return 0;
}