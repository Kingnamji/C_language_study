#include <stdio.h>

/*
	strcmp() : �� ���� ��Ʈ���� ��
	int strcmp(const char *string1, const char *string2);
	�Ű� ���� : string1, string2(���� NULL ���� ���ڿ�)

	��ȯ ��
	�� ���ڿ� 1�� ���ڿ� 2�� ����
		<0 string1�� ���ڿ�2���� ����
		0 string1�� ���ڿ�2�� ����
		>0 string1�� ���ڿ�2���� ŭ

	sscanf_s() : ��Ʈ������ ���ϴ� ��ŭ�� ���ڿ��� ������.
	int sscanf_s(const char *buffer, const char *format[, argument ].);

	�Ű� ���� : ����(����� ������)
	format : ���� ��Ʈ�� ���ڿ�.
	argument : ������ �μ�

	��ȯ ��
	�̷��� �� �Լ��� ��� ���������� ��ȯ�ǰ� �Ҵ�� �ʵ� ���� ��ȯ, �̶� ���������� �Ҵ���� ����
	�ʵ�� ��ȯ ���� ���Ե��� �ʴ´�. ��ȯ ���� 0�̸� �Ҵ�� �ʵ尡 ������ ��Ÿ����.
*/

int main(void)
{
	char st1[80], st2[80];
	char input[80] = "Korea, is very, wonderful country";
	char* tok, * next_str;

	tok = strtok_s(input, ",", &next_str);
	printf("tok = %s\nnext_str = %s\n", tok, next_str);
	sscanf_s(input + strlen(tok) + 1, "%s%s", st1, sizeof(st1), st2, sizeof(st2));
	printf("st1 = %s\nst2 = %s\n", st1, st2);	

	return 0;
}