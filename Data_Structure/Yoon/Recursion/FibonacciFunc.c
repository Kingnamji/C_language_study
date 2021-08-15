#include <stdio.h>

int Fibo(int n)
{
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return Fibo(n - 1) + Fibo(n - 2);
	}
}

int main(void)
{
	int n;
	for (n = 0; n < 15; n++) {
		printf("fibo(%d) = %d \n", n+1, Fibo(n));
	}

	return 0;

}