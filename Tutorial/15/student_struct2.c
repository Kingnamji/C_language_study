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
	// �Է�
	printf("�й��� �Է��ϼ��� : ");
	scanf("%d", &s.number);
	printf("�̸��� �Է��ϼ��� : ");
	scanf("%s", s.name); // �迭�� ��ü�� �������� �ǹ̸� ���⿡ &�� ���� �ʿ� X
	printf("������ �Է��ϼ��� : ");
	scanf("%lf", &s.grade);
	// ���
	printf("\n�й� : %d\n", s.number);
	printf("�̸� : %s\n", s.name);
	printf("���� : %.1lf", s.grade);

	return 0;
}