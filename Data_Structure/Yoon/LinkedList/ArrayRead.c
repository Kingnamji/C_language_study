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
		printf("자연수 입력 : ");
		scanf("%d", &readData);

		if (readData < 1) // stop 조건
			break;

		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; i++) {
		printf("%3d", arr[i]);
	}

	return 0;
}