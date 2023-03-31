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
	int* b = new int[rank + 1];
	for (i = 0; i < rank + 1; i++)
		b[i] = rank;
	int* a = new int[(size * (size + 1)) / 2];
	int* RC = new int[size];
	int* ds = new int[size];
	for (int i = 0; i < size; i++)
		{
		RC[i] = i + 1;
		ds[i] = (i * (i + 1)) / 2;
		}
	MPI_Gatherv(b, rank + 1, MPI_INT, a, RC, ds, MPI_INT, 0, MPI_COMM_WORLD);
	for (i = 0; i < 100000000 * rank; i++)
		s += 1;
	printf("rank= %d a: ", rank);
	for (i = 0; i < (size * (size + 1)) / 2; i++)
		printf(" %d ", a[i]);
	printf("\n ");
	MPI_Finalize();
	return 0;
	}