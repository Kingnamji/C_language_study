#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXI 100

int main()
{
	FILE* fp;
	char buf[MAXI];
	char* tok, * ntok;

	fopen_s(&fp, "input.txt", "r");
	fgets(buf, sizeof(buf), fp);
	while (1)
	{
		printf("string is: %s\n", buf);
		ntok = buf;
		while (1)
		{
			tok = strtok_s(ntok, " \n", &ntok);
			if (tok == NULL)
			{
				printf("end of line \n");
				break;
			}
			printf("tok = %s\n", tok);
		}
		if (!fgets(buf, sizeof(buf), fp))
			break;
	}
	fclose(fp);
	return 0;
}