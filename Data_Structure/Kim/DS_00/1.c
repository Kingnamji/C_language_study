#include <stdio.h>

int sum(int, int);
float average(int, int);

int main() {
	int s, f;
	printf("�� ���� �Է� >>");
	scanf_s("%d %d", &s, &f);

	printf("�μ� ������ ���� �� : %d\n", sum(s, f));
	printf("�μ� ���� ������ ��� : %f\n", average(s, f));
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