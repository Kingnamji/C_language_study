#include <stdio.h>
#include <stdlib.h>


# define MALLOC(p,s) \
	if(!((p) = malloc(s))){\
		exit(1);\
	}

int main(void)
{
	int* pi;
	float* pf;

	MALLOC((int*)pi, sizeof(int));
	MALLOC((float*)pf, sizeof(float));

	*pi = 1024;
	*pf = (float)3.14;
	printf("an integer = %d \na float = %f\n", *pi, *pf);

	free(pi);
	free(pf);


	return 0;
}