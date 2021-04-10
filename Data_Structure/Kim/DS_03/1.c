#include <stdio.h>
#include <stdlib.h>

#define MALLOC(P, SIZE)  \
	if(!((p) = malloc(SIZE))) { \
		fprintf_s(stderr, "not allocated\n"); \
		exit(EXIT_FAILURE); \
	}
int* make1dArray(int);

int main()
{
	int *ipp;
	int i, num;

	printf("일차원 배열의 수를 입력하세요: ");
	scanf_s("%d", &num);

	ipp = make1dArray(num);
	for (i = 0; i < num; i++) {
		printf("ipp[%2d] =%2d ", i, ipp[i]);
		if ((i % 5) == 4)
			printf("\n");

		}
	return 0;
}



int* make1dArray(int R)
{
	int* p; 
	int i;

	MALLOC(p, (sizeof(int) * R)); // 원소가 포인터인 배열의 시작주소

	for (i = 0; i < R; i++)
	{
		for (i = 0; i < R; i++)
			*(p+i) = rand() % 100;
	}

	return p;
}
