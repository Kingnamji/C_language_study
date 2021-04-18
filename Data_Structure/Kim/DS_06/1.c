#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 20
#define MAX_LEN 100
#define MALLOC(p,s)  \
	if (! ((p) = malloc(s))) {\
		fprintf(stderr, "Insufficient memory"); \
		exit(EXIT_FAILURE); \
	}

typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

void copy(element* a, element* b, element* c);
void queueFull();

element *queue;
int capacity = 2;
int rear = 0, front = 0; // 비어있는 queue의 rear, front 기본값.

int main()
{
	MALLOC(queue, sizeof(element) * capacity); // 초기의 메모리 할당
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;
	
	// 일반 출력
	printf("<< Circular queue operations using dynamic allocated array, where the initial capacity is 2 >>\n");
	printf("add 1 Jung \ndelete\n\n");
	printf("*****************************************************\n");

	// input.txt에서 데이터 받아오기
	fopen_s(&fp, "input.txt", "r");
	fgets(line, sizeof(line), fp);

	while (1) {
		ntok = line;
		tok = strtok_s(ntok, " \n", &ntok);
		if (!strcmp(tok, "add")) // 명령이 add라면
		{
			rear = (rear + 1) % capacity;
			// rear가 capacity 보다 크거나 같아진 경우 
			if (rear == front)
			{
				queueFull(); // 함수 실행				
				rear = rear+1;
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
				
				printf("queue capacity is doubled, \n"); // 문장 출력
				printf("current queue capacity is %d\n", capacity);
				if (front < rear) // front 값이 rear값 보다 클 때
				{
					for (int i = front + 1; i <= rear; i++)
						printf("%d, %s\n", queue[i].id, queue[i].name);
					printf("\n\n");
				}
				else if (rear < front) // rear 값이 front 값 보다 작을 때
				{
					for (int i = 0; i <= rear; i++)
						printf("%d, %s\n", queue[i].id, queue[i].name);
					printf("\n\n");
				}
			}
			else {
				sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
			}
		}
		else if (!strcmp(tok, "delete"))
		{
			if (front == rear) // queue가 empty
			{
				printf("queue is empty. cannot delete element.\n");
				break;
			}
			front = (front + 1) % capacity; //queue가 비어있지 않은 경우
		}
		else if (!strcmp(tok, "qprint"))
		{
			if (front < rear) // front 값이 rear값 보다 클 때
			{
				for (int i = front + 1; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n\n");
			}
			else if (rear < front) // rear 값이 front 값 보다 작을 때
			{
				for (int i = 0; i <= rear; i++)
					printf("%d, %s\n", queue[i].id, queue[i].name);
				printf("\n\n");
			}
			// rear값 front 값이 같아지는 경우는 없음
		}
		else if (!strcmp(tok, "quit"))
		{
			printf("end of program!!\n");
			exit(1);
		}
		else // 위의 어떤 command에도 해당하지 않는 경우
		{
			printf("wrong command! try again!\n");
		}

		// 명령어에 관한 실행이 끝난 후
		if (!(fgets(line, sizeof(line), fp))) // 다음 줄을 받아온다
			break;

	}

	fclose(fp);
	free(queue);

	return 0;
}

void copy(element* a, element* b, element* c)
{
	while (a != b)
		*c++ = *a++;
}

void queueFull()
{ 
	int start;
	element* newQueue;
	MALLOC(newQueue, 2 * capacity * sizeof(*queue));

	start = (front + 1) % capacity;
	if (start < 2)
		copy(queue + start, queue + start + capacity - 1, newQueue);
	else
	{
		copy(queue + start, queue + capacity, newQueue);
		copy(queue, queue + rear + 1, newQueue + capacity - start);
	}

	front = 2 * capacity - 1;
	rear = capacity - 2;
	capacity *= 2;
	free(queue);
	queue = newQueue;
}
