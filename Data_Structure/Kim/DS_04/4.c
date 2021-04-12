#include <stdio.h>
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100
int nfind(char *string, char *pat)
{ /* Match the last character in the pattern first, then match it from the beginning. */
	int i, j=0, start = 0;
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	for (i = 0; endmatch <= lasts; endmatch++, start++) {
		if (string[endmatch] == pat[lastp])
			for (j = 0, i = start; j< lastp && string[i] == pat[j]; i++, j++);
		if (j == lastp)
			return start;    /* success */
	}
	return -1;
}

void main()
{
	char a[100], b[100];
	int st;
	printf("���ڿ��� �Է��ϼ��� : ");
//	scanf_s("%s", a, sizeof(a));
	gets_s(a, sizeof(a));
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%s", b, sizeof(b));
	st = nfind(a, b);
	if (st == -1)
		printf("������ �����ϴ�..");
	else
		printf("���ڿ� %d ��°���� ������ ���۵�..\n", st);
}