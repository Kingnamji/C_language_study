#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10
#define MALLOC(p,s)\
	if( !((p) = malloc(s)) ){\
		printf("malloc fail");\
		exit(1);\
	}

typedef struct {
	int key;
}element;

element* ht[8] = { NULL };

int random[8];

int b = 8, slot = 1;
int cnt;

void insertht(int k);
int h(int k);
int s(int i);
element* search(int k);

int main()
{
	FILE* fp;
	int input[100];
	int check[11] = { 0 };
	int k, seed;
	int i, j, size;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL)
	{
		exit(1);
	}
	printf("key sequence from file : ");

	i = 0;
	while (!feof(fp))
	{
		fscanf_s(fp, "%d", &input[i]);
		printf("     %d ", input[i]);
		i++;
	}

	size = i;

	printf("\ninput seed >> ");
	scanf_s("%d", &seed);
	srand(seed);
	printf("\n");
	
	for (i = 1; i < b; i++)
	{
		random[i] = rand() % (b - 1) + 1;
		
		while (check[random[i]] == 1)
			random[i] = rand() % (b - 1) + 1;

		check[random[i]] = 1;

		printf("random[%2d] : %d\n", i, random[i]);
	}

	for (i = 0; i < size; i++) {
		insertht(input[i]);
	}

	printf("\n             key\n");

	for (int i = 0; i < b; i++)
	{
		if (ht[i]) {
			printf("ht [%2d] :%6d\n", i, ht[i]->key);
		}
		else {
			printf("ht [%2d] :\n", i);
		}

	}
	
	while (1)
	{
		printf("\ninput 0 to quit");
		printf("\nkey to search >> ");
		scanf_s("%d", &k);

		if (k == 0) {
			break;
		}

		if (search(k))
		{
			printf("key : %d, the number of comparisions : %d\n\n", search(k)->key, cnt);
		}
		else {
			printf("there is no\n\n");
		}
	}

	fclose(fp);
	return 0;
}

int s(int i)
{
	return random[i];
}

element* search(int k)
{
	int i, homeBucket, currentBucket;
	homeBucket = h(k);
	cnt = 1;

	for (i = 1, currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k; i++) {
		cnt++;

		currentBucket = (h(k + s(i))) % b;

		if (currentBucket == homeBucket)
			return NULL;
	}
	if (ht[currentBucket] && ht[currentBucket]->key == k)
		return ht[currentBucket];

	return NULL;
}

void insertht(int k) {
	int i, homeBucket, currentBucket;
	element* temp;
	homeBucket = h(k);

	MALLOC(temp, sizeof(element) * slot);

	for (i=1, currentBucket = homeBucket; ht[currentBucket];i++)
	{
		currentBucket = (h(k + s(i))) % b;

		if (currentBucket == b)
		{
			printf("exit\n");
			return;
		}
	}

	temp->key = k;

	ht[currentBucket] = temp;
}

int h(int k)
{
	return (k % b);
}
