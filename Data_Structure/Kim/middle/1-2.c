#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s)\
	if ( !((p) = malloc(s)) ){\
		exit(1);\
}

int main(void)
{
	int i, * pi;
	float f, * pf;
	MALLOC(pi, sizeof(int));
	MALLOC(pf, sizeof(int));
	*pi = 1024;
	*pf = 3.14;

	printf("an integer = %d\na float = %f\n", *pi, *pf);
	free(pi);
	free(pf);
	return 0;
}

