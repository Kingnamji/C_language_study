#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct listNode* listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

void insert(listPointer* first, int data);
void delete(listPointer* first, listPointer trail, listPointer x);
void printList(listPointer first);

int main(void)
{
	FILE* fp;
	int data_f;
	listPointer x, trail, p1, p2;
	x = NULL;

	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);
	
	fscanf_s(fp, "%d", &data_f);
	while (!feof(fp))
	{
		insert(&first, data_f);
		fscanf_s(fp, "%d", &data_f);
	}
	printList(first->link);

	if (first)
		p1 = first->link;
	else
	{
		exit(1);
	}

	trail = first;
	p2 = trail;
	
	while (p1 != NULL)
	{
		if (p1->data % 2) {
			x = p1;
			p1 = p1->link;

			delete(&first, trail, x);

			if (p2 != first)
				break;
		}
		else
		{
			trail = p1;
			p1 = p1->link;
		}
		if (trail == first)
			break;
	}

	printf("\nAfter deleting nodes with odd value \n\n");
	printList(first->link);

	fclose(fp);

	return 0;
}

void printList(listPointer first)
{
	int i;
	listPointer temp;
	temp = first;
	printf("The Circularly Linked List contains: \n");
	for (i = 1; first; i++) {
		printf("(%p, %4d, %p ) ", first, first->data, first->link);
		if (i % 3 == 0)
			printf("\n");

		first = first->link;

		if (temp == first)
			break;
	}
	printf("\n");
}

void insert(listPointer* first, int data)
{ 
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = data;

	if (*first == NULL)
	{
		temp->link = temp;
		*first = temp;
	}
	else
	{
		temp->link = (*first)->link;
		(*first)->link = temp;
		*first = temp;
	}
}

void delete(listPointer* first, listPointer trail, listPointer x)
{ 
	if (*first == x)
		*first = trail;
	trail->link = x->link;
	free(x);
}

