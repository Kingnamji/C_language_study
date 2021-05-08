
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define INF_NUM 9999
#define MAX_QUEUE_SIZE 100
#define MAX_INEDX 15

// min - winner tree 
int nums[MAX_SIZE+1][11] = { 0 };			// keys to sort
int winTree[ 2*MAX_SIZE ] = { 0 };		// winner tree
int sorted[ MAX_SIZE*10+1 ] = { 0 };		// sorted result
int sortedIdx[MAX_SIZE + 1] = { 0 };		// sorted index of each record
void initWinner(int cur, int k, int winTree[]);
void  adjustWinner(int min, int k, int winTree[]);

void addq(int w_index);
void queueFull();
int deleteq();
int queueEmpty();
void levelOrder();

int queue[MAX_QUEUE_SIZE];
int front, rear;


int main(void)
{
	int cnt, i, j;
	int k;
	int min; // the smallest number's index
	FILE * fp;
	
	if (fopen_s(&fp, "input.txt", "r")) {
		printf("can not open input.txt\n");
		exit(1);
	}
	

	printf("<<<<<<<<<<<<< run data >>>>>>>>>>>>>>\n\n");
	for (i = 1; i < 9; i++) {
		for (j = 1; j < 11; j++)
			if (fscanf_s(fp, "%d", &nums[i][j]) < 1) {
				printf("data of run is not correct !!\n");
					exit(1);
			}
				
		printf("%d-th run: \n", i);

		for (j = 1; j <= 10; j++)
			printf("%4d ", nums[i][j]);
		printf("\n");
	}

	k = 8;
	for ( cnt = k, i = 1; i <= k; cnt++, i++ )						
			winTree[cnt] = i;
	for ( i = 1; i <= k; i++)
		sortedIdx[i] = 1;

	initWinner(1, k, winTree);  // ( root index , the numbers of keys, winTree )
	printf("\nLeve-order traversal for initial min-winner tree\n");
	levelOrder();

	printf("\n\nsorting with min-winner tree...\n");
	for ( i = 1; i <= k * 10; i++ )						
	{
		min = winTree[1];		// minimum key's index in array nums[]
		sorted[i] = nums[min][sortedIdx[min]];

		//nums[min] = INF_NUM;
		// 해당 레코드의 원소가가 정렬되었으면, 다음 원소를 정렬해야합니다.
		sortedIdx[min]++;

		// 해당 레코드의 모든 원소가 정렬되었으면, 다음번에 정렬되지 않도록
		// INF_NUM 값으로 치환합니다.
		if (sortedIdx[min] > 10) {
			sortedIdx[min]--;
			nums[min][sortedIdx[min]] = INF_NUM;
		}
		adjustWinner(min, k, winTree);
	}

	printf("\nsorted result\n");
	for ( i = 1; i <= k * 10; i++ )						
		printf("%3d%s", sorted[i], i % k ?  " " : "\n"  );

	return 0;
}


void initWinner(int cur, int k, int winTree[])
{
	int parent, start;

	start = k + k - 1;
	parent = start / 2;

	while (parent >= 1)
	{
		if (nums[winTree[start]][1] > nums[winTree[start-1]][1])
			winTree[parent] = winTree[start - 1];
		else
			winTree[parent] = winTree[start];
		start = start - 2;
		parent = start / 2;
	}

}

// adjusting winner tree for a substituted key
void  adjustWinner(int min, int k, int winTree[])
{
	int  sibling;
	int sub = k-1+min;   // index in winner tree for a substituted key
	int parent = sub / 2;
	
	while( parent >= 1 )
	{
		if ( sub % 2 )				// odd index
			sibling = 2 * parent; // or sibling = sub - 1;
		else				
			sibling = 2 * parent + 1;  // or sibling = sub + 1
	
		///< modified by jsjang
		if( nums[ winTree[sibling] ][sortedIdx[winTree[sibling]]] < nums[ winTree[sub] ][sortedIdx[winTree[sub]]])
			winTree[parent] = winTree[sibling];
		else
			winTree[parent] = winTree[sub];

		parent /= 2;
		sub /= 2;
	}
}




// Level-order traversal of a binary tree
void levelOrder()
{ /* level order tree traversal */

	front = rear = 0;		/* circular queue */
	int w_index = 1;

	addq(w_index);

	for (;; )
	{
		w_index = deleteq();
		if (w_index < 0)
			break;
	
		printf("%d ", nums[winTree[w_index]][1]);
		if (w_index*2 <= MAX_INEDX)
			addq(w_index * 2);

		if (w_index * 2 + 1 <= MAX_INEDX)
			addq(w_index * 2 + 1);
		
	}

}


/////////////////////// queue operations ///////////////////////////////////
// Program 3.7
void addq(int w_index)
{ /* add an item to the queue */
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear)
		queueFull(); /* print error and exit */
	queue[rear] = w_index;
}

void queueFull()
{
	fprintf(stderr, "queue is full, cannot add item\n");
	exit(EXIT_FAILURE);
}

int deleteq()
{ /* remove front element from the queue */
	if (front == rear)
		return queueEmpty(); /* return an error key */
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

int queueEmpty()
{

	return -1;
}


