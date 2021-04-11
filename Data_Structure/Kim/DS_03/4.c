#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct { 			// 다항식 구조체 타입 선언
	int degree;			// 다항식의 차수
	int coef[MAX_DEGREE];	// 다항식의 계수
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
	
	// A  최대 차수 입력
	printf("Input the degree of items of A(x) : ");
	scanf_s("%d", &a.degree);
	
	// A 각 항 계수 입력
	printf("Input the coefficients A(x) :  ");
	for(i=0; i<a.degree+1; i++)
		scanf_s("%d", &a.coef[i]);
	
	// B 최대 차수 입력
	printf("Input the degree of items of B(x) : ");
	scanf_s("%d", &b.degree);
	
	// B 각 항 계수 입력
	printf("Input the coefficients B(x) :  ");
	for(i=0; i<b.degree+1; i++)
		scanf_s("%d", &b.coef[i]);

	// A,B 출력
    poly_print("A(X) = ", a);
	poly_print("B(X) = ", b); 

	// C = A+B 계산 및 출력
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
	
	if (c.coef[c.degree]) // 상수 항
		printf("%d \n", c.coef[c.degree]);

	else printf("\b\n");

}

polynomial poly_add1(polynomial A, polynomial B)  // C=A+B
{
	polynomial C;				// 결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0;	// 배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // A, B 중 더 큰 차수가 C의 차수

	while (Apos <= A.degree && Bpos <= B.degree) { // A, B의 배열 인덱스가 각 항의 차수 보다 작을 때
		if (degree_a > degree_b) { // A의 차수가 더 큰 경우
			C.coef[Cpos++] = A.coef[Apos++]; // C의 해당 항에 A의 가장 큰 항을 더해준다.
			degree_a--; // A 차수를 빼 줌
		}
		else if (degree_a == degree_b) { // A와 B의 차수가 같은 경우
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++]; // C의 해당 항에 A+B
			degree_a--; degree_b--;
		}
		else { // B의 차수가 더 큰 경우
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
