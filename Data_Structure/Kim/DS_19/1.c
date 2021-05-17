#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef struct {
	int key;
	int u;
	int v;
} element;

typedef struct {
	element heap[MAX_SIZE];
	int heap_size;
}HeapType;

int parent[MAX_SIZE];

void init(HeapType* h);
void insertEdge(HeapType* h);
void insert_min_heap(HeapType* h, element e);
void insert_heap_edge(HeapType* h, int u, int v, int weight);
void set(int n);
void SetUnion(int a, int b);
int find(int e);
element delete(HeapType* h);

int num, sum, n;
FILE* fp;
sum = 0;

int main(void) {
	int a, b;
	int edge_accepted = 0;
	HeapType h;
	element e;

	n = 7;

	fopen_s(&fp, "input.txt", "r");

	if (fp == NULL)
		exit(1);

	fscanf_s(fp, "%d", &num);

	init(&h);
	insertEdge(&h);
	set(n);

	while (edge_accepted < (n - 1)) {
		e = delete(&h);
		a = find(e.u);
		b = find(e.v);
		if (a != b) {
			printf("(%d %d) %d\n", e.u, e.v, e.key);
			sum += e.key;
			edge_accepted++;
			SetUnion(a, b);
		}
	}

	printf("\n최소비용 : %d\n", sum);

	fclose(fp);

	return 0;
}

void init(HeapType* h) {
	for (int i = 0; i < 100; i++) {
		h->heap[i].key = 0;
	}
	h->heap_size = 0;
}

void set(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

void insertEdge(HeapType* h) {
	int u, v, weight;

	for (int i = 0; i < num; i++) {
		fscanf_s(fp, "%d %d %d", &u, &v, &weight);
		insert_heap_edge(h, u, v, weight);
	}
}

void insert_heap_edge(HeapType* h, int u, int v, int weight) {
	element e;
	e.u = u;
	e.v = v;
	e.key = weight;
	insert_min_heap(h, e);
}

void insert_min_heap(HeapType* h, element e) {
	int i;

	i = ++(h->heap_size);

	while ((i != 1) && (e.key < (h->heap[i / 2].key))) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = e;
}

element delete(HeapType* h) {
	int parent, child;
	element data, temp;
	data = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= (h->heap_size)) {
		if ((child < (h->heap_size)) && (h->heap[child].key > h->heap[child + 1].key))
			child++;
		if (temp.key <= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return data;
}

int find(int e) {
	for (; parent[e] >= 0; e = parent[e])
		;
	return e;
}

void SetUnion(int a, int b) {
	parent[a] = b;
}

