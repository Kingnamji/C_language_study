#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi; // Pointer Integer
	pi =  (int*)malloc(sizeof(int)); // malloce = �޸𸮸� �Ҵ��ض�.

	if (pi == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	}
	*pi = 100;
	printf("%d\n", *pi);
	/* ���� �޸𸮸� ����� ���Ŀ��� �ݵ�� �ش� �޸𸮸� ��ȯ�Ѵ�. 
	free = �޸𸮸� �Ҵ� ���� (�ݳ�) */
	free(pi);
	return 0;
}