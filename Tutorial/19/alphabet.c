#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* pc = NULL;
	int i = 0;
	pc = (char*)malloc(100 * sizeof(char)); //char 가 100개 들어갈 수 있는 공간을 만든다.

	if (pc == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
		exit(1);
	}
	//pc가 가르키는 포인터를 1씩 증가시키며 알파벳 소문자를 삽입한다.
	for (i = 0; i < 26; i++)
	{
		*(pc + i) = 'a' + i;
	}
	*(pc + i) = 0; // 아스키 코드에서 0은 NULL을 의미한다.

	printf("%s\n", pc);
	free(pc);
	return 0;
}