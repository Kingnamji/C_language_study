#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
	int coef;
	int expon;
}term;

term terms[MAX_TERMS];
int avail = 0;
void attach(int coefficient, int exponent);
void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD);
void poly_print(char c[], int startp, int finishp);
int compare(int x, int y);

int main(void)
{
	int startA, finishA, startB, finishB, startD, finishD;
	int coef,exp;
	int i, itema, itemb;
	char c;

	printf("<< D(x) = A(x) + B(x) >>\n");
	printf("Input the number of items of A(x) :");
	scanf_s("%d", &itema);
	printf("Input the number of items of B(x) :");
	scanf_s("%d", &itemb);
	startA = 0;
	finishA = itema - 1;
	startB = itema;
	finishB = startB + itemb - 1;
	avail = finishB + 1;

	printf("\ninput in descending order\n\n");

	printf("coefficient and exponent of A(x)=10x^5+8x^3+7 (10 5, 8 3, 7 0 ) : ");
	for (i = startA; i <= finishA-1; i++) {
		scanf_s("%d %d %c", &coef, &exp, &c, sizeof(char));
		terms[i].coef = coef;
		terms[i].expon = exp;
	}
	scanf_s("%d %d", &coef, &exp);
	terms[i].coef = coef;
	terms[i].expon = exp;


	printf("coefficient and exponent of B(x)=10x^5+8x^2+3 (10 5, 8 2, 3 0 ) : ");
	for (i = startB; i <= finishB - 1; i++) {
		scanf_s("%d %d %c", &coef, &exp, &c, sizeof(char));
		terms[i].coef = coef;
		terms[i].expon = exp;
	}
	scanf_s("%d %d", &coef, &exp);
	terms[i].coef = coef;
	terms[i].expon = exp;

	padd(startA, finishA, startB, finishB, &startD, &finishD);

	poly_print("A(x) =", startA, finishA);
	poly_print("B(x) =", startB, finishB);
	poly_print("D(x) =", startD, finishD);


	return 0;
}

int compare(int x, int y)
{
	if (x < y)
		return -1;
	else if (x == y)
		return 0;
	else
		return 1;
}

void padd(int startA, int finishA, int startB, int finishB, int* startD, int* finishD)
{
	int coef;
	int comp;
	*startD = avail;

	while (startA <= finishA && startB <= finishB)
	{
		comp = compare(terms[startA].expon, terms[startB].expon);
		if (comp == -1){ // a expon < b expon
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
		}
		else if (comp == 0) {
			coef = terms[startA].coef + terms[startB].coef;
			if (coef) {
				attach(coef, terms[startA].expon);
			}
			startA++;
			startB++;
		}
		else {
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
		}
	}
	for (; startA <= finishA; startA++) {
		attach(terms[startA].coef, terms[startA].expon);
	}
	for (; startB <= finishB; startB++) {
		attach(terms[startB].coef, terms[startB].expon);
	}
	*finishD = avail - 1;
}

void attach(int coefficient, int exponent)
{
	if (avail >= MAX_TERMS) {
		exit(1);
	}

	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void poly_print(char c[], int startp, int finishp) {
	int i;

	printf("%s ", c);

	for (i = startp; i < finishp; i++) {
		printf("%dx^%d +", terms[i].coef, terms[i].expon);
	}
	if (terms[i].expon == 0) {
		printf("%d\n", terms[i].coef);
	}
	else
		printf("%dx^%d\n", terms[i].coef, terms[i].expon);
	
}