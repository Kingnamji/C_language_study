#include <stdio.h>

int main(void) 
{ 
	// 변수란 프로그램이 실행되는 동안에 언제든지 저장 값이 변경될 수 있는 공간
	// 상수는 한번 정해지면 값을 변경할 필요가 없는 데이터
	int x; // 정수형의 변수 x를 선언
	x = 5;
	float y = 123456789.123456789; //float는 이정도 크기의 수를 담을 수 없다
	double z = 123456789.123456789; //double은 가능
	printf("x = %d\n", x);
	printf("y = %.2f\n", y); // 소수점 두자리까지 출력
	printf("z = %.2lf\n", z); // 소수점 두자리까지 출력

	// int형 변수의 메모리 크기를 sizeof()를 통해 확인
	printf("변수 x의 메모리 크기는 %d이다.\n", sizeof(x)); 
	// float형 변수의 메모리 크기 확인
	printf("변수 y의 메모리 크기는 %d이다.\n", sizeof(y));
	// double형 변수의 메모리 크기 확인
	printf("변수 z의 메모리 크기는 %d이다.\n", sizeof(z));

	return 0;
}