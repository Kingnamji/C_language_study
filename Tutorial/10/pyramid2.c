#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// �ݺ��Լ��� �̿��� ���� �Ƕ�̵� ����ϱ�
// �ݺ��Լ��� ���� for���� while������ �����ȴ�.

int print(int a)
{
	int i, j;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j <= i; j++)
		{ 
			printf("%d ", j + 1);
		}
		printf("\n");
	}
}


int main(void)
{
	int a;
	printf("���ڸ� �Է��ϼ���. : ");
	scanf("%d", &a);

	print(a);
	return 0;
}