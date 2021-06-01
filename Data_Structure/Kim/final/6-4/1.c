#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 7
#define INF 999

int cost[MAX_VERTICES][MAX_VERTICES];
int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int path[MAX_VERTICES]; 

int choose(int distance[], int n, short int found[]);
void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]);
void printPath(int start, int end);

int main(void)
{
	int v, e;
	int i, row, col, value;
	int start;
	FILE* fp;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL) {
		exit(1);
	}

	fscanf_s(fp, "%d %d", &v, &e);

	for (row = 0; row < v; row++){
		for (col = 0; col < v; col++)
		{
			if (row == col)
				cost[row][col] = 0;
			else cost[row][col] = INF;
		}
	}

	for (i = 0; i < e; i++)
	{
		fscanf_s(fp, "%d %d %d", &row, &col, &value);
		cost[row][col] = value;
		cost[col][row] = value;
	}

	start = 0;

	shortestPath(start, cost, distance, v, found);
	printf("\n");

	for (i = 0; i < 7; i++)
	{
		if (i != start)
		{
			printf("distance[%d-%d]=%-4d: ", start, i, distance[i]);
			printPath(start, i);
			printf("\n");
		}
	}

	return 0;
}


int choose(int distance[], int n, short int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortestPath(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[])
{
	int i, j, u, w;
	u = 0;

	for (i = 0; i < n; i++)
	{
		found[i] = FALSE;
		path[i] = v;
		distance[i] = cost[v][i];
	}
	found[v] = TRUE;
	distance[v] = 0;

	for (i = 0; i < n; i++)
	{
		if (i != n-1){
			printf("%d:  ", u);

			for (j = 0; j < n; j++)
			{
				printf("%7d", distance[j]);
			}
			printf("\n");
		}
		
		u = choose(distance, n, found);
		
		found[u] = TRUE;
		for (w = 0; w < n; w++) {
			if (!found[w])
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					path[w] = u;
				}
		}
		
	}
}

void printPath(int start, int end)
{
	if (path[end] != start)
		printPath(start, path[end]);
	printf("<%d -> %d>  ", path[end], end);
}