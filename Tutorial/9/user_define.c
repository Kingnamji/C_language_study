#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ����� ���� �Լ� ���� ���� �Լ����� ��� �˰����� ó���Ѵٸ�
�̴� �۾��� ȿ������ ���Ͻ�Ų��. 
���� �Լ��� ������ ���μ� ���� �����ǰ� ���ϵ� �� �ִٴ� ������ �ִ�.*/

// ���� ����(���α׷� ��𼭳� ���� ������ ����) �����
int hour;
int minute;
int minuteAdd;

//��ȯ�� �Լ��̸�(�Ű�����) ��
void counter()
{
	minute += minuteAdd;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
	// ���������� �ֱ⶧���� return�� �ʿ����.
	//	return minute;
}

int main(void)
{
	printf("�ø� �Է��ϼ��� : ");
	scanf("%d", &hour);
	printf("���� �Է��ϼ��� : ");
	scanf("%d", &minute);
	printf("���� ���� �Է��ϼ���: ");
	scanf("%d", &minuteAdd);
	counter();
	printf("������ �ð��� %d�� %d�� �Դϴ�.\n", hour, minute);

	return 0;
}