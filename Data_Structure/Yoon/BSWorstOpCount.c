#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
	int first = 0; // Ž�� ����� ���� �ε��� ��
	int last = len - 1; // Ž�� ����� ������ �ε��� ��
	int mid;
	int opCount = 0; // ���� Ƚ���� ���

	while (first <= last)
	{
		mid = (first + last) / 2; // Ž�� ����� �߾��� ã�´�.

		if (target == ar[mid]) // �߾ӿ� ����� ���� Ÿ���̶��
		{
			return mid; // Ž�� �Ϸ�
		}
		else // Ÿ���� �ƴ϶�� Ž�� ����� ������ ���δ�.
		{
			if (target < ar[mid])
			{
				last = mid - 1;
			}
			else
			{
				first = mid + 1;
			}
		}
		opCount += 1; // �񱳿��� Ƚ�� 1ȸ ����
	}
	printf("�񱳿���Ƚ�� : %d \n", opCount); // Ž������ �� ����Ƚ�� ���
	return -1; // ã�� ������ �� ��ȯ��
}


int main(void)
{
	int arr1[500] = { 0, }; // ��� ��� 0���� �ʱ�ȭ
	int arr2[5000] = { 0, }; // ��� ��� 0���� �ʱ�ȭ
	int arr3[50000] = { 0, }; // ��� ��� 0���� �ʱ�ȭ
	int idx;

	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n\n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n\n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n\n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	return 0;
}