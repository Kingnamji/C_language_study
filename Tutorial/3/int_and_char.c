#include <stdio.h>

int main(void)
{
	char x = 'A';
	char x_2 = 65; // �ƽ�Ű �ڵ带 ����� �ʱ�ȭ
	int x_3 = 65; 

	printf("%c\n", x);

	printf("%c\n", x_2);
	printf("%c\n", x_3); // �������� %c�� ����ص� �ƽ�Ű �ڵ尪�� �ش��ϴ� ���ڰ� ���´�.

	printf("%d", x_2); // ���������� character���� ������ ��� ����

	return 0;
}