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
	s.number = 20150001;
	strcpy(s.name, "ȫ�浿");
	s.grade = 4.5;
	printf("�й� : %d\n", s.number);
	printf("�̸� : %s\n", s.name);
	printf("���� : %.1lf\n", s.grade);
	return 0;
}