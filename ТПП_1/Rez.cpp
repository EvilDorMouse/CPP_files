#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

void swap(int* a, int i, int j);
bool NextSet(int* a, int n);
void printV(int* a, int n);

int main(int argc, char* argv[])
{
	int rank;
	int size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	//MPI_Status stat;

	int n = 5; //создание и заполнение матрицы расстрояний n городов (1)

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				a[i][i] = 0;
			else
				a[i][j] = i + j;
		} //-----end(1)-----




	if (rank == 0)
	{
		cout << "M = " << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";
	}
	else
	{
		int* v = new int[n - 2]; //создание вектора пути
		int v0 = rank;
		int vn = 0;

		for (int i = 0; i < n - 2; i++)
		{
			if (i + 1 == rank)
				i++;

			v[i] = i + 1;
		}

		cout << "rank = " << rank << "\nv = ";
		printV(v, n - 2);

		int Sv0 = *a[0, v[0]];

		cout << "-----v0-----> " << v0 << "\n";

		//int sum = 0;
		//int min_sum = 10000;
		//int* res = new int[n];

		/*while (NextSet(v, n))
		{
			for (int i = 0; i < n-1; i++)
			{
				sum += *a[v[i], v[i + 1]];
			}

			if (sum < min_sum)
			{
				min_sum = sum;

				for (int i = 0; i < n;i++)
					res[i] = v[i];
			}
		}*/

		//cout << "-----res-----> ";
		//printV(res, n);
		//cout << "\n";
	}

	MPI_Finalize();
	return 0;
}

void swap(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool NextSet(int* a, int n)
{
	int j = n - 2;

	while (j != -1 && a[j] >= a[j + 1]) j--;

	if (j == -1)
		return false; // больше перестановок нет

	int k = n - 1;

	while (a[j] >= a[k]) k--;
	swap(a, j, k);

	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности

	while (l < r)
		swap(a, l++, r--);

	return true;
}

void printV(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\n";
}