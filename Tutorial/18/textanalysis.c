#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE* fp;
	char fname[256];
	char buffer[256];
	char word[256];
	int line = 0;

	printf("���� �̸��� �Է��ϼ��� : ");
	scanf("%s", fname);
	
	printf("Ž���� �ܾ �Է��ϼ��� : ");
	scanf("%s", word);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname);
		return 0;
	}

	while (fgets(buffer, 256, fp))
	{
		line++;
		if (strstr(buffer, word))
		{
			printf("���� %d | �ܾ� %s��(��) �߰ߵƽ��ϴ�.\n", line, word);
		}
	}
	
	fclose(fp);
	return 0;
}