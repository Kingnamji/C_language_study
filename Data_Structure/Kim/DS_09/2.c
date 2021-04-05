#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUES_SIZE 3
#define MALLOC(p, s) \
	if( !((p) = malloc(s))) { \
		fprintf(stderr, "Insufficient memory"); \
		exit( EXIT_FAILURE );\
	}

typedef struct {
	int class; // 학반
	int grade; // 성적
}element;

typedef struct stack* queuePointer;
typedef struct stack {
	element data;
	queuePointer link;
}Node;
// Linked Queues
queuePointer front[MAX_QUEUES_SIZE] = { NULL };
queuePointer rear[MAX_QUEUES_SIZE] = { NULL };

void addq(int i, element item);
element deleteq(int i);
element queueEmpty();

int main()
{
	FILE* fp;
	element data_f;
	int i, j;
	if (fopen_s(&fp, "input.txt", "r"))
		exit(1);


	fscanf_s(fp, "%d %d %d", &i, &data_f.class, &data_f.grade);
	while (!feof(fp))
	{
		addq(i, data_f);
		fscanf_s(fp, "%d %d %d", &i, &data_f.class, &data_f.grade);
	}

	printf("과목번호,  학반,  성적\n");
	for (i = 0; i < MAX_QUEUES_SIZE; i++)
	{
		printf("************************\n");
		while (front[i])
		{
			data_f = deleteq(i);
			printf("%8d%7d%7d\n", i, data_f.class, data_f.grade);
		}
	}

	fclose(fp);

	return 0;
}

void addq(int i, element item)
{
	queuePointer temp;
	MALLOC(temp, sizeof(*temp));
	temp->data = item;
	temp->link = NULL;
	
	if (front[i])
		rear[i]->link = temp;
	else
		front[i] = temp;
	rear[i] = temp;
}

element queueEmpty()
{
	element item;
	item.grade = -1;
	return item;
}

element deleteq(int i)
{
	element item;
	queuePointer temp = front[i];

	if (!temp)
		return queueEmpty();
	
	item = temp->data;
	front[i] = temp->link;
	free(temp);

	return item;
}