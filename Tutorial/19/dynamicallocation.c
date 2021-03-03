#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* pi; // Pointer Integer
	pi =  (int*)malloc(sizeof(int)); // malloce = 메모리를 할당해라.

	if (pi == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	*pi = 100;
	printf("%d\n", *pi);
	/* 동적 메모리를 사용한 이후에는 반드시 해당 메모리를 반환한다. 
	free = 메모리를 할당 해제 (반납) */
	free(pi);
	return 0;
}