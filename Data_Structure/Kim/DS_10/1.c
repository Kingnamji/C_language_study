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
};
polyPointer a, b;

void insert(polyPointer* first, polyPointer x, int coef, int expon);
void attach(int coefficient, int exponent, polyPointer* ptr);
void erase(polyPointer* ptr);
void Pinput(char* file, polyPointer* p);
void find(polyPointer first, polyPointer* last);
polyPointer padd(polyPointer a, polyPointer b);

int main(void)
{
	polyPointer c;
	FILE* fp;

	Pinput("a.txt", &a);
	Pinput("b.txt", &b);

	c = padd(a, b);

	printf("       a :\n");
	for (; a; a = a->link)
		printf("(%p :%+6dx^%d : %p)\n", a, a->coef, a->expon, a->link);
	printf("\n");

	printf("       b :\n");
	for (; b; b = b->link)
		printf("(%p :%+6dx^%d : %p)\n", b, b->coef, b->expon, b->link);
	printf("\n");

	printf("       c :\n");
	for (; c; c = c->link)
		printf("(%p :%+6dx^%d : %p)\n", c, c->coef, c->expon, c->link);
	printf("\n");

	erase(&a); erase(&b); erase(&c);

	return 0;
}

void insert(polyPointer* first, polyPointer x, int coef, int expon)
{ 	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->coef = coef;
	temp->expon = expon;

	if (*first)
	{ 	if (!x)
		{ 
			temp->link = *first;
			*first = temp;
		}
		else
		{ 
			temp->link = x->link;
			x->link = temp;
		}
	}
	else
	{ 	
		temp->link = NULL;
		*first = temp;
	}
}

void find(polyPointer first, polyPointer* last)
{
	for (; first; first = first->link)
		*last = first;
}

void Pinput(char* file, polyPointer* p)
{
	int coef, expon;
	polyPointer x = NULL;		
	polyPointer last = NULL;	
	char order;					
	FILE* fp;

	fopen_s(&fp, file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "cannot open the file");
		exit(EXIT_FAILURE);
	}

	fscanf_s(fp, "%c", &order, sizeof(order));		
	if (order == 'a')
	{
		fscanf_s(fp, "%d%d", &coef, &expon);
		while (!feof(fp))
		{
			insert(p, NULL, coef, expon);
			fscanf_s(fp, "%d%d", &coef, &expon);
		}
	}
	else if (order == 'd')
	{
		fscanf_s(fp, "%d%d", &coef, &expon);
		while (!feof(fp))
		{
			find(*p, &last);
			x = last;
			insert(p, x, coef, expon);		
			fscanf_s(fp, "%d%d", &coef, &expon);
		}
	}
	else {
		printf("please check input.\n");
		exit(1);
	}

	fclose(fp);
}

void attach(int coefficient, int exponent, polyPointer* ptr)
{
	polyPointer temp;
	MALLOC(temp, sizeof(*temp));
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

polyPointer padd(polyPointer a, polyPointer b)
{
	polyPointer c, rear, temp;
	int sum;
	MALLOC(rear, sizeof(*rear));
	c = rear;
	while (a && b) // a, b 가 모두 NULL을 가르키지 않는 동안만
	{
		switch (COMPARE(a->expon, b->expon)){
		case -1:
			attach(b->coef, b->expon, &rear);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link;
			b = b->link;
			break;
		case 1:
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	return c;
}