#include<stdio.h>
#include<stdlib.h>

#define ROW 7
#define COL 7
#define MAX_SIZE 100
#define INF 2147483647
#define TRUE 1
#define FALSE 0

int selected[MAX_SIZE];
int dist[MAX_SIZE];
int adjmatrix[ROW][COL];

int get_min_vertex(int n);
void prim(int s, int n);

int num, sum;
FILE* fp;

sum = 0;

int main(void) {
	int u, v, weight;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
		exit(1);

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (i == j)
				adjmatrix[i][j] = 0;
			else
				adjmatrix[i][j] = INF;
		}
	}

	fscanf_s(fp, "%d", &num);
	for (int i = 0; i < num; i++) {
		fscanf_s(fp, "%d %d %d", &u, &v, &weight);
		adjmatrix[u][v] = weight;
		adjmatrix[v][u] = weight;
	}

	prim(0, 7);

	printf("최소 비용 : %d\n", sum);

	return 0;
}


int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) { v = i; break; }
	}
	for (i = 0; i < n; i++) {
		if (!selected[i] && (dist[i] < dist[v]))
			v = i;
	}
	return v;
}

void prim(int s, int n) {
	int u, before = 0;
	int distance;

	for (u = 0; u < n; u++) {
		dist[u] = INF;
		selected[u] = FALSE;
	}

	dist[s] = 0;

	for (int i = 0; i < n; i++) {
		u = get_min_vertex(n);
		selected[u] = TRUE;

		if (dist[u] == INF)
			return;

		printf("선택 vertex : %d,    ", u);
		for (int v = 0; v < n; v++) {
			if (adjmatrix[u][v] != INF) {
				if (!selected[v] && adjmatrix[u][v] < dist[v]) {
					dist[v] = adjmatrix[u][v];
				}
			}
		}

		printf("distance : ");

		for (int i = 0; i < n; i++) {
			if (dist[i] == 2147483647)
				printf("  INF");
			else
				printf("%4d ", dist[i]);
		}

		if (i > 0) {
			printf("  선택 edge : (%d, %d) distance : %d\n", before, u, dist[u]);
			before = u;
		}
		else
			printf("\n");

		if (i == n - 1) {
			for (i = 0; i < n; i++) {
				sum += dist[i];
			}
		}
	}
}