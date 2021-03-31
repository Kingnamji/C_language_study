#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20
#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct listNode* listPointer;
typedef struct listNode {
	char name[MAX_LEN];
	char be[MAX_LEN];
	char sex[MAX_LEN];
	listPointer link;
}listNode;
listPointer first = NULL;

void printList(listPointer first); // list를 출력해주는 함수
void insert(listPointer* first, listPointer* x, listNode data_f);

int main()
{
	FILE* fp;
	listNode data_f; // 파일에서 값을 받아올 구조체
	listPointer trail, man, woman;
	listPointer p1, temp1, temp2;
	man = NULL;
	woman = NULL;
	temp1 = NULL;
	temp2 = NULL;
	trail = NULL;

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);

	fscanf_s(fp, "%s%s%s", data_f.name, MAX_LEN, data_f.be, MAX_LEN, data_f.sex, MAX_LEN);
	// 데이터를 받고 연결
	while (!feof(fp)) {
		insert(&first, &trail, data_f);
		fscanf_s(fp, "%s%s%s", data_f.name, MAX_LEN, data_f.be, MAX_LEN, data_f.sex, MAX_LEN);
	}
	insert(&first, &trail, data_f);
	p1 = first;

	printf("전체 리스트\n");
	printList(first);
	
	while (p1 != NULL)
	{
		if (strcmp(p1->sex, "남자") == 0) {
			if (man) {
				temp1->link = p1;
			}
			else {
				man = p1;
			}
			temp1 = p1;
		}
		else {
			if (woman)
				temp2->link = p1;
			else {
				woman = p1;
			}
			temp2 = p1;
		}
		p1 = p1->link;
	}
	temp1->link = NULL;
	temp2->link = NULL;

	printf("\n남자 리스트\n");
	printList(man);
	printf("\n\n여자 리스트\n");
	printList(woman);
	
	fclose(fp);

	return 0;
}

void printList(listPointer first)
{
	int i;

	for (i = 1; first; first = first->link, i++) {
		printf("(%p, %s, %s, %s, %p )  ", first, first->name, first->be, first->sex, first->link);
		if ((i % 2) == 0)
			printf("\n");
	}
}

void insert(listPointer* first, listPointer *x, listNode data_f)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	strcpy_s(temp->name, MAX_LEN, data_f.name);
	strcpy_s(temp->be, MAX_LEN, data_f.be);
	strcpy_s(temp->sex, MAX_LEN, data_f.sex);

	if (*first == NULL) {
		temp->link = NULL;
		*first = temp;
		*x = temp;
	}
	else {
		if (x == NULL) {
			temp->link = *first;
			*first = temp;
			*x = temp;
		}
		else {
			temp->link = (*x)->link;
			(*x)->link = temp;
			*x = temp;
		}
	}
}