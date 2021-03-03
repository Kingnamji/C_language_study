#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;
	int c;

	fp = fopen("input.txt", "r");
	// w -> write, 쓰기 모드, r -> read, 읽기 모드
	if (fp == NULL)
	{
		printf("파일 열기에 실패했습니다.\n");
	}
	else
	{
		printf("파일 열기에 성공했습니다.\n");
	}
	
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}

	fclose(fp);

	return 0;
}