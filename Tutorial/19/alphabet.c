#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* pc = NULL;
	int i = 0;
	pc = (char*)malloc(100 * sizeof(char)); //char �� 100�� �� �� �ִ� ������ �����.

	if (pc == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	}
	//pc�� ����Ű�� �����͸� 1�� ������Ű�� ���ĺ� �ҹ��ڸ� �����Ѵ�.
	for (i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
	*(pc + i) = 0; // �ƽ�Ű �ڵ忡�� 0�� NULL�� �ǹ��Ѵ�.

	printf("%s\n", pc);
	free(pc);
	return 0;
}