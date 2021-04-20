#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100

int find(char* string, char* pat);

int main(void)
{
	char a[100], b[100];
	int result;
	printf("���ڿ��� �Է��ϼ��� : ");
	gets_s(a, sizeof(a));
	printf("���� ������ �Է��ϼ��� : ");
	gets_s(b, sizeof(b));

	result = find(a, b);

	if (result == -1)
		printf("������ ã�� ���߽��ϴ�.\n");
	else
		printf("���ڿ� %d��°���� ������ ���۵�..\n", result);

	return 0;
}



int find(char* string, char* pat)
{
	int i, j = 0, start = 0;
	int lasts = strlen(string) - 1;
	int lastp = strlen(pat) - 1;
	int endmatch = lastp;

	for (i = 0; endmatch <= lasts; endmatch++, start++) {

		if (string[endmatch] == pat[lastp])
			for (j = 0, i = start; j < lastp && string[i] == pat[j]; i++, j++);
		if (j == lastp)
			return start;
	}
	return -1;
}

