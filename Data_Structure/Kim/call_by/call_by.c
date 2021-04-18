#include <stdio.h>

// 참고 사이트 : https://programist.tistory.com/entry/C-%EC%96%B8%EC%96%B4-Call-by-Value%EA%B0%92%EC%97%90-%EC%9D%98%ED%95%9C-%ED%98%B8%EC%B6%9C-Call-by-Reference%EC%B0%B8%EC%A1%B0%EC%97%90-%EC%9D%98%ED%95%9C-%ED%98%B8%EC%B6%9C%EC%9D%98-%EC%9D%B4%ED%95%B4
void swap1(int a, int b);
void swap2(int* a, int* b);

int main(void) 
{
	int a = 10;
	int b = 20;

	// call by value

	printf("before calling function => swap1\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %d   // b value   : %d\n\n", a, b);

	swap1(a, b);

	printf("after calling fuction =>swap1\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %d   // b value   : %d\n\n", a, b);

	// call by reference

	a = 10;
	b = 20;
	printf("before calling function => swap2\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %d   // b value   : %d\n\n", a, b);

	swap2(&a, &b);

	printf("after calling fuction =>swap2\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %d   // b value   : %d\n", a, b);

	return 0;
}


void swap1(int a, int b) {
	int temp;

	temp = a;
	a = b;
	b = temp;

	printf("calling fuction swap1\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %d   // b value   : %d\n\n", a, b);
}

void swap2(int* a, int* b) {
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	printf("calling fuction swap1\n");
	printf("a address : %p   // b address : %p\n", &a, &b);
	printf("a value   : %p   // b value   : %p\n", a, b);
	printf("a pointer : %d   // b pointer   : %d\n\n", *a, *b);
}