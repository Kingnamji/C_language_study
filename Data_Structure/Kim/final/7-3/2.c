#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define M_DATA 100
#define BUCKETS 10
#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

void error(char* message);
void init(QueueType* q);
void enqueue(QueueType* q, element item);
void radix_sort(int list[], int n, int digits);
int is_empty(QueueType* q);
int is_full(QueueType* q);
element dequeue(QueueType* q);
element peek(QueueType* q);

int main()
{
	int i, digits, n;
	int list[M_DATA];

	FILE* fp;

	fopen_s(&fp, "input.txt", "r");
	
	if (fp == NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}

	fscanf_s(fp, "%d%d", &digits, &n);

	for (i = 0; i < n; i++)
		fscanf_s(fp, "%d", &list[i]);

	printf("input data --- \n");

	for (i = 0; i < n; i++)
		printf("%5d", list[i]);
	printf("\n");

	radix_sort(list, n, digits);

	printf("\nresult --- \n");

	for (i = 0; i < n; i++)
		printf("%5d", list[i]);
	printf("\n");

	fclose(fp);
	return 0;
}

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

void radix_sort(int list[], int n, int digits)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (d = 0; d < digits; d++) {
		for (b = 0; b < BUCKETS; b++) init(&queues[b]);  // ť���� �ʱ�ȭ
		printf("\nstep %d �ڸ�  --- \n", d);
		printf("\nQueue�� ����  --- \n");
		for (i = 0; i < n; i++)
			printf("%5d", i);
		printf("\n");

		for (i = 0; i < n; i++)			// �����͵��� �ڸ����� ���� ť�� ����
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (i = 4; i > 0; i--) {
			for (b = 0; b < BUCKETS; b++)
				if (queues[b].rear >= i)
					printf("%5d", queues[b].queue[i]);
				else
					printf("     ");
			printf("\n\n");
		}
		printf("---------------------------------------------------\n");

		for (b = i = 0; b < BUCKETS; b++)  // ��Ŷ���� ������ list�� ��ģ��
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;					// �� ���� �ڸ���


		for (i = 0; i < n; i++)
			printf("%5d", list[i]);
		printf("\n");
	}

}