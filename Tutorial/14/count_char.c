#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char input[1001];
	gets(input); // input�̶�� char�ȿ� Enter�� �Է��� �� ���� ���ڿ��� �Է�
	int count = 0;

	while (input[count] != '\0') // gets�� �Է��� ���� �� ���ڿ��� ���������� NULL���� ����.
	{
		count++;
	}
	printf("�Է��� ���ڿ��� ���̴� %d�Դϴ�.\n", count);
	printf("�Է��� ���ڿ�: %s", input); // %s ���� NULL ���� ���������� �ϳ��� ���� ������ ���
	return 0;
}