#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 3
#define MAX_NAME_SIZE 20
#define MAX_LEN 100


typedef struct {
	int id;
	char name[MAX_NAME_SIZE];
}element;

element queue[MAX_QUEUE_SIZE];

int main()
{
	FILE* fp;
	char line[MAX_LEN];
	char* tok, * ntok;
	int temp;
	int rear = 0, front = 0; // 비어있는 queue의 rear, front 기본값.
	// 일반 출력
	printf("<< Circular queue operations where MAX_QUEUE_SIZE is 3 >>\n");
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
			temp = rear; // Queue가 Full 이면 다시 돌려줄 변수
			rear = (rear + 1) % MAX_QUEUE_SIZE;
			// rear가 MAX_QUEUE_SIZE보다 크거나 같아진 경우 
			if (rear == front)
			{
				printf("queue is full, not added\n");
				rear = temp;
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
			front = (front+1)%MAX_QUEUE_SIZE; //queue가 비어있지 않은 경우
		}
		else if (!strcmp(tok, "qprint"))
		{
			if (front<rear) // front 값이 rear값 보다 클 때
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

	return 0;
}
