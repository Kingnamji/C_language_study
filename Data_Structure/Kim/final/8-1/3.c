#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100
#define LEN 10
#define MALLOC(p,s)\
	if( !((p) = malloc(s)) ){\
		printf("malloc fail");\
		exit(1);\
	}

typedef struct
{
	char item[LEN];
	int key;
}element;

typedef struct node* nodePointer;
typedef struct node
{
	element data;  
	nodePointer link;
}Node;

typedef struct
{
	nodePointer link;
}HT;

int cnt, b = 11;
nodePointer list[MAX_SIZE];
HT ht[11] = { NULL};

int h(int k);
void insertht(nodePointer x);
int stringToInt(char* item);
nodePointer createNode(char item[]);
void printList(int i);
element* search(int k);


int main()
{
	FILE* fp;
	char data[MAX_SIZE][LEN];
	int i, k, size;
	char find[LEN];
	element* result = NULL;

	size = 0;

	fopen_s(&fp, "input.txt", "r");
	if (fp == NULL) {
		exit(1);
	}

	printf(" input strings : ");

	while (!feof(fp))
	{
		fscanf_s(fp, "%s ", data[size++],LEN); 
		printf("%s ", data[size - 1]);  
	}
	printf("\n");

	for (i = 0; i < size; i++)
		list[i] = createNode(data[i]);

	for (i = 0; i < size; i++)
		insertht(list[i]);

	printf("\n          item  key\n");
	for (i = 0; i < b; i++)
	{
		printf("ht[%2d] :", i);
		printList(i);
	}
	printf("\n");

	while (1)
	{
		printf("input \"quit\" to quit\n");
		printf("string to search >> ");
		scanf_s("%s", find, LEN);

		if (!strcmp(find, "quit"))
			break;
		k = stringToInt(find);
		result = search(k);

		if (!result)
			printf("it doesn't exist\n\n");
		else
			printf("item : %s, key : %d, the number of comparison : %d\n\n", result->item, result->key, cnt);
	}

	fclose(fp);
	return 0;
}

int h(int k)
{
	return k % b;
}


nodePointer createNode(char item[])
{
	nodePointer temp;

	MALLOC(temp, sizeof(*temp));

	strcpy_s(temp->data.item, LEN,item);
	temp->data.key = stringToInt(item);
	temp->link = NULL;

	return temp;
}

int stringToInt(char* item)
{
	int num = 0;

	while (*item)
		num += *item++;

	return num;
}

void insertht(nodePointer x)
{
	nodePointer temp;
	int index = h(x->data.key);

	if (!ht[index].link)  
		ht[index].link = x;

	else  
	{
		for (temp = ht[index].link; temp; temp = temp->link) 
		{
			if (!temp->link)  
			{
				temp->link = x;  
				break;
			}
		}
	}
}

void printList(int i)
{
	nodePointer temp;

	if (!ht[i].link)
		printf("\n");
	else
	{
		for (temp = ht[i].link; temp; temp = temp->link)
			printf(" (%s %d)", temp->data.item, temp->data.key);
		printf("\n");
	}
}


element* search(int k)
{
	nodePointer current;
	cnt = 1;

	current = ht[h(k)].link;
	for (; current; current = current->link)
	{
		if (current->data.key == k)
			return &current->data;
		cnt++;
	}

	return NULL;
}