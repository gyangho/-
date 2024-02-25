#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INF 999

void travel(int n, int** W);
int NumofV(int A, int k, int n);
int HasVi(int i, int A);
int min(int** W, int** D, int A, int i, int n);
int differ(int A, int j);
void print(int row, int col, int** mat);
void Route(int n, int A, int** P);

/*============================================================ 선 언 ==============================================================*/

int main()
{
	int n = 4;
	int** W;
	int mat[4][4] = {
		{0,   2,   9,   INF},
		{1,   0,   6,   4},
		{INF, 7,   0,   8},
		{6,   3,   INF, 0}
	}; //인접행렬

	/*int mat[4][4] = {
		{0,   10,  15,  20},
		{5,  0,  9, 10},
		{6,  13,  0,   12},
		{8, 8,  9,  0}
	};*/

	W = (int**)malloc(sizeof(int) * (n+1));
	for (int i=0;i<=n;i++)
		W[i]=(int*)malloc(sizeof(int) * (n+1));
	
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
	printf("\n\n");


	travel(n, W);

	free(W);
	getchar();
	return 0;
}

/*===========================================================함수 부분=============================================================*/

void travel(int n, int** W) //TSP 구현
{
	int i, j, k, A;
	int** D;
	int** P;
	D = (int**)malloc(sizeof(int) * (n + 1));
	P = (int**)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
	{
		D[i] = (int*)malloc(sizeof(int) * (int)pow(2, n - 1)); //인덱스는 10진수를 2진수로 나타냈을 때, 가장 오른쪽 비트 부터 2가 있는지 없는지 여부 예) 0000==공집합 0010=={3} 0111=={2,3,4} 이런 식으로 인덱스 지정
		P[i] = (int*)malloc(sizeof(int) * (int)pow(2, n - 1));
	}

	for(i=1; i<=n;i++) //0으로 초기화
		for (j = 0; j < (int)pow(2, n - 1); j++)
		{
			D[i][j] = 0;
			P[i][j] = 0;
		} 

	for (i = 1; i <= n; i++) //D의 공집합 부분에 W의 1열 입력
		D[i][0] = W[i][1];

	for (k = 1; k <= n - 2; k++) //A가 가지고 있는 Vertcies의 수
	{
		for (A = 1; A < pow(2, (double)n - 1); A++)
		{
			if (!NumofV(A, k, n)) //Does subset A⊆V - {v1} contain k vertices? (거짓이면 continue) 
				continue;
			for (i = 2; i <= n; i++)
			{
				if (HasVi(i, A)) // Does A has Vertex Vi? (진실이면 continue) 
					continue;
				P[i][A] = min(W,D,A,i,n); // 최솟값 구하기 + D와 P에 입력
			}
		}
	}
	A = (int)pow(2, n - 1) - 1;
	P[1][A] = min(W, D, A, 1, n); // 최소 경비
	printf("Matrix D :\n"); //D 배열 출력
	print(n, (int)pow(2, n - 1), D);
	printf("Matrix P :\n"); //P 배열 출력
	print(n, (int)pow(2, n - 1), P);

	Route(n,A,P); //최적경로 출력

	printf("\nOPTCOST: %d\n",D[1][A]);

	free(D);
	free(P);
}

int NumofV(int A, int k, int n)
{
	int i = 0, count = 0;
	while (1)
	{
		if (i == n-1)
			break;
		if ((A & (1 << i)) > 0) //각 비트에 1이 있을 때마다 count(원소개수) 증가
			count++;
		i++;
	}
	return (k == count) ? 1 : 0;
}

int HasVi(int i, int A)
{
	return ((A & (1 << (i - 2))) > 0) ? 1 : 0; //찾는 원소 i가 있는지 여부는 오른쪽에서 부터 i-2번 째 비트에 표시돼있기 때문에
}


int min(int** W, int** D, int A, int i, int n)
{
	int m=0, mj=0, min=9999;
	for (int j = 2; j <= n; j++)
	{
		if (!HasVi(j, A))
			continue;
		m = W[i][j] + D[j][differ(A, j)]; //min(j:vj∈A)(W[i][j]+D[j][A-{vj}])
		if (min >= m)
		{
			min = m;
			mj = j;
		}
	}
	if (min > INF)
		min = INF; //INF이상의 값은 연결돼있지 않은 상태이기 때문에 모두 999로 지정 안하면 다른 부분에서 값의 차이가 남
	D[i][A] = min;
	return mj;
}

int differ(int A, int j) //A와 {Vj}의 차집합. j가 있는지 여부를 알려주는 비트를 0으로 변경
{
	int t = 1 << (j - 2);
	return (A & (~t));
}

void print(int row, int col, int **mat) //배열 출력
{
	int i, j;

	for (i = 1; i <= row; i++) 
	{
		for (j = 0; j < col; j++) 
		{
			printf("%4d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void Route(int n, int A, int** P) //최적경로
{
	int j = 1;
	printf("Route: V1->");
	for (int i = 1; i <= n-1; i++)
	{
		printf("V%d->", P[j][A]);
		j = P[j][A];
		A = differ(A, j);
	}
	printf("V1\n\n");
}