#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 사용자 정의 함수 없이 메인 함수에서 모든 알고리즘을 처리한다면
이는 작업의 효율성을 저하시킨다. 
또한 함수는 각각의 모듈로서 쉽게 수정되고 보완될 수 있다는 장점이 있다.*/

// 전역 변수(프로그램 어디서나 접근 가능한 변수) 만들기
int hour;
int minute;
int minuteAdd;

//반환형 함수이름(매개변수) 순
void counter()
{
	minute += minuteAdd;
	hour += minute / 60;
	minute %= 60;
	hour %= 24;
	// 전역변수가 있기때문에 return이 필요없다.
	//	return minute;
}

int main(void)
{
	printf("시를 입력하세요 : ");
	scanf("%d", &hour);
	printf("분을 입력하세요 : ");
	scanf("%d", &minute);
	printf("더할 분을 입력하세요: ");
	scanf("%d", &minuteAdd);
	counter();
	printf("더해진 시간은 %d시 %d분 입니다.\n", hour, minute);

	return 0;
}