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
	char item[LEN];
	int key;
}element;

int b = 11, s = 1;
int cnt;

element* ht[11];

void insertht(int k, char data[]);
unsigned int stringToInt(char* key);
int h(unsigned int k);
element* search(int k);

int main()
{
	FILE* fp;
	char data[LEN];
	unsigned int  k;
	int i;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
		exit(1);

	printf(" input strings :");
	while (!feof(fp)) {
		fscanf_s(fp, "%s", data, LEN);
		printf(" %s", data);
		k = stringToInt(data);
		insertht(k, data);		
	}

	printf("\n\n               item     key\n");
	for (i = 0; i < b; i++) {
		if (ht[i]) {
			printf("ht [%2d] :%10s%8d\n", i, ht[i]->item, ht[i]->key);
		}
		else {
			printf("ht [%2d] :\n", i);
		}
	}
	
	printf("\nstring to search >> ");
	scanf_s("%s", data, LEN);
	k = stringToInt(data);

	if (search(k)) {
		printf("item : %s, key : %d, the number of comparisions : %d\n", search(k)->item, search(k)->key, cnt);
	}
	else {
		printf("There is no");
	}

	fclose(fp);
	return 0;
}

unsigned int stringToInt(char* key)
{
	int number = 0;
	while (*key) {
		number += *key++;
	}
	return number;
}

int h(unsigned int k) {
	return k % b;
}

void insertht(int k, char data[]) {
	int homeBucket, currentBucket;
	element* temp;
	homeBucket = h(k);

	MALLOC(temp, sizeof(element) * s);

	for (currentBucket = homeBucket; ht[currentBucket];)
	{
		currentBucket = (currentBucket + 1) % b;

		if (currentBucket == b)
		{
			printf("exit\n");
			return;
		}
	}

	strcpy_s(temp->item, LEN, data);
	temp->key = k;
	
	ht[currentBucket] = temp;
}

element* search(int k)
{
	int homeBucket, currentBucket;
	homeBucket = h(k);
	cnt = 1;
	

	for (currentBucket = homeBucket; ht[currentBucket] && ht[currentBucket]->key != k;) {
		cnt++;

		currentBucket = (currentBucket + 1) % b;

		if (currentBucket == homeBucket)
			return NULL;
	}
	if (ht[currentBucket] && ht[currentBucket]->key == k)
		return ht[currentBucket];

	return NULL;
}