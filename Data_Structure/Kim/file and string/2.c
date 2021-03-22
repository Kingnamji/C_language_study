#include <stdio.h>

/*
	strcmp() : 두 개의 스트링을 비교
	int strcmp(const char *string1, const char *string2);
	매개 변수 : string1, string2(비교할 NULL 종료 문자열)

	반환 값
	값 문자열 1과 문자열 2의 관계
		<0 string1이 문자열2보다 작음
		0 string1은 문자열2와 동일
		>0 string1이 문자열2보다 큼

	sscanf_s() : 스트링에서 원하는 만큼만 문자열을 가져옴.
	int sscanf_s(const char *buffer, const char *format[, argument ].);

	매개 변수 : 버퍼(저장된 데이터)
	format : 형식 컨트롤 문자열.
	argument : 선택적 인수

	반환 값
	이러한 각 함수는 모두 성공적으로 변환되고 할당된 필드 수를 반환, 이때 읽혀졌지만 할당되지 않은
	필드는 반환 값에 포함되지 않는다. 반환 값이 0이면 할당된 필드가 없음을 나타낸다.
*/

int main(void)
{
	char st1[80], st2[80];
	char input[80] = "Korea, is very, wonderful country";
	char* tok, * next_str;

	tok = strtok_s(input, ",", &next_str);
	printf("tok = %s\nnext_str = %s\n", tok, next_str);
	sscanf_s(input + strlen(tok) + 1, "%s%s", st1, sizeof(st1), st2, sizeof(st2));
	printf("st1 = %s\nst2 = %s\n", st1, st2);	

	return 0;
}