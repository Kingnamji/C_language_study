#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

int main(void)
{
	Node* head = NULL; // 리스트의 머리를 가리키는 포인터 변수
	Node* tail = NULL; // 리스트의 꼬리를 가리키는 포인터 변수
	Node* cur = NULL; // 저장된 데이터의 조회에 사용되는 포인터 변수

	Node* newNode = NULL;
	int readData;

	// 데이터 입력
	while (1)
	{
		printf("자연수를 입력하삼요 : ");
		scanf("%d", &readData);
		if (readData < 1) // stop
			break;

		// 노드 추가
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL) // 첫 번째 노드라면
			head = newNode; // 첫 번째 노드를 head가 가리키게 함
		else
			tail->next = newNode;

		tail = newNode; // 노드의 끝을 tail이 가리키게 함
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정
	printf("입력 받은 데이터의 전체 출력! \n");
	
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다.\n");
	}
	else {
		cur = head;
		printf("%d ", cur->data); // 첫 번째 데이터 출력
	
		while (cur->next != NULL) // 두 번째 이후 쭉 출력
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	// 메모리 해제
	if (head == NULL)
	{
		printf("메모리 해제할 노드가 없음. \n");
		return 0;
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		// 첫 번째 노드 삭제
		printf("%d을 삭제합니다. \n", head->data);
		free(delNode); 

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}