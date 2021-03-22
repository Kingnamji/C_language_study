#include <stdio.h>
#define MAX_LEN 100

int main(void)
{
	FILE* fp;
	char line[MAX_LEN], * result;

	fopen_s(&fp, "input.txt", "r");
	while (1)
	{
		if ((result = fgets(line, MAX_LEN, fp)))
			printf("The string is %s\n", result);
		else
			break;
	}
	fclose(fp);
}