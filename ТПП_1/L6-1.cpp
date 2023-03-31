#include <stdio.h>
#include <iostream>
#include "mpi.h"

#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max);

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int n = 0, count;

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	srand(static_cast<unsigned int>(time(0)) * (rank*10 + rand()));

	if (rank == 0)
	{
		n = size;
		int** a = new int* [n];
		a[0] = new int[n * n];

		for (int i = 1; i < n; i++)
			a[i] = a[i - 1] + n;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = 0;

		for (int i = 1; i < size; i++)
		{
			MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &stat);
			MPI_Get_count(&stat, MPI_INT, &count);
			MPI_Recv(a[stat.MPI_SOURCE], count, MPI_INT, stat.MPI_SOURCE, 777, MPI_COMM_WORLD, &stat);
			printf("source= %d \n", stat.MPI_SOURCE);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf(" %d ", a[i][j]);
			printf("\n ");
		}
	}
	else
	{
		int l = getRandomNumber(1, size);
		int* a = new int[l];

		cout << "-----< " << rank << " >-----\n";
		for (int i = 0; i < l; i++)
		{
			a[i] = rank;
			cout << a[i] << " ";
		}
		cout << endl;

		MPI_Send(a, l, MPI_INT, 0, 777, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	
	return static_cast<int>(rand() * fraction * (double(max) - double(min) + 1.0) + double(min));
}