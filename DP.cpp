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

/*============================================================ �� �� ==============================================================*/

int main()
{
	int n = 4;
	int** W;
	int mat[4][4] = {
		{0,   2,   9,   INF},
		{1,   0,   6,   4},
		{INF, 7,   0,   8},
		{6,   3,   INF, 0}
	}; //�������

	/*int mat[4][4] = {
		{0,   10,  15,  20},
		{5,  0,  9, 10},
		{6,  13,  0,   12},
		{8, 8,  9,  0}
	};*/

	W = (int**)malloc(sizeof(int) * (n+1));
	for (int i=0;i<=n;i++)
		W[i]=(int*)malloc(sizeof(int) * (n+1));
	
	printf("Matrix W :\n"); //������� ���
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

/*===========================================================�Լ� �κ�=============================================================*/

void travel(int n, int** W) //TSP ����
{
	int i, j, k, A;
	int** D;
	int** P;
	D = (int**)malloc(sizeof(int) * (n + 1));
	P = (int**)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
	{
		D[i] = (int*)malloc(sizeof(int) * (int)pow(2, n - 1)); //�ε����� 10������ 2������ ��Ÿ���� ��, ���� ������ ��Ʈ ���� 2�� �ִ��� ������ ���� ��) 0000==������ 0010=={3} 0111=={2,3,4} �̷� ������ �ε��� ����
		P[i] = (int*)malloc(sizeof(int) * (int)pow(2, n - 1));
	}

	for(i=1; i<=n;i++) //0���� �ʱ�ȭ
		for (j = 0; j < (int)pow(2, n - 1); j++)
		{
			D[i][j] = 0;
			P[i][j] = 0;
		} 

	for (i = 1; i <= n; i++) //D�� ������ �κп� W�� 1�� �Է�
		D[i][0] = W[i][1];

	for (k = 1; k <= n - 2; k++) //A�� ������ �ִ� Vertcies�� ��
	{
		for (A = 1; A < pow(2, (double)n - 1); A++)
		{
			if (!NumofV(A, k, n)) //Does subset A��V - {v1} contain k vertices? (�����̸� continue) 
				continue;
			for (i = 2; i <= n; i++)
			{
				if (HasVi(i, A)) // Does A has Vertex Vi? (�����̸� continue) 
					continue;
				P[i][A] = min(W,D,A,i,n); // �ּڰ� ���ϱ� + D�� P�� �Է�
			}
		}
	}
	A = (int)pow(2, n - 1) - 1;
	P[1][A] = min(W, D, A, 1, n); // �ּ� ���
	printf("Matrix D :\n"); //D �迭 ���
	print(n, (int)pow(2, n - 1), D);
	printf("Matrix P :\n"); //P �迭 ���
	print(n, (int)pow(2, n - 1), P);

	Route(n,A,P); //������� ���

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
		if ((A & (1 << i)) > 0) //�� ��Ʈ�� 1�� ���� ������ count(���Ұ���) ����
			count++;
		i++;
	}
	return (k == count) ? 1 : 0;
}

int HasVi(int i, int A)
{
	return ((A & (1 << (i - 2))) > 0) ? 1 : 0; //ã�� ���� i�� �ִ��� ���δ� �����ʿ��� ���� i-2�� ° ��Ʈ�� ǥ�õ��ֱ� ������
}


int min(int** W, int** D, int A, int i, int n)
{
	int m=0, mj=0, min=9999;
	for (int j = 2; j <= n; j++)
	{
		if (!HasVi(j, A))
			continue;
		m = W[i][j] + D[j][differ(A, j)]; //min(j:vj��A)(W[i][j]+D[j][A-{vj}])
		if (min >= m)
		{
			min = m;
			mj = j;
		}
	}
	if (min > INF)
		min = INF; //INF�̻��� ���� ��������� ���� �����̱� ������ ��� 999�� ���� ���ϸ� �ٸ� �κп��� ���� ���̰� ��
	D[i][A] = min;
	return mj;
}

int differ(int A, int j) //A�� {Vj}�� ������. j�� �ִ��� ���θ� �˷��ִ� ��Ʈ�� 0���� ����
{
	int t = 1 << (j - 2);
	return (A & (~t));
}

void print(int row, int col, int **mat) //�迭 ���
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

void Route(int n, int A, int** P) //�������
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