#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 999

typedef struct node
{
	int level;
	int bound = INF;
	int* path;
}Node;

typedef struct Priority_Queue
{
	Node* heap; // 오름차순으로 정렬
	int capacity;
	int currentSize;
}PQ;

void travel2(int n, int** W);
void Initialize(PQ* pq);
void Insert(PQ* pq, Node node);
int Empty(PQ pq);
Node Remove(PQ* pq, int n);
int bound(int* path, int n, int level , int** W);
int HasVi(int n, int* path, int i);
void swap(Node* n1, Node* n2);
int length(int* path, int n, int** W);

int main()
{
	int n = 5;
	//int n = 4;
	int** W;
	int mat[5][5] = {
		{ 0,   14,  4,   10,  20},
		{14,   0,   7,   8,   7},
		{ 4,   5,   0,   7,   16},
		{ 11,  7,   9,   0,   2},
		{ 18,  7,   17,  4,   0}
	};

	/*int mat[4][4] = {
		{0,   10,  15,  20},
		{5,  0,  9, 10},
		{6,  13,  0,   12},
		{8, 8,  9,  0}
	};*/

	W = (int**)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		W[i] = (int*)malloc(sizeof(int) * (n + 1));

	printf("Matrix W :\n"); //인접행렬 출력
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			W[i][j] = mat[i - 1][j - 1];
			printf("%4d ", W[i][j]);
		}
		printf("\n");
	}

	travel2(n, W);

	return 0;
}

void travel2(int n, int** W) {
	PQ pq{0,};
	node u, v;
	u.path = (int*)calloc(n + 1, sizeof(int));
	v.path = (int*)calloc(n + 1, sizeof(int));
	int minlength = 999;
	int* opttour = (int*)malloc(sizeof(int) * (n + 1));
	Initialize(&pq);
	v.level = 0;
	v.path[0] = 1;
	v.bound = bound(v.path, n, v.level ,W);
	Insert(&pq, v);
	while (!Empty(pq))
	{
		memcpy(&v, &u, sizeof(Node));
		v = Remove(&pq, n);		
		if (v.bound < minlength)
		{
			u.level = v.level + 1;
			for (int i = 2; i <= n; i++)
			{
				if (HasVi(n, v.path, i))
					continue;
				for(int k=0;k<=v.level;k++)
					u.path[k] = v.path[k];
				u.path[u.level] = i;
				if (u.level == (n - 2))
				{
					for (int j = 2; j <= n; j++)
					{
						if (HasVi(n, u.path, j))
							continue;
						u.path[n - 1] = j;
					}
					u.path[n] = 1;
					if (bound(u.path, n, u.level, W) < minlength)
					{
						minlength = bound(u.path, n, u.level, W);
						for (int k = 0; k < n + 1; k++)
							opttour[k] = u.path[k];
					}
				}
				else
				{
					u.bound = bound(u.path, n, u.level, W);
					if (u.bound < minlength)
						Insert(&pq, u);
				}
			}
		}
	}
	printf("\n\nOPTTOUR: ");
	for (int i = 0; i < n; i++)
	{
		printf("V%d->", opttour[i]);
	}
	printf("V1");
	printf("\n\nMINLEMGTH: %d", minlength);
	printf("\n\n");
	getchar();
	return;
}

void swap(Node* n1, Node* n2)
{
	Node ntmp;
	ntmp.bound= n1->bound;
	ntmp.level = n1->level;
	ntmp.path = (int*)malloc(sizeof(int) * (n1->level + 1));
	for (int k = 0; k <= n1->level; k++)
		ntmp.path[k] = n1->path[k];
	n1->bound = n2->bound;
	n1->level = n2->level;
	n1->path = (int*)malloc(sizeof(int) * (n2->level + 1));
	for (int k = 0; k <= n2->level; k++)
		n1->path[k] = n2->path[k];
	n2->bound = ntmp.bound;
	n2->level = ntmp.level;
	n2->path = ntmp.path;
}

void Initialize(PQ* pq)
{
	pq->heap = (Node*)malloc(sizeof(Node) * 999);
	pq->capacity = 999;
	pq->currentSize = 0;
}

void Insert(PQ* pq, Node node)
{
	if (pq->currentSize >= pq->capacity)
	{
		printf("Heap is full!\n");
		return;
	}
	int pos = pq->currentSize++;
	pq->heap[pos].bound = node.bound;
	pq->heap[pos].level = node.level;
	pq->heap[pos].path = (int*)malloc(sizeof(int) * (node.level + 1));
	for (int k = 0; k <= node.level; k++)
		pq->heap[pos].path[k] = node.path[k];
	int ppos = (pos - 1) / 2; //배열에서 현재 pos값에서 1을 빼고 2로 나누면 이진트리에서의 부모값이된다.
	while (ppos>=0 && (pq->heap[pos].bound < pq->heap[ppos].bound))
	{
		swap(&(pq->heap[pos]), &(pq->heap[ppos]));
		pos = ppos;
		ppos = (pos - 1) / 2;
	}
}

int Empty(PQ pq)
{
	if (pq.currentSize == 0)
		return 1;
	else
		return 0;
}

Node Remove(PQ* pq, int n)
{
	if (Empty(*pq))
	{
		printf("Heap is Empty!\n");
		return pq->heap[0];
	}
	Node front;
	front.path = (int*)calloc(n+1, sizeof(int));
	front.bound = pq->heap[0].bound;
	front.level = pq->heap[0].level;
	for (int k = 0; k <= front.level; k++)
		front.path[k] = pq->heap[0].path[k];

	swap(&pq->heap[0], &pq->heap[pq->currentSize - 1]);
	pq->heap[pq->currentSize - 1].bound = INF;
	pq->currentSize--;
	

	int root = 0;
	int leftChild;
	int rightChild;

	while (root < (pq->currentSize - 1)) 
	{
		if (root == 0)
		{
			leftChild = 1;
			rightChild = 2;
		}
		else
		{
			leftChild = (root + 1) * 2 - 1;
			rightChild = (root + 1) * 2;
		}
		if (leftChild >= pq->currentSize) 
		{
			//Child 존재 X
			break;
		}
		else if (rightChild >= pq->currentSize) 
		{
			//왼쪽 Child만 존재
			if (pq->heap[leftChild].bound < pq->heap[root].bound) 
			{
				swap(&pq->heap[leftChild], &pq->heap[root]);
				root = leftChild;
			}
			else break;
		}
		else
		{
			//양쪽 Child 존재
			if (pq->heap[leftChild].bound < pq->heap[root].bound && pq->heap[rightChild].bound < pq->heap[root].bound)
			{
				if (pq->heap[leftChild].bound > pq->heap[rightChild].bound) 
				{
					swap(&pq->heap[rightChild], &pq->heap[root]);
					root = rightChild;
				}
				else 
				{
					swap(&pq->heap[leftChild], &pq->heap[root]);
					root = leftChild;
				}
			}
			else if (pq->heap[leftChild].bound < pq->heap[root].bound) 
			{
				swap(&pq->heap[leftChild], &pq->heap[root]);
				root = leftChild;
			}
			else if (pq->heap[rightChild].bound < pq->heap[root].bound) 
			{
				swap(&pq->heap[rightChild], &pq->heap[root]);
				root = rightChild;
			}
			else 
			{
				break;
			}
		}
	}
	return front;
}

int HasVi(int n, int* path, int i)
{
	for (int j = 0; j < n; j++)
	{
		if (i == path[j])
			return 1;
	}
	return 0;
}

int bound(int* path, int n, int level, int** W)
{
	int min = INF, m = 0, value = 0;
	for (int i = 0; i <= level+1; i++)
	{
		min = INF;
		if (path[i + 1] < 1 || path[i+1]>n)
		{
			for (int j = 2; j <= n; j++)
			{
				if (HasVi(n, path, j))
					continue;
				m = W[path[i]][j];
				if (min > m)
					min = m;
			}
			value += min;
			break;
		}
		value += W[path[i]][path[i + 1]];
	}

	for (int i = 2; i <= n; i++)
	{
		min = INF;
		if (HasVi(n, path, i))
			continue;
		for (int j = 1; j <= n; j++)
		{
			if (j != 1 && (i == j || HasVi(n, path, j)))
				continue;
			m = W[i][j];
			if (min > m)
				min = m;

		}
		value += min;
	}
	return value;
}

int length(int* path, int n, int** W)
{
	int value = 0;
	for (int i = 0; i < n; i++)
	{
		value = value + W[path[i]][path[i + 1]];
	}
	return value;
}