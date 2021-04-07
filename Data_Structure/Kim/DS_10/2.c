#include <stdio.h>
#include <stdlib.h>

#define COMPARE(x,y) (((x) < (y)) ? -1: ((x) == (y)) ? 0:1)
#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;
polyPointer a, b;
polyPointer avail;

polyPointer getNode(void);
polyPointer cpadd(polyPointer a, polyPointer b);
void Pinput(char* file, polyPointer* header, polyPointer* last);
void attach(int coefficient, int exponent, polyPointer* ptr);
void erase(polyPointer* ptr);
void retNode(polyPointer node);
void cerase(polyPointer* ptr);
void insert(polyPointer* last, polyPointer node);
void insertLast(polyPointer* last, polyPointer node);

int main(void)
{
	polyPointer c, temp, last;

	Pinput("a.txt", &a, &last);
	printf("       a :\n");
	if (a)
	{
		temp = a->link;
		printf("(%p : %+6dx^%d : %p)\n", a, a->coef, a->expon, a->link);
		while (temp != a)
		{
			printf("(%p : %+6dx^%d : %p)\n", temp, temp->coef, temp->expon, temp->link);
			temp = temp->link;
		}
		printf("\n");
	}
	last = NULL;
	temp = NULL;

	Pinput("b.txt", &b, &last);
	printf("       b :\n");
	if (b)
	{
		temp = b->link;
		printf("(%p : %+6dx^%d : %p)\n", b, b->coef, b->expon, b->link);
		while (temp != b)
		{
			printf("(%p : %+6dx^%d : %p)\n", temp, temp->coef, temp->expon, temp->link);
			temp = temp->link;
		}
		printf("\n");
	}

	c = cpadd(a, b);
	printf("a + b = c :\n");
	if (c)
	{
		temp = c->link;
		printf("(%p : %+6dx^%d : %p)\n", c, c->coef, c->expon, c->link);
		while (temp != c)
		{
			printf("(%p : %+6dx^%d : %p)\n", temp, temp->coef, temp->expon, temp->link);
			temp = temp->link;
		}
		printf("\n");
	}

	cerase(&a);
	cerase(&b);
	cerase(&c);
	printf("       avail :\n");
	if (avail)
	{
		temp = avail->link;
		printf("(%p : %+6dx^%d : %p)\n", avail, avail->coef, avail->expon, avail->link);
		while (temp != avail)
		{
			printf("(%p : %+6dx^%d : %p)\n", temp, temp->coef, temp->expon, temp->link);
			temp = temp->link;
		}
		printf("\n");
	}
	erase(&avail);

	return 0;
}



void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	temp = getNode();
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

void erase(polyPointer* ptr)
{
	polyPointer temp;
	while (*ptr) {
		temp = *ptr;
		*ptr = (*ptr)->link;
		free(temp);
	}
}

polyPointer getNode(void)
{
	polyPointer node;
	if (avail)
	{
		node = avail;
		avail = avail->link;
	}
	else
		MALLOC(node, sizeof(*node));
	return node;
}

void retNode(polyPointer node)
{
	node->link = avail;
	avail = node;
}

void cerase(polyPointer* ptr)
{ 
	polyPointer temp;
	if (*ptr)
	{
		temp = (*ptr)->link;
		(*ptr)->link = avail;
		avail = temp;
		*ptr = NULL;
	}
}

polyPointer cpadd(polyPointer a, polyPointer b)
{ 
	polyPointer startA, c, lastC;
	int sum, done = 0;
	startA = a;			
	a = a->link;		
	b = b->link;
	c = getNode();	
	c->expon = -1; lastC = c;

	do
	{
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(b->coef, b->expon, &lastC);
			b = b->link;
			break;

		case 0:
			if (startA == a)
			{
				done = 1;
			}
			else
			{
				sum = a->coef + b->coef;
				if (sum) attach(sum, a->expon, &lastC);
				a = a->link; 	b = b->link;
			}
			break;

		case 1: 
			attach(a->coef, a->expon, &lastC);
			a = a->link;
		}
	} while (!done);

	lastC->link = c;

	return c;
}


void insert(polyPointer* last, polyPointer node)
{	
	if (!(*last))
	{ 
		*last = node;
		node->link = node;
	}
	else
	{ 
		node->link = (*last)->link->link;
		(*last)->link->link = node;

		if ((*last)->expon == -1)
			*last = node;
	}
}

void insertLast(polyPointer* last, polyPointer node)
{
	if (!(*last))
	{ 
		*last = node;
		node->link = node;
	}
	else
	{ 
		node->link = (*last)->link;
		(*last)->link = node;
		*last = node;
	}
}

void Pinput(char* file, polyPointer* header, polyPointer* last)
{
	polyPointer node;
	char order;			
	FILE* fp;

	fopen_s(&fp, file, "r");
	if (fp == NULL)
	{
		exit(1);
	}

	*header = getNode();
	(*header)->expon = -1;
	*last = NULL;
	insertLast(last, *header);

	fscanf_s(fp, "%c", &order, sizeof(order));
	
	if (order == 'a')
	{
		insert(last, *header);
		node = getNode();
		fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		while (!feof(fp))
		{
			insert(last, node);
			node = getNode();
			fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		}
		retNode(node);
	}
	else if (order == 'd')
	{
		node = getNode();
		fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		while (!feof(fp))
		{
			insertLast(last, node);
			node = getNode();
			fscanf_s(fp, "%d%d", &node->coef, &node->expon);
		}
		retNode(node);
	}
	else {
		exit(1);
	}

	fclose(fp);
}