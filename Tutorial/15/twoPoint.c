#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct point {
	int x;
	int y;
};

int main(void)
{
	struct point p1, p2;
	int xDiff, yDiff;
	double distance;
	// ��ǥ �Է¹ޱ�
	printf("1�� ���� ��ǥ�� �Է��ϼ��� : ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("2�� ���� ��ǥ�� �Է��ϼ��� : ");
	scanf("%d %d", &p2.x, &p2.y);
	// x���� �Ÿ�, y�� ���� �Ÿ��� �̿��� �Ÿ� ���
	xDiff = p1.x - p2.x;
	yDiff = p1.y - p2.y;
	distance = sqrt(pow(xDiff, 2) + pow(yDiff, 2)); // �� �� ������ �Ÿ�

	printf("�� �� ������ �Ÿ��� %lf�Դϴ�.\n", distance);

	return 0;
}