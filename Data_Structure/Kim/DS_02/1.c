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
	printf("\n�Է��� ���ڿ� : ");
	gets(ch); // ���鵵 ���� �� �ִ�.
	//scanf_s("%s", ch, size); �̷��� ���� ó�� x
	return ch;

}

int main(void)
{


	int  *pNum;
	char* pChar;
	
	pNum = func1();  // int ũ�� ��ŭ �����Ҵ� �޾� 10�� ���� �� ������ ������ ����
	printf("%d\n", *pNum);

	func2(pNum);// pNum�� ����Ű�� ���� 100���� ����
	printf("%d\n", *pNum); 

	func3(&pNum); // pNum�� ����Ű�� ���� 200���� ����
	printf("%d\n", *pNum);

	pChar = func4(100); // pChar �� 100byte �Ҵ� ���� �޸𸮿� Ű����κ��� �Է� ���� ���ڿ� ����
	printf("pChar contents = % s\n", pChar);

	free(pNum);
	free(pChar);

	return 0;
}
