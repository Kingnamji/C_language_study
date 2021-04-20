#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEGREE 101

typedef struct {
	int degree;
	int coef[MAX_DEGREE];
}polynomial;

void poly_print(char c[], polynomial p);
int max_num(int a, int b);
polynomial padd(polynomial a, polynomial b);

int main(void)
{
	polynomial a, b, c;

	printf("<< C(x) = A(x) + B(x) >>\n");

	printf("Input the degree of items of A(x) : ");
	scanf_s("%d", &a.degree);
	printf("Input the coefficients A(x) : ");
	for (int i = 0; i <= a.degree; i++){
		scanf_s("%d", &a.coef[i]);
	}
	printf("Input the degree of items of B(x) : ");
	scanf_s("%d", &b.degree);
	printf("Input the coefficients B(x) : ");
	for (int i = 0; i <= b.degree; i++) {
		scanf_s("%d", &b.coef[i]);
	}

	c = padd(a, b);
	poly_print("A(X)", a);
	poly_print("B(X)", b);
	poly_print("C(X)", c);


	return 0;
}

int max_num(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void poly_print(char c[], polynomial p)
{
	int i;
	printf("%s = ", c);

	for (i = 0; i < p.degree; i++)
	{
		if (p.coef[i])
			printf("%dx^%d + ", p.coef[i], p.degree - i);
	}
	if (p.coef[p.degree])
		printf("%d\n", p.coef[p.degree]);
	else
		printf("\n");
}

polynomial padd(polynomial a, polynomial b) {
	polynomial c;
	int max_degree;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = a.degree;
	int degree_b = b.degree;

	max_degree = max_num(a.degree, b.degree);
	c.degree = max_degree;

	while (Apos <= a.degree && Bpos <= b.degree) {
		if (degree_a > degree_b) {
			c.coef[Cpos++] = a.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) {
			c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
			degree_a--;
			degree_b--;
		}
		else {
			c.coef[Cpos++] = b.coef[Bpos++];
			degree_b--;
		}
	}
	
	return c;
}