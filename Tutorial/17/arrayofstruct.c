#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

struct student
{
	int number;
	char name[20];
	double grade;
};

int main(void)
{
	struct student list[SIZE];
	int i;
	
	for (i = 0; i < SIZE; i++)
	{
		printf("학번을 입력하세요 : ");
		scanf("%d", &list[i].number);
		printf("이름을 입력하세요 : ");
		scanf("%s", &list[i].name);
		printf("학점을 입력하세요 : ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("학번 : %d , 이름 : %s, 학점 : %.lf\n", list[i].number, list[i].name, list[i].grade);
	}

	return 0;
}