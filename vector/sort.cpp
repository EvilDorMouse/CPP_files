#include <iostream>

using namespace std;

void BubbleSortAsc(double *A, int N)
{
	int perm(0);
	int comp(0);

	double c;

	for (int i = 0; i < N - 1; i++)
		for (int j = N - 2; j >= i; j--)
		{
			comp++;
			if (A[j] > A[j + 1])
			{
				perm++;
				c = A[j];
				A[j] = A[j + 1];
				A[j + 1] = c;
			}
		}
	cout << "Perm = " << perm << endl;
	cout << "Comp = " << comp << endl;
}

void BubbleSortDes(double *A, int N)
{
	double c;

	for (int i = 0; i < N - 1; i++)
		for (int j = N - 2; j >= i; j--)
			if (A[j] < A[j + 1])
			{
				c = A[j];
				A[j] = A[j + 1];
				A[j + 1] = c;
			}
}

void SelectSort(double *A, int N)
{
	int i_min;
	double c;
	int perm(0);
	int comp(0);

	for (int i = 0; i < N; i++)
	{
		i_min = i;
		for (int j = i + 1; j < N; j++)
		{
			comp++;
			if (A[j] < A[i_min])
				i_min = j;
		}
		comp++;
		if (i_min != i)
		{
			perm++;
			c = A[i];
			A[i] = A[i_min];
			A[i_min] = c;
		}
	}
	cout << "Perm = " << perm << endl;
	cout << "Comp = " << comp << endl;
}

void InsertSort(double *A, int N)
{
	int j;
	double x;
	int perm(0);
	int comp(0);

	for (int i = 1; i < N; i++)
	{
		x = A[i];
		j = i - 1;

		while (x < A[j] && j >= 0)
		{
			comp++;
			perm++;
			A[j + 1] = A[j];
			j = j - 1;
		}
		perm++;
		A[j + 1] = x;
	}
	cout << "Perm = " << perm << endl;
	cout << "Comp = " << comp << endl;
}