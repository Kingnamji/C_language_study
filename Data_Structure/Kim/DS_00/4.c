#include <stdio.h>
#include <ctype.h>

int check(char);

int main()
{
	char s[500], *p;
	printf("���ڿ� �Է� : ");
	gets_s(s, sizeof(s)); // s�� ���ڿ� �Է�
	p = s;
	while (*p != '\0')
	{
		if(check(*p))
			*p = toupper(*p);
		p++;
	}
	printf("������ �빮�ڷ� ��ȯ ��� : %s \n", s);
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
