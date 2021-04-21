#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 20
#define MAX_LEN 100
#define MALLOC(p,s)\
	if (!((p) = malloc(s))){\
		exit(1);\
	}

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

int front = 0;
int rear = 0;
int capacity = 2;
element* queue;

void copy(element* a, element* b, element* c);
void queueFull();
void qprint();

int main(void)
{
	MALLOC(queue, sizeof(element) * capacity);
	FILE* fp;
	char line[100];
	char* ntok, * tok;
	fopen_s(&fp, "input.txt", "r");

	printf("<< Circular queue operations using dynamic allocated array, where the initial capacity is 2>>\n");
	printf("add 1 Jung\n");
	printf("delete\n\n");
	printf("**************************************************\n");


	fgets(line, MAX_LEN, fp);
	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);

		if (!strcmp(tok, "add")) {
			rear = (rear + 1) % capacity;
			if (rear == front) {
				queueFull();
				rear = rear + 1;
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
				printf("queue capacity is doubled, \n");
				printf("current queue capacity is %d\n", capacity);
				qprint();
			}
			else {
				sscanf_s(line + strlen(tok) + 1, "%d %s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
			}
		}
		else if (!(strcmp(tok, "delete")))
		{
			if (front == rear) {
				printf("queue is empty, cannot delete element.\n");
				break;
			}
			front = (front + 1) % capacity;
		}
		else if (!strcmp(tok, "qprint"))
		{
			qprint();
		}
		else if (!strcmp(tok, "quit")) {
			printf("end of program!\n");
			exit(1);
		}
		else
			printf("wrong command! try again\n");

		if(!fgets(line, MAX_LEN, fp))
			break;
	}

	fclose(fp);
	free(queue);

	return 0;
}

void copy(element* a, element* b, element* c) {
	while (a != b)
		*c++ = *a++;
}

void queueFull() {
	int start;
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	if (start < 2) {
		copy(queue + start, queue + start + capacity - 1, newQueue);
	}
	else {
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
	free(queue);
	queue = newQueue;
}

void qprint()
{
	int i, j;
	if (front > rear)
		j = front + 1 + rear + (capacity - 1 - front);
	else 
		j = rear;
	for (i = front + 1; i <= j; i++)
 		printf("%d, %s\n", queue[i % capacity].id, queue[i % capacity].name);
	printf("\n");
}