#include <stdio.h>

#define MALLOC(p,s)\
	if ( !((p) = malloc(s)) ){\
		exit(1);\
}

int* make1dArray(int num);

int main(void)
{
	int* ipp;
	int i, num;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++) {
		printf("ipp[%2d] = %2d ", i, ipp[i]);
		if ((i % 5) == 4)
			printf("\n");
	}

	free(ipp);

	return 0;
}

int* make1dArray(int num) {
	int* ary;
	int i;

	MALLOC(ary, sizeof(int) * num);

	for (i = 0; i < num; i++) {
		*(ary + i) = rand() % 100;
	}

	return ary;
}