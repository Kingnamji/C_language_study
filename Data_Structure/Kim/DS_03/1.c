#include <stdio.h>
#include <stdlib.h>

int* make1dArray(int);

#define MALLOC(p,s) \
	if (!(p = malloc(s))){\
		exit(1);\
	}

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

	free(ipp);

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
