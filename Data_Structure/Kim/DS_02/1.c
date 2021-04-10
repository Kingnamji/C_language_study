#include <stdio.h>
#include <stdlib.h>


int *func1(void)
{
	int *pNum;
	
	if (!(pNum = (int*)malloc(sizeof(int))))
		exit(0);
	 else
		*pNum = 10;
	return pNum;
}

int func2(int  *pNum)
{
	*pNum = 100;
	return 0;
}

int func3(int  **ppNum)
{
	**ppNum = 200;
	return 0;
}

char* func4(int size)
{
	char *ch;

	if (!(ch = (char*)malloc(sizeof(char)*size)))
		exit(0);
	printf("\n입력할 문자열 : ");
	gets(ch); // 공백도 받을 수 있다.
	//scanf_s("%s", ch, size); 이러면 공백 처리 x
	return ch;

}

int main(void)
{


	int  *pNum;
	char* pChar;
	
	pNum = func1();  // int 크기 만큼 동적할당 받아 10을 지정 후 정수형 포인터 리턴
	printf("%d\n", *pNum);

	func2(pNum);// pNum이 가리키는 것을 100으로 수정
	printf("%d\n", *pNum); 

	func3(&pNum); // pNum이 가리키는 것을 200으로 수정
	printf("%d\n", *pNum);

	pChar = func4(100); // pChar 은 100byte 할당 받은 메모리에 키보드로부터 입력 받은 문자열 저장
	printf("pChar contents = % s\n", pChar);

	free(pNum);
	free(pChar);

	return 0;
}
