#include <stdio.h>
#include <stdlib.h>
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MAX_TERMS 100

void padd( int startA, int finishA, int startB, int finishB, int *startD, int *finishD );
void attach( int coefficient, int exponent );
void printPolynomial( int start, int finish );

typedef struct 
{
    int coef; // 계수
    int exp; // 지수
}term;
 
term terms[MAX_TERMS];
int avail = 0;
 
void main()
{
            
	int startA, finishA, startB, finishB, startD, finishD;
	int coef;
	int exp, i, m, n;
	char c;
	 
	printf("<< D(x) = A(x) + B(x) >>\n");
	printf("Input the number of items of A(x) : ");
	scanf_s("%d", &m);
	printf("Input the number of items of B(x) : ");
	scanf_s("%d", &n);

	startA=0;
	finishA = m-1;
	startB = finishA+1;
	finishB = startB+n-1;
	avail = finishB + 1;

	printf("\ninput in descending order\n");
	
	// Input for A(x)
	puts("");
	printf("coefficient and exponent of A(x)=10x^5+8x^3+7 (10 5, 8 3, 7 0 ) : " );
	for( i = startA; i <= finishA-1; i++ )
		{	
			scanf_s("%d %d %c" , &coef, &exp,  &c, (int)sizeof(char) );
			terms[i].coef = coef;
			terms[i].exp = exp;
		}

	scanf_s("%d %d" , &coef, &exp);
	terms[i].coef = coef;
	terms[i].exp = exp;


	// Input for B(x)
		printf("coefficient and exponent of B(x)=10x^5+8x^2+3 (10 5, 8 2, 3 0 ) : " );
	for( i = startB; i <= finishB-1; i++ )
		{	
			scanf_s("%d %d %c", &coef, &exp, &c, (int)sizeof(char));
			terms[i].coef = coef;
			terms[i].exp = exp;
		}

		scanf_s("%d %d", &coef, &exp);
		terms[i].coef = coef;
		terms[i].exp = exp;
	puts("");


	// D(x) = A(x) + B(x)
	padd( startA, finishA, startB, finishB, &startD, &finishD );
 
	// print the result of polynomial addition
	printf("\nA(x) = ");	printPolynomial( startA, finishA );
	printf("B(x) = ");	printPolynomial( startB, finishB );
	printf("D(x) = ");	printPolynomial( startD, finishD );
}

 void printPolynomial( int start, int finish )
 {
	 int i;	
	 for( i = start; i < finish; i++ )
		printf( "%dx^%d + ", terms[i].coef, terms[i].exp );
	
	if( terms[finish].exp == 0 )
		printf( "%d\n",terms[finish].coef );
	else 
		printf( "%dx^%d\n", terms[finish].coef, terms[finish].exp );
 }

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
	/*add A(x) and B(x) to obtain D(x) */
	int coefficient;
	*startD = avail;
	
	while( startA <= finishA && startB <= finishB )
	{
		switch( COMPARE( terms[startA].exp, terms[startB].exp ) )
		{
			case -1 : /* a expon < b expon */
				attach( terms[startB].coef, terms[startB].exp );
				startB++;
				break;
			case 0 :  /* equal exponents */
				coefficient = terms[startA].coef + terms[startB].coef;
				if ( coefficient )
					attach( coefficient, terms[startA].exp );
				startA++;
				startB++;
				break;
			case 1 : /* a expon > b expon */
				attach( terms[startA].coef, terms[startA].exp );
				startA++;
		}//switch
	}//while

	/* add in remaining terms of A(x) */
    for(; startA <= finishA; startA++ )
		attach( terms[startA].coef, terms[startA].exp );
    
	/* add in remaining terms of B(x) */
	for(; startB <= finishB; startB++ )
		attach( terms[startB].coef, terms[startB].exp );
 
    *finishD = avail-1;
}
 
void attach( int coefficient, int exponent )
{
	/* add a new trems to the polynomial */
	if( avail >= MAX_TERMS )
	{
		fprintf( stderr, "Too may terms in the polynomial\n");
		exit(EXIT_FAILURE);
	}
	terms[avail].coef = coefficient;
	terms[avail++].exp = exponent;
}
