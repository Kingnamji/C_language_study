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
		puts("저장이 불가능합니다.");
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

LData LRemove(List* plist) // 최근 조회가 이뤄진 데이터를 삭제
{
	int rpos = plist->curPosition; // 최근 조회된 데이터의 위치
	int num = plist->numOfData; // 저장된 데이터 수
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++) 
		plist->arr[i] = plist->arr[i + 1]; // 한 칸씩 당김

	(plist->numOfData)--; // 데이터가 하나 줄었음
	(plist->curPosition)--; // 참조 위치도 하나 빼줌
	return rdata; // 삭제한 데이터는 반환
}

int Lcount(List* plist)
{
	return plist->numOfData;
}