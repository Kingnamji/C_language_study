#include <stdio.h>

int sum(int, int);
float average(int, int);

int main() {
	int s, f;
	printf("두 정수 입력 >>");
	scanf_s("%d %d", &s, &f);

	printf("두수 사이의 정수 합 : %d\n", sum(s, f));
	printf("두수 사이 정수의 평균 : %f\n", average(s, f));
}

int sum(int a, int b)
{
	int i, sum = 0;
	for (i = a + 1; i < b; i++)
		sum += i;
	return sum;
}

float average(int a, int b)
{
	int i, sum = 0;
	for (i = a + 1; i < b; i++)
		sum += i;
	return sum / (b - a - 1);
}