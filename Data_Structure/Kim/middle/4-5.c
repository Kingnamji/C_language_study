#include <stdio.h>
#include <string.h>
#define MAX_STRING_SIZE 100
#define MAX_PATTERN_SIZE 100


int pmatch(char*, char*);
void fail(char*);

int failure[MAX_PATTERN_SIZE];

void main()
{
	int i, result;
	
	char string[MAX_STRING_SIZE];
	char pat[MAX_PATTERN_SIZE];

	printf("문자열을 입력하세요 : ");
	gets_s(string, sizeof(string));
	printf("비교할 패턴을 입력하세요 : ");
	scanf_s("%s", pat, sizeof(pat));

	fail(pat);
	printf("pat의 위치 정보 값\n");
	for (i = 0; i < strlen(pat); i++) {
		printf("failure[%d]=%5d  ", i, failure[i]);
		if (i % 5 == 4)
			printf("\n");
	}

	result = pmatch(string, pat);

	if (result == -1)
		printf("패턴이 없습니다..");
	else
		printf("문자열 %d 번째부터 패턴이 시작됨..", result);
}

int pmatch(char* string, char* pat)
{
	int i = 0, j = 0;

	int lens = strlen(string);
	int lenp = strlen(pat);

	while (i < lens && j < lenp) {
		if (string[i] == pat[j]) {
			i++; j++;
		}
		else if (j == 0) // 패턴의 처음부터 매칭해야하는 경우
			i++;
		else 
			j = failure[j - 1] + 1;
	}
	return ((j == lenp) ? (i - lenp) : -1);
}

void fail(char* pat)
{
	int i, j;
	int n = strlen(pat);

	failure[0] = -1;

	for (j = 1; j < n; j++) {
		i = failure[j - 1];
		while ((pat[j] != pat[i + 1]) && (i >= 0))
			i = failure[i];
		if (pat[j] == pat[i + 1])
			failure[j] = i + 1;
		else 
			failure[j] = -1;
	}
}