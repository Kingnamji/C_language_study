#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE* fp = NULL;
	int c;

	fp = fopen("input.txt", "r");
	// w -> write, ���� ���, r -> read, �б� ���
	if (fp == NULL)
	{
		printf("���� ���⿡ �����߽��ϴ�.\n");
	}
	else
	{
		printf("���� ���⿡ �����߽��ϴ�.\n");
	}
	
	while ((c = fgetc(fp)) != EOF)
	{
		putchar(c);
	}

	fclose(fp);

	return 0;
}