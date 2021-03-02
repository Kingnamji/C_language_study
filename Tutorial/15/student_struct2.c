#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct student {
	int number;
	char name[10];
	double grade;
};


int main(void)
{
	struct student s;
	// 입력
	printf("학번을 입력하세요 : ");
	scanf("%d", &s.number);
	printf("이름을 입력하세요 : ");
	scanf("%s", s.name); // 배열은 자체로 포인터의 의미를 갖기에 &를 넣을 필요 X
	printf("학점을 입력하세요 : ");
	scanf("%lf", &s.grade);
	// 출력
	printf("\n학번 : %d\n", s.number);
	printf("이름 : %s\n", s.name);
	printf("학점 : %.1lf", s.grade);

	return 0;
}