#include "OSBinTree.h"
using namespace std;


void OSBinTree::CreateMatrix(int* p, int* q, int n, int** W, int** C, int** R)
{
	int i, j, t;
	for (i = 0; i < n + 1; i++)
		for (j = 0; j < n + 1; j++)
			W[i][j] = C[i][j] = R[i][j] = -1;

	//заполнение главной (t=0) диагонали в W и C
	for (i = 0; i < n + 1; i++)
		W[i][i] = C[i][i] = q[i];

	//заполнение первой (t=1) диагонали в W, C и R
	for (i = 0; i < n; i++)
	{
		j = i + 1;
		W[i][j] = W[i][i] + p[j] + q[j];
		C[i][j] = W[i][j] + C[i][i] + C[j][j];
		R[i][j] = j;
	}

	int min, k, k_min;
	//заполнение остальных (t=2,3,...,n) диагонали в W, C и R
	for (t = 2; t < n + 1; t++)
		for (i = 0; i < n + 1 - t; i++)
		{
			j = i + t;
			W[i][j] = W[i][j - 1] + p[j] + q[j];

			min = C[i][i] + C[i + 1][j]; k_min = i + 1;
			for (k = i + 2; k <= j; k++)
				if (C[i][k - 1] + C[k][j] < min)
				{
					min = C[i][k - 1] + C[k][j]; k_min = k;
				}

			C[i][j] = W[i][j] + min;
			R[i][j] = k_min;
		}



	//вывод чтобы посмотреть
	//int i, j;
	cout << "W:" << endl;
	for (i = 0; i < n + 1; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << W[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "C[]:" << endl;
	for (i = 0; i < n + 1; i++)//1
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "R[]:"<<endl;
	for (i = 0; i < n + 1; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			cout << R[i][j] << "\t";
		}
		cout << endl;
	}
}

//OSBinTree(const OSBinTree&);
OSBinTree::OSBinTree(const OSBinTree& T)
{
	if (T.root == NULL) root = NULL;
	else {
		root = new Node(T.root->key);
		copy(T.root->left, root, 0);
		copy(T.root->right, root, 1);
	}
}

Node* OSBinTree::OTree(int* d, int i, int j, int** R, Node* q)
{
	if (i >= j)	return NULL;
	int k = R[i][j];
	Node* p = new Node(d[k]);
	p->left = OTree(d, i, k - 1, R, p);
	p->right = OTree(d, k, j, R, p);
	p->parent = q;
	return p;
}

OSBinTree::OSBinTree(int* d, int* p, int* q, int n)
{
	int** W = new int* [n+1];
	int** R = new int* [n+1];
	int **C = new int* [n+1];

	for (int i = 0; i < n + 1; i++)
	{
		W[i] = new int[n+1];
		C[i] = new int[n+1];
		R[i] = new int[n+1];
	}
	CreateMatrix(p, q, n, W, C, R);

	root = OTree(d, 0, n, R, NULL);
}

