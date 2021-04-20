#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if( !((p) = malloc(s)) ){\
		exit(1);\
	}

int* func1();
void func2(int* pNum);
void func3(int** pNum);
char* func4(int num);

int main(void)
{
	int* pNum;
	char* pChar;

	pNum = func1();
	printf("%d\n", *pNum);

	func2(pNum);
	printf("%d\n", *pNum);
	
	func3(&pNum);
	printf("%d\n", *pNum);

	pChar = func4(100);

	printf("pChar contents = %s\n", pChar);

	free(pNum);
	free(pChar);

	return 0;
}

int* func1() {
	int* p;
	MALLOC(p, sizeof(int));
	*p = 10;

	return p;
}

void func2(int *pNum) {
	*pNum = 100;
}

void func3(int** pNum) {
	**pNum = 200;
}

char* func4(int num) {
	char* c;

	MALLOC(c, num);
	
	printf("입력할 문자열 : ");
	scanf_s("%s", c, num);

	return c;
}