#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 0 �� �ƴ� ��� ���� ���̴�.


int main(void)
{
	char o;
	int x, y;
	
	while (1)
	{
		printf("������ �Է��ϼ��� : ");
		// �Է� ���� �ڷ����� ���� %d, %c, %f, %lf ���� �پ��� ������ ����ؾ� �Ѵ�.
		scanf("%d %c %d", &x, &o, &y); // ���� �ȿ� Ư���� ���� ������ �� �ִ�.
		if (o == '+')
		{
			printf("%d %c %d = %d \n", x, o, y, x + y);
		}
		else if (o == '-')
		{
			printf("%d %c %d = %d \n", x, o, y, x - y);
		}
		else if (o == '*')
		{
			printf("%d %c %d = %d \n", x, o, y, x * y);
		}
		else if (o == '/')
		{
			printf("%d %c %d = %d \n", x, o, y, x / y);
		}
		else if (o == '%')
		{
			printf("%d %c %d = %d \n", x, o, y, x % y);
		}
		else
		{
			printf("�Է��� �߸��ƽ��ϴ�.\n");
		}
		getchar(); // EnterŰ�� �Է����� ���� �ֱ� ������ ���۸� ó�����ش�.
		printf("���α׷��� �����Ͻðڽ��ϱ�? (y/n)");
		scanf("%c", &o);
		if (o == 'n' || o == 'N')
		{
			continue;
		}
		else if (o == 'y' || o == 'Y')
		{
			break;
		}
		else
		{
			printf("�Է��� �߸��ƽ��ϴ�.\n");
		}
	}
	
	return 0;
}