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
	int num;
	int rear = -1, front = -1; // 비어있는 queue의 rear, front 기본값.
	// 일반 출력
	printf("<< Linear queue operations where MAX_QUEUE_SIZE is 3 >>\n");
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
			rear++;
			// rear가 MAX_QUEUE_SIZE보다 크거나 같아진 경우 
			if (rear >= MAX_QUEUE_SIZE) 
			{
				if (front > -1)
				{
					printf("data shift\n");
					num = front;
					for (int i = 0; i <= num; i++)
					{
						for (int j = front; j < rear; j++)
						{
							queue[j].id = queue[j + 1].id;
							strcpy_s(queue[j].name, MAX_NAME_SIZE, queue[j + 1].name);
						}
						front--;
						rear--;
					}
					sscanf_s(line + strlen(tok) + 1, "%d%s", &queue[rear].id, queue[rear].name, sizeof(queue[rear].name));
				}
				else {
					rear--; // rear이 ++ 연산으로 인해 최대 크기보다 커졌으므로 다시 줄여준다.
					printf("queue is full, not added\n");
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
			front++; //queue가 비어있지 않은 경우
		}
		else if (!strcmp(tok, "qprint"))
		{
			for (int i = front + 1; i <= rear; i++)
				printf("%d %s\n", queue[i].id, queue[i].name);
			printf("\n\n");
		}
		else if (!strcmp(tok, "quit"))
		{
			exit(1);
		}
		else // 위의 어떤 command에도 해당하지 않는 경우
		{
			printf("wrong command! try again!\n\n");
		}

		// 명령어에 관한 실행이 끝난 후
		if (!(fgets(line, sizeof(line), fp))) // 다음 줄을 받아온다
			break;

	}

	fclose(fp);

	return 0;
}
