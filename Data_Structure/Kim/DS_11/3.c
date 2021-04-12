#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
		exit(1);\
	}

typedef struct node* nodePointer;
typedef struct node {
	nodePointer llink;
	int data;
	nodePointer rlink;
} node;

nodePointer header = NULL;

void list_in(int data);
void print_forward();
void print_backward();
void delete(nodePointer node, nodePointer deleted);
void delete_under_value(nodePointer* pHeader, int delValue);

int main(void)
{
	int data;
	FILE* fp; 
	MALLOC(header, sizeof(node));
	header->llink = header;
	header->rlink = header;
		
	fopen_s(&fp, "input.txt", "r");
	
	if (fp == NULL) {
		exit(1);
	}

	fscanf_s(fp, "%d", &data);

	while (!feof(fp)){
		list_in(data);
		fscanf_s(fp, "%d", &data);
	}
	
	fclose(fp);

	printf("After creating a doubly linked circular list with a head node :\n");
	print_forward();
	print_backward();
	
	printf("After deleting numbers less than and equel to 50 :\n");
	delete_under_value(&header, 50);
	print_forward();
	print_backward();

	return 0;
}

void list_in(int data)
{
	nodePointer tmp;
	MALLOC(tmp, sizeof(node));
	tmp->data = data;
	tmp->llink = header->llink;
	tmp->rlink = header;
	header->llink->rlink = tmp;
	header->llink = tmp;
}

void print_forward()
{
	int i = 0;
	nodePointer scaf;

	printf("forward\n");
	for (scaf = header->rlink; scaf != header; scaf = scaf->rlink) {
		i++;
		printf("(%p %d %p) ", scaf->llink, scaf->data, scaf->rlink);
		if ((i % 4) == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

void print_backward()
{
	int i = 0;
	nodePointer scaf;

	printf("backward\n");
	for (scaf = header->llink; scaf != header; scaf = scaf->llink) {
		i++;
		printf("(%p %d %p) ", scaf->llink, scaf->data, scaf->rlink);
		if ((i % 4) == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

void delete(nodePointer node, nodePointer deleted)
{ 
	if (node == deleted)
	{
		printf("Can't Delete.\n");
	}
	else
	{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}

void delete_under_value(nodePointer* pHeader, int delValue)
{
	nodePointer temp, del;

	if (*pHeader)
	{
		temp = (*pHeader)->rlink;	
		while (temp != *pHeader)
		{
			del = temp;
			temp = temp->rlink;

			if (del->data <= delValue)
				delete(*pHeader, del);
		}
	}
}