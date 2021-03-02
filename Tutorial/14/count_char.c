#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char input[1001];
	gets(input); // input이라는 char안에 Enter를 입력할 때 까지 문자열을 입력
	int count = 0;

	while (input[count] != '\0') // gets의 입력이 끝난 후 문자열의 나머지에는 NULL값이 들어간다.
	{
		count++;
	}
	printf("입력한 문자열의 길이는 %d입니다.\n", count);
	printf("입력한 문자열: %s", input); // %s 또한 NULL 값을 만날때까지 하나의 문자 각각을 출력
	return 0;
}