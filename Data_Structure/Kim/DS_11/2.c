// equivalence classes
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 24
#define FALSE 0
#define TRUE 1

#define MALLOC(p,s)\
	if(!((p) = malloc(s))){\
		exit(1);\
	}

typedef struct node* nodePointer;
typedef struct node {
	int data;
	nodePointer link;
}node;

int main()
{
	FILE* fp;

	int out[MAX_SIZE];
	nodePointer seq[MAX_SIZE];
	nodePointer x, y, top;
	int i, j, size;
	int temp_num = 0;
	int temp_top[MAX_SIZE];
	int temp_data[MAX_SIZE];
	int temp_link[MAX_SIZE];


	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		exit(1);
	}

	fscanf_s(fp, "%d", &size);
	for (i = 0; i < size; i++){
		out[i] = FALSE;
		seq[i] = NULL;
	}
	// size 관련 출력
	printf("/* MAX_SIZE of a set S : %d*/\n", MAX_SIZE);
	printf("current size of S : %d\n", size);
	printf("S = { 0");
	for (i = 1; i < size; i++) {
		printf(", %d", i);
	}
	printf(" }\n");

	
	fscanf_s(fp, "%d %d", &i, &j);
	printf("input pairs :");

	while (!feof(fp))
	{
		printf(" %dR%d ", i, j);
		MALLOC(x, sizeof(*x));
		x->data = j; x->link = seq[i]; seq[i] = x;
		MALLOC(x, sizeof(*x));
		x->data = i; x->link = seq[j]; seq[j] = x;
		fscanf_s(fp, "%d%d", &i, &j);
	}
	fclose(fp);

	printf("\n\nsymmetric 관계 linked List\n");
	for (i = 0; i < size; i++) {
		printf("%d : symmetric 관계: \n", i);
		x = seq[i];
		while (x) {
			printf("(%p %2d %p)   ", x, x->data, x->link);
			x = x->link;
		}
		printf("\n");
	}

	for (i = 0; i < size; i++)
	{
		if (out[i] == FALSE)
		{
			temp_num = 0;
			printf("\nNew class: %4d", i);
			out[i] = TRUE;				
			x = seq[i]; 
			top = NULL;
			for (;;)							
			{
				while (x)
				{
					j = x->data;
					if (out[j] == FALSE)
					{
						printf("%5d", j); 
						out[j] = TRUE;
						y = x->link; 
						x->link = top; 
						top = x; 
						x = y;
					}
					else
					{
						x = x->link;
					}
				} 
				if (!top)
					break;
				x = seq[top->data];
				
				temp_top[temp_num] = top;
				temp_data[temp_num] = top->data;
				temp_link[temp_num] = top->link;
				temp_num += 1;
				top = top->link;
			}
			printf("\npop한 노드 정보\n");
			for (int k = 0; k < temp_num; k++)
			{
				printf("pop: (%p   %3d   %p)\n", temp_top[k], temp_data[k], temp_link[k]);
			}
		}
		
	}
	printf("\n");
	fclose(fp);

	return 0;
}
