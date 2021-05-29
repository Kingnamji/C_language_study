#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500
#define INF_NUM 501

#define MALLOC(p,s)\
	if ( !( (p) = malloc(s) ) ) {\
		exit(1);\
	}

int nums[MAX_SIZE + 1] = { 0 };						// keys to sort
int winTree[2 * MAX_SIZE] = { NULL };		// winner tree
int sorted[MAX_SIZE + 1] = { 0 };					// sorted result
void winner(int cur, int k, int winTree[]);
void inorder(int root, int k, int winTree[]);
void adjust(int ind, int winTree[]);

int main(void)
{
	int cnt, i, j, n, seed;

	printf("<<<<<<<<<<<<< sorting with winner tree >>>>>>>>>>>>>>\n\n");

	printf("%s", "the number of keys ( 4, 8, 16, or 32 as a power of 2 )  >> ");
	scanf_s("%d", &n);

	printf("value of seed >>  ");
	scanf_s("%d", &seed);
	srand(seed);

	for (i = 1; i <= n; i++)
	{
		nums[i] = rand() % MAX_SIZE + 1;
		printf(" %3d", nums[i]);
	}
	printf("\n");

	printf("\ninitialization of min-winner tree\n");
	for (cnt = n, i = 1; i <= n; cnt++, i++)
		winTree[cnt] = nums[i];

	printf("\ninorder traversal for min-winner tree\n");
	winner(1, n, winTree);
	inorder(1, n, winTree);

	for (i = 1; i <= n; i++)
	{
		sorted[i] = winTree[1];
		if (i != n) {
			for (j = n; j < 2 * n; j++)
				if (sorted[i] == winTree[j]) {
					winTree[j] = INF_NUM;
					break;
				}
			adjust(j, winTree);
		}
		if (i == 2) {
			printf("\nWinner Tree inoder traversal after find 2 winners...\n");
			inorder(1, n, winTree);
		}
	}
	printf("\n\n");
	printf("sorting with min-winner tree...\n\n");

	printf("sorted result\n");
	for (i = 1; i <= n; i++)
		printf(" %3d", sorted[i]);

	return 0;
}


void inorder(int root, int k, int winTree[])
{
	if (root < 2 * k)
	{
		inorder(2 * root, k, winTree);
		printf(" %3d", winTree[root]);
		inorder(2 * root + 1, k, winTree);
	}
}


void adjust(int ind, int winTree[])
{
	int i, cmp;
	i = ind;
	while (i != 1) {
		if (i % 2)
			cmp = i - 1;
		else
			cmp = i + 1;
		if (winTree[i] <= winTree[cmp])
			winTree[i / 2] = winTree[i];
		else
			winTree[i / 2] = winTree[cmp];
		i = i / 2;
	}
}

void winner(int cur, int k, int winTree[])
{
	int i, j, parent, start;

	start = k + k - 1;
	parent = start / 2;

	while (parent >= 1)
	{

		if (winTree[start] > winTree[start - 1])
			winTree[parent] = winTree[start - 1];
		else
			winTree[parent] = winTree[start];
		start = start - 2;
		parent = start / 2;

	}
}
