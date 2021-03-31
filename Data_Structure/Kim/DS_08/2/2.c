#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !( (p) = malloc( s ) ) ){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

// linked list
typedef struct listNode {
	int data;
	struct listNode * link;
}listNode;
listNode *first = NULL;

void find(listNode *first, listNode **x, int data);				// find insert position
void insert(listNode **first, listNode *x, int data);				// insert data into ordered list first after node x
void delete(listNode **first, listNode *trail, listNode *x); // 주의 : delete 는 c++ 의 keyword!, 소스파일 확장자가 cpp이면 컴파일 에러임
void printList(listNode *first);

int main(void)
{
	int data;
	listNode *x, *trail, *curr, *ffirst;

	// data input for each node
	FILE *fp;
	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%d", &data);
	while (!feof(fp))
	{
		find(first, &x, data);		// find insert position
		insert(&first, x, data);		// insert data first after node x. 
		fscanf_s(fp, "%d", &data);
	}
	printList(first);

	curr = ffirst = first;
	trail = NULL;

	while (curr != NULL)
	{
		if (curr->data % 2) {
			x = curr;
			delete(&first, trail, x);
			if (ffirst != first) {
				trail = NULL;
				curr = first;
				ffirst = first;
			}
			else
				curr = trail->link;

		}
		else
		{
			trail = curr;
			curr = curr->link;
		}
	}

	printf("\nAfter deleting nodes with odd value \n\n");
	printList(first);

	fclose(fp);

	return 0;
}

void find(listNode *first, listNode **x, int data)
{ /* *x is the position of insert  */
	listNode *pre = first;
	listNode *trav = first;

	if ( first == NULL )
	{ // empty list
		*x = first;
	}
	else 
	{ // non-empty list
		for ( ; trav; trav = trav->link)
		{  	
			if( data > trav->data)
			{
				pre = trav;
				*x = pre;
			}
			else
			{					
				if ( first == pre )
					*x = NULL;
				break;
			}
		}
	}
}

void insert(listNode **first, listNode *x, int data)
{ /* insert a new node with a data into the chain first after node x */
	listNode * temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;

	if(*first == NULL) 
	{ // add to empty list
		temp->link = NULL;
		*first = temp;
	}
	else 
	{ // add to non-empty list
		if ( x == NULL ) 
		{ // as a first node
			temp->link = *first;
			*first = temp;
		}
		else 
		{ 
			temp->link = x->link;
			x->link = temp;
		}
	}
}

void delete(listNode **first, listNode *trail, listNode *x)
{/* delete x from the list, trail is the preceding node 
	   and *first is the front of the list */
	if(trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void printList(listNode *first)
{
	int count;
	printf("The ordered list constains: \n");
	for (count = 1; first; first = first->link, count++)
	{
		printf("(%p, %4d, %p )%s", first, first->data, first->link, count % 3 ? "" : "\n");
		if (count % 10 == 0)
			printf("\n");
	}
	printf("\n");
}