#include <stdio.h>
#include <limits.h> // 각 자료형의 limit값을 포함하고 있는 MAX, MIN을 사용하게 해주는 라이브러리

int main(void)
{
	int x = INT_MAX;
	printf("int형의 최댓값 x는 %d입니다.\n", x);
	printf("x + 1은 %d 입니다. \n", x + 1); // 오버플로가 발생해 최솟값이 나온다.

	return 0;
}