#include <stdio.h>
#include <limits.h> // �� �ڷ����� limit���� �����ϰ� �ִ� MAX, MIN�� ����ϰ� ���ִ� ���̺귯��

int main(void)
{
	int x = INT_MAX;
	printf("int���� �ִ� x�� %d�Դϴ�.\n", x);
	printf("x + 1�� %d �Դϴ�. \n", x + 1); // �����÷ΰ� �߻��� �ּڰ��� ���´�.

	return 0;
}