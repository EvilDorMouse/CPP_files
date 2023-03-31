#include <stdio.h>
#include "mpi.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
int rank;
int size;
int i, s = 0;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

int* b = new int[size - rank];
for (i = 0; i < size - rank; i++)
	b[i] = rank;
int* a = new int[(size * (size + 1)) / 2];
int* RC = new int[size];
int* ds = new int[size];

for (int i = size; i > 0; i--)
	RC[size - i] = i;

ds[0] = 0;
for (int i = size; i > 1; i--)
ds[size - i + 1] = (2 * i + (size - i)) * (size - i + 1) / 2;

MPI_Gatherv(b, size - rank, MPI_INT, a, RC, ds, MPI_INT, 0, MPI_COMM_WORLD);

if (rank == 0)
{
	printf("rank= %d a: ", rank);
	for (i = 0; i < (size * (size + 1)) / 2; i++)
		printf(" %d ", a[i]);
	printf("\n ");
}

MPI_Finalize();
return 0;
}