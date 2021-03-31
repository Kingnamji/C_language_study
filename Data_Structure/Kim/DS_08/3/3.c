#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// linked list
typedef struct listNode *listPointer;
typedef struct listNode {
	char name[10];
	char job[20];
	char gen[5];
	listPointer link;
}listNode;
listPointer first = NULL;

// void find(listPointer first, listPointer *x, listNode data);					// find insert position
void insert(listPointer *first, listPointer *x, listNode data);				// insert data into ordered list first after node x
// void delete( listPointer *first, listPointer trail, listPointer x); // 주의 : delete 는 c++ 의 keyword!, 소스파일 확장자가 cpp이면 컴파일 에러임
void printList(listPointer first);

int main(void)
{
	listNode data_n;


	listPointer trail, cur, man, woman, man_e, woman_e;
	
	// data input for each node
	FILE *fp;	

	fopen_s(&fp, "input.txt", "r");
	if( fp == NULL )
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}
	
	trail = NULL;
	fscanf_s(fp, "%s%s%s", data_n.name, 10, data_n.job, 20, data_n.gen, 5);		
	while( !feof(fp) )
	{
//		find(first, &x, data);		// find insert position
		insert(&first, &trail , data_n);		// insert data first after node x. 
		fscanf_s(fp, "%s%s%s", data_n.name, 10, data_n.job, 20, data_n.gen, 5);
	}
	insert(&first, &trail, data_n);		// insert data first after node x. 
	printf("전체 리스트 \n");
	printList(first);	

	man_e = woman_e = NULL;
	cur = first;
	man = woman = NULL;

	while (cur) {
		if (!strcmp(cur->gen, "남자")) {
			if (man)
				man_e->link = cur;				
			else
				man = cur;
			man_e = cur;
		}
		else {
			if (woman)
				woman_e->link = cur;
			else
				woman = cur;
			woman_e = cur;
		}
		cur = cur->link;
	}
	man_e->link = NULL;
	woman_e->link = NULL;

	printf("남자 리스트 \n");
	printList(man);
	printf("\n여자 리스트 \n");
	printList(woman);
	
	fclose(fp);
	
	return 0;
}


void insert(listPointer *first, listPointer *x, listNode n_data)
{ /* insert a new node with a data into the chain first after node x */
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	strcpy_s(temp->name, 10, n_data.name);
	strcpy_s(temp->job, 20, n_data.job);
	strcpy_s(temp->gen, 5, n_data.gen);

	if(*first == NULL)  
	{ // add to empty list
		temp->link = NULL;
		*first = temp;
		*x = temp;
	}
	else 
	{ // add to non-empty list
			
		if ( x == NULL ) 
		{ // as a first node
			temp->link = *first;
			*first = temp;
			*x = temp;
		}
		else 
		{ 
			temp->link = (*x)->link;
			(*x)->link = temp;
			*x = temp;
		}
/*		
		temp->link = x->link;
		x->link = temp;
*/

	}
}


void printList(listPointer listp)
{
	int count;
//	printf("The ordered list contains: \n");
	for (count = 1 ; listp; listp = listp->link, count++)
		printf("(%p, %s, %s, %s %p )   %s", listp, listp->name, listp->job, listp->gen, listp->link, count%2 ? "" : "\n");
	printf("\n");
}