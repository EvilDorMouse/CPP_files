#include <stdio.h>
#include "mpi.h"
int main(int argc, char* argv[])
{
	int rank;
	int size;
	int i, s = 0;
	MPI_Status stat;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int* a = new int[size * (size + 1)];
	if (rank == 0)
		for (i = 0; i < size * (size + 1); i++)
		a[i] = i;

	int* b = new int[(rank +1)*2];
	int* RC = new int[size];
	int* ds = new int[size];

	for (int i = 0; i < size; i++)
	{
		RC[i] = 2*(i+1);
		ds[i] = (i+2)*(i+1);
	}

	MPI_Scatterv(a, RC, ds, MPI_INT, b, rank + 1, MPI_INT, 0, MPI_COMM_WORLD);
	
	for (i = 0; i < 100000000 * rank; i++)
		s += 1;

	printf("rank= %d b: ", rank);
	for (i = 0; i < (rank + 1) * 2; i++)
		printf(" %d ", b[i]);

	printf("\n ");
	MPI_Finalize();
	return 0;
}