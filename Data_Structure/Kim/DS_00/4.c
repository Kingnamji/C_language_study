#include <stdio.h>
#include <ctype.h>

int check(char);

int main()
{
	char s[500], *p;
	printf("문자열 입력 : ");
	gets_s(s, sizeof(s)); // s에 문자열 입력
	p = s;
	while (*p != '\0')
	{
		if(check(*p))
			*p = toupper(*p);
		p++;
	}
	printf("자음만 대문자로 변환 결과 : %s \n", s);
}

int check(char ch)
{
	int i;
	char vowel[] = { 'a', 'e', 'i', 'o', 'u' };
	for (i = 0; i < 5; i++)
		if (ch == vowel[i])
			return 0;
	return 1;
}
