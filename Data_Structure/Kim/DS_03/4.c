#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { 			// ���׽� ����ü Ÿ�� ����
	int degree;			// ���׽��� ����
	int coef[MAX_DEGREE];	// ���׽��� ���
} polynomial;

void poly_print(char [], polynomial );
polynomial poly_add1(polynomial A, polynomial B);

int main()
{
	int i;
	polynomial a;
	polynomial b;
	polynomial c;

	printf("<< C(x) = A(x) + B(x) >>\n");
	
	// A  �ִ� ���� �Է�
	printf("Input the degree of items of A(x) : ");
	scanf_s("%d", &a.degree);
	
	// A �� �� ��� �Է�
	printf("Input the coefficients A(x) :  ");
	for(i=0; i<a.degree+1; i++)
		scanf_s("%d", &a.coef[i]);
	
	// B �ִ� ���� �Է�
	printf("Input the degree of items of B(x) : ");
	scanf_s("%d", &b.degree);
	
	// B �� �� ��� �Է�
	printf("Input the coefficients B(x) :  ");
	for(i=0; i<b.degree+1; i++)
		scanf_s("%d", &b.coef[i]);

	// A,B ���
    poly_print("A(X) = ", a);
	poly_print("B(X) = ", b); 

	// C = A+B ��� �� ���
	c = poly_add1(a,b);
	poly_print("C(X) = ", c); 
}

void poly_print(char ch[], polynomial c)
{
	int i;
	printf("%s", ch);
	for( i = 0 ; i < c.degree ; i++ )
	{
		if (c.coef[i])
			printf("%dx^%d + ", c.coef[i], c.degree - i);
	}	
	
	if (c.coef[c.degree]) // ��� ��
		printf("%d \n", c.coef[c.degree]);

	else printf("\b\n");

}

polynomial poly_add1(polynomial A, polynomial B)  // C=A+B
{
	polynomial C;				// ��� ���׽�
	int Apos = 0, Bpos = 0, Cpos = 0;	// �迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // A, B �� �� ū ������ C�� ����

	while (Apos <= A.degree && Bpos <= B.degree) { // A, B�� �迭 �ε����� �� ���� ���� ���� ���� ��
		if (degree_a > degree_b) { // A�� ������ �� ū ���
			C.coef[Cpos++] = A.coef[Apos++]; // C�� �ش� �׿� A�� ���� ū ���� �����ش�.
			degree_a--; // A ������ �� ��
		}
		else if (degree_a == degree_b) { // A�� B�� ������ ���� ���
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++]; // C�� �ش� �׿� A+B
			degree_a--; degree_b--;
		}
		else { // B�� ������ �� ū ���
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
