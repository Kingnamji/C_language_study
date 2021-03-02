#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[5] = "Love";
	char inputOne[5] = "ace";
	char inputTwo[5] = "king";
	char inputThree[10] = "Love You";
	char result[5] = "Love";

	// 문자열 길이세기 , strlen()
	printf("문자열의 길이 : %d\n", strlen(input));

	// 문자열 비교하기, strcmp() 
	printf("문자열 비교 : %d\n", strcmp(inputOne, inputTwo)); // 사전적으로 비교된다.
	// 사전적으로 동일하면 0, 앞이 사전적으로 빠르면 -1, 뒤가 빠르면 1

	// 문자열 복제하기, strcpy()
	strcpy(result, inputThree); // result안에 inputThree를 카피가능
	// result의 배열 크기가 작아도 strcpy는 내부적으로 포인터를 이용하기때문에 복사가 가능하다.
	printf("문자열 복사 : %s\n", result);
	return 0;

}