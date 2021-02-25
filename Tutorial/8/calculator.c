#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 0 이 아닌 모든 수는 참이다.


int main(void)
{
	char o;
	int x, y;
	
	while (1)
	{
		printf("수식을 입력하세요 : ");
		// 입력 받을 자료형에 따라서 %d, %c, %f, %lf 등의 다양한 문법을 사용해야 한다.
		scanf("%d %c %d", &x, &o, &y); // 변수 안에 특정한 값을 삽입할 수 있다.
		if (o == '+')
		{
			printf("%d %c %d = %d \n", x, o, y, x + y);
		}
		else if (o == '-')
		{
			printf("%d %c %d = %d \n", x, o, y, x - y);
		}
		else if (o == '*')
		{
			printf("%d %c %d = %d \n", x, o, y, x * y);
		}
		else if (o == '/')
		{
			printf("%d %c %d = %d \n", x, o, y, x / y);
		}
		else if (o == '%')
		{
			printf("%d %c %d = %d \n", x, o, y, x % y);
		}
		else
		{
			printf("입력이 잘못됐습니다.\n");
		}
		getchar(); // Enter키가 입력으로 남아 있기 때문에 버퍼를 처리해준다.
		printf("프로그램을 종료하시겠습니까? (y/n)");
		scanf("%c", &o);
		if (o == 'n' || o == 'N')
		{
			continue;
		}
		else if (o == 'y' || o == 'Y')
		{
			break;
		}
		else
		{
			printf("입력이 잘못됐습니다.\n");
		}
	}
	
	return 0;
}