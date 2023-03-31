#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int n = 0, i, s = 0, j;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if (rank == 0) 
		cin >> n;
	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	int** b = new int* [2];
	b[0] = new int[2 * n];

	for (int j = 0; j < 2; j++)
		for (i = 0; i < n; i++)
			b[j][i] = rank;

	int** a = new int* [2 * size];
	a[0] = new int[n * 2 * size];

	for (i = 1; i < 2 * size; i++)
		a[i] = 0;

	MPI_Gather(b, n, MPI_INT, *a, n, MPI_INT, 0, MPI_COMM_WORLD);
	if (rank == 0)
		{
		printf("rank= %d a: \n", rank);
		for (i = 0; i < size; i++)
			{
			for (j = 0; j < n; j++)
				printf(" %d ", a[i][j]);
			printf("\n ");
			}
		}
	MPI_Finalize();
	return 0;
	}