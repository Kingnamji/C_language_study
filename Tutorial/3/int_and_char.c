#include <stdio.h>

int main(void)
{
	char x = 'A';
	char x_2 = 65; // 아스키 코드를 사용해 초기화
	int x_3 = 65; 

	printf("%c\n", x);

	printf("%c\n", x_2);
	printf("%c\n", x_3); // 정수형을 %c로 출력해도 아스키 코드값에 해당하는 문자가 나온다.

	printf("%d", x_2); // 마찬가지로 character형도 정수로 출력 가능

	return 0;
}