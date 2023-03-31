#include <stdio.h>
#include "mpi.h"
int main(int argc, char* argv[])
{
	int rank;
	int size;
int n = 0, i, j, s = 0;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	 MPI_Comm_size(MPI_COMM_WORLD, &size);

	 if (rank == 0) scanf("%d", &n);

	 MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

	 int** a = new int* [size];
	 a[0] = new int[n * size];

	 for (i = 1; i < size; i++)
		 a[i] = a[i - 1] + n;

	 if (rank == 0)
		 {
		 for (i = 0; i < size; i++)
			 for (j = 0; j < n; j++)
			 a[i][j] = i;
		 }

	int* b = new int[n];

	 MPI_Scatter(*a, n, MPI_INT, b, n, MPI_INT, 0, MPI_COMM_WORLD);

	for (i = 0; i < 100000000 * rank; i++)
		 s += 1;

	 printf("rank= %d b: \n", rank);
	 for (i = 0; i < n; i++)
	 printf(" %d ", b[i]);
	 printf("\n");
	 MPI_Finalize();
	return 0;
	 }