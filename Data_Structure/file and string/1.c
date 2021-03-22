#include <stdio.h>
// gets_s, strtok_s
/*
char *gets_s(char *buffer, size_t sizeInCharacters);
�Ű� ���� : ���� (�Է� ���ڿ��� ���� ���丮�� ��ġ)
			sizeInCharacters (������ ũ��)

��ȯ �� : �����ϸ� ���۸� ��ȯ, NULL�����ʹ� ���� �Ǵ� ���� �� ������ ��Ÿ����.


char* strtok_s(char* str, const char* delimiters, char* context);
�Ű� ���� : str (ã�� ��ū�� ���� �ϴ� ���ڿ�)
			���� ��ȣ (����� ���� ��ȣ ���� ����)
			context (�Լ� ȣ�� ���� ��ġ ������ ���� �ϴ� �� ���)
��ȯ �� : Str ���� ã�� ���� ��ū�� �� �� �����͸�
		��ȯ. �� �̻� ��ū�� ã�� �� ���� ��� NUL �� ��ȯ
tok = strtok_s(input, delimiter, &next_str);
	input���� �����ڸ� �������� ���� ����, ù ��° �ܾ�� tok ��
	����Ű��, ������ �κ��� next_str�� ����Ŵ. �����ڴ� ��� ����.
	delimiter�� ��Ʈ������ �־�� �ϸ�, �� ,1\n������ �־�����, ����, ��,��, ��\n���� ��� ��������.

*/
int main(void)
{	
	char line[21]; // room for 20 chars + '\0'
	char input[80] = "Korea, is very, wonderful country";
	char* tok, * next_str;
	printf("input : ");
	gets_s(line, 20);
	printf("The line entered was : %s\n", line);

	tok = strtok_s(input, ",", &next_str);
	printf("tok = %s\nnext_str = %s\n", tok, next_str);

	return 0;
}