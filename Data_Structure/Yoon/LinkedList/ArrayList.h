#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1 // ��
#define FALSE 0 // ����

# define LIST_LEN 100 // ����Ʈ ���� (�迭�� �̿�)
typedef int LData;

typedef struct __ArrayList // �迭��� ����Ʈ
{
	LData arr[LIST_LEN]; // ����Ʈ�� ������� �迭
	int numOfData; // ����� ������ ��
	int curPosition; // ������ ������ġ 
}ArrayList;

typedef ArrayList List;

void ListInit(List* plist); // �ʱ�ȭ
void LInsert(List* plist, LData data); // ������ ����

int LFirst(List* plist, LData* pdata); // ù ������ ����
int LNext(List* plist, LData* pdata); // �� ��° ���� ������ ����

LData LRemove(List* plist); // ������ ������ ����
int Lcount(List* plist); // ����� �������� �� ��ȯ

#endif
