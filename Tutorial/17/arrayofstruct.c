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
		printf("�й��� �Է��ϼ��� : ");
		scanf("%d", &list[i].number);
		printf("�̸��� �Է��ϼ��� : ");
		scanf("%s", &list[i].name);
		printf("������ �Է��ϼ��� : ");
		scanf("%lf", &list[i].grade);
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("�й� : %d , �̸� : %s, ���� : %.lf\n", list[i].number, list[i].name, list[i].grade);
	}

	return 0;
}