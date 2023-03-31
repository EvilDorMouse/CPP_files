#include <stdio.h>
#include <iostream>
#include <time.h>
#include "mpi.h"

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
	MPI_Status stat;
	srand(static_cast<unsigned int>(time(0)));

	int n = 5; //создание и заполнение матрицы расстрояний n городов (1)

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i > j)
			{
				a[i][j] = rand()%35;
				a[j][i] = a[i][j];
			}
		
			if (i == j)
				a[i][i] = 0;
		} //-----end(1)-----

	if (rank == 0)
	{
		cout << "M: " << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j] << " ";
			cout << "\n";
		}
		cout << "\n";

		int* cres = new int[n - 1];
		for (int i = 0; i < n - 1; i++)
			cres[i] = -1;

		int** Mres = new int* [n - 1];
		Mres[0] = new int[(n -1) *n];
		for (int i = 1; i < n - 1; i++)
			Mres[i] = Mres[i - 1] + n;

		for (int i = 1; i < size; i++)
		{
			MPI_Recv(&cres[i - 1], 1, MPI_INT, i, 666, MPI_COMM_WORLD, &stat);
			MPI_Recv(Mres[i - 1], n, MPI_INT, i, 666, MPI_COMM_WORLD, &stat);
		}

		cout << "-----cres-----> ";
		for (int i = 0; i < n - 1; i++)
		{
			cout << cres[i] << " ";
		}
		cout << "\n";

		cout << "Mres:" << "\n";
		for (int i = 0; i < n - 1; i++)
		{
			cout << "0 ";
			for (int j = 0; j < n; j++)
				cout << Mres[i][j] << " ";

			cout << "\n";
		}
		cout << "\n";
			

		int minc = cres[0];
		int minn = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (cres[i] < minc)
			{
				minc = cres[i];
				minn = i;
			}
		}

		cout << "-----minc-----> " << minc << "\n";
		cout << "-----minres-----> 0 ";
		for (int i = 0; i < n; i++)
		{
			cout << Mres[minn][i] << " ";
		}
		cout << "\n";
	}
	else
	{
		int* v = new int[n - 2]; //создание вектора пути

		int p = 0;
		for (int i = 0; i < n - 2; i++)
		{
			if (i + 1 == rank)
			{
				p += 2;
				v[i] = p;
			}
			else
			{
				p++;
				v[i] = p;
			}
				
		}

	//	cout << "rank = " << rank << "\nv = ";
	//	printV(v, n - 2);

		int Sv0rank = a[0][rank];

	//	cout << "-----Sv0rank-----> " << Sv0rank << "\n";

		int sum = 0;
		int min_sum = 0;
		int* res = new int[n];
		for (int i = 0; i < n - 1; i++)
			res[i] = -1;
		
		for (int i = 0; i < n - 3; i++)
		{
			min_sum += a[v[i]][v[i + 1]];
		}

		for (int i = 1; i < n - 1; i++)
			res[i] = v[i - 1];

		res[0] = rank;
		res[n - 1] = 0;

		int Svrank = a[rank][v[0]];
		int Svend = a[0][v[n - 3]];

		min_sum += Svrank + Svend;
	//	cout << "-----min_sum-----> " << min_sum << "\n";

		while (NextSet(v, n - 2))
		{
			for (int i = 0; i < n - 3; i++)
			{
				sum += a[v[i]][v[i + 1]];
			}

			Svrank = a[rank][v[0]];
			Svend = a[0][v[n - 3]];
			
			sum += Svrank + Svend;
		//	cout << "-----sum-----> " << sum << "\n";

			
			if (sum < min_sum)
			{
				min_sum = sum;

				for (int i = 1; i < n - 1; i++)
					res[i] = v[i - 1];
			}

			sum = 0;
		}

		//cout << "-----res-----> ";
		//printV(res, n);
		//cout << "\n";

		min_sum += Sv0rank;

		MPI_Send(&min_sum, 1, MPI_INT, 0, 666, MPI_COMM_WORLD);
		MPI_Send(res, n, MPI_INT, 0, 666, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

/*********************************************************/

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