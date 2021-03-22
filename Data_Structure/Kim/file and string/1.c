#include <stdio.h>
// gets_s, strtok_s
/*
char *gets_s(char *buffer, size_t sizeInCharacters);
매개 변수 : 버퍼 (입력 문자열에 대한 스토리지 위치)
			sizeInCharacters (버퍼의 크기)

반환 값 : 성공하면 버퍼를 반환, NULL포인터는 오류 또는 파일 끝 조건을 나타낸다.


char* strtok_s(char* str, const char* delimiters, char* context);
매개 변수 : str (찾을 토큰을 포함 하는 문자열)
			구분 기호 (사용할 구분 기호 문자 집합)
			context (함수 호출 간의 위치 정보를 저장 하는 데 사용)
반환 값 : Str 에서 찾은 다음 토큰에 대 한 포인터를
		반환. 더 이상 토큰을 찾을 수 없는 경우 NUL 을 반환
tok = strtok_s(input, delimiter, &next_str);
	input에서 구분자를 기준으로 나눈 다음, 첫 번째 단어는 tok 가
	가르키고, 나머지 부분은 next_str이 가르킴. 구분자는 출력 안함.
	delimiter는 스트링으로 주어야 하며, “ ,1\n”으로 주어지면, 공백, ‘,’, ‘\n’는 모두 구분자임.

*/
int main(void)
{	
	char line[21]; // room for 20 chars + '\0'
	char input[80] = "Korea, is very, wonderful country";
	char* tok, * next_str;
	printf("input : ");
	gets_s(line, 20);
	printf("The line entered was : %s\n", line);

	tok = strtok_s(input, ",", &next_str);
	printf("tok = %s\nnext_str = %s\n", tok, next_str);

	return 0;
}