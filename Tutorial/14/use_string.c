#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char input[5] = "Love";
	char inputOne[5] = "ace";
	char inputTwo[5] = "king";
	char inputThree[10] = "Love You";
	char result[5] = "Love";

	// ���ڿ� ���̼��� , strlen()
	printf("���ڿ��� ���� : %d\n", strlen(input));

	// ���ڿ� ���ϱ�, strcmp() 
	printf("���ڿ� �� : %d\n", strcmp(inputOne, inputTwo)); // ���������� �񱳵ȴ�.
	// ���������� �����ϸ� 0, ���� ���������� ������ -1, �ڰ� ������ 1

	// ���ڿ� �����ϱ�, strcpy()
	strcpy(result, inputThree); // result�ȿ� inputThree�� ī�ǰ���
	// result�� �迭 ũ�Ⱑ �۾Ƶ� strcpy�� ���������� �����͸� �̿��ϱ⶧���� ���簡 �����ϴ�.
	printf("���ڿ� ���� : %s\n", result);
	return 0;

}