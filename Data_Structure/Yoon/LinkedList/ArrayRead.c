#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;
	int i;

	while (1)
	{
		printf("�ڿ��� �Է� : ");
		scanf("%d", &readData);

		if (readData < 1) // stop ����
			break;

		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; i++) {
		printf("%3d", arr[i]);
	}

	return 0;
}