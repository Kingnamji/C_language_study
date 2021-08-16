#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) 
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

intLNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) // �ֱ� ��ȸ�� �̷��� �����͸� ����
{
	int rpos = plist->curPosition; // �ֱ� ��ȸ�� �������� ��ġ
	int num = plist->numOfData; // ����� ������ ��
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++) 
		plist->arr[i] = plist->arr[i + 1]; // �� ĭ�� ���

	(plist->numOfData)--; // �����Ͱ� �ϳ� �پ���
	(plist->curPosition)--; // ���� ��ġ�� �ϳ� ����
	return rdata; // ������ �����ʹ� ��ȯ
}

int Lcount(List* plist)
{
	return plist->numOfData;
}