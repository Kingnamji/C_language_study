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
	// 좌표 입력받기
	printf("1번 점의 좌표를 입력하세요 : ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("2번 점의 좌표를 입력하세요 : ");
	scanf("%d %d", &p2.x, &p2.y);
	// x기준 거리, y축 기준 거리를 이용한 거리 계산
	xDiff = p1.x - p2.x;
	yDiff = p1.y - p2.y;
	distance = sqrt(pow(xDiff, 2) + pow(yDiff, 2)); // 두 점 사이의 거리

	printf("두 점 사이의 거리는 %lf입니다.\n", distance);

	return 0;
}