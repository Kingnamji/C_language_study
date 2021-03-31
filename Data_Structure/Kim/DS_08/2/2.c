#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct listNode {
	int data;
	struct listNode* link;
}listNode;
listNode* first = NULL;

void printList(listNode* first); // list를 출력해주는 함수
void insert(listNode** first, listNode* x, int data_f);
void delete(listNode** first, listNode* trail, listNode* x);
void locate(listNode* first, listNode** x, int data_f); // 정렬을 위해 위치를 잡아줄 함수
int main()
{
	FILE* fp;
	int data_f; // 파일에서 값을 정수를 받아올 변수
	listNode* x, * trail;
	listNode* p1, * p2;

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);

	fscanf_s(fp, "%d", &data_f);
	// 데이터를 받고 정렬해서 계속 연결
	while (!feof(fp)) {
		locate(first, &x, data_f);
		insert(&first, x, data_f);
		fscanf_s(fp, "%d", &data_f);
	}
	// 홀수 삭제를 위해 listPointer를 준비
	trail = NULL;
	p1 = first;
	p2 = first;

	printf("The ordered list contains:\n");
	printList(first);

	while (p1 != NULL)
	{
		if (p1->data % 2 != 0) {
			x = p1;
			delete(&first, trail, x);
			if (p2 != first) {
				trail = NULL;
				p1 = first;
				p2 = first;
			}
			else {
				p1 = trail->link;
			}
		}
		else {
			trail = p1;
			p1 = p1->link;
		}
	}

	printf("\nAfter deleting nodes with odd value\n\n");
	printf("The ordered list contains:\n");
	printList(first);

	fclose(fp);

	return 0;
}

void printList(listNode* first)
{
	int i;

	for (i = 1; first; first = first->link, i++) {
		printf("(%p, %4d, %p ) ", first, first->data, first->link);
		if ((i % 3) == 0)
			printf("\n");
	}

}

void delete(listNode** first, listNode* trail, listNode* x)
{
	if (trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void insert(listNode** first, listNode* x, int data_f)
{
	listNode* temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data_f;
	if (*first == NULL) {
		temp->link = NULL;
		*first = temp;
	}
	else {
		if (x == NULL) {
			temp->link = *first;
			*first = temp;
		}
		else {
			temp->link = x->link;
			x->link = temp;
		}
	}
}

void locate(listNode* first, listNode** x, int data_f)
{
	listNode* p1 = first;
	listNode* p2 = first;

	if (first == NULL) {
		*x = first;
	}
	else
	{
		for (; p2; p2 = p2->link)
		{
			if (data_f > p2->data)
			{
				p1 = p2;
				*x = p1;
			}
			else
			{
				if (first == p1)
					*x = NULL;
				break;
			}
		}
	}
}