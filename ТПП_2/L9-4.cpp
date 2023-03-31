#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int i, s = 0, j;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int** a = new int* [2];
	a[0] = new int[(rank + 1)* 2];
	for (i = 1; i < 2; i++)
		a[i] = a[i - 1] + (rank + 1);

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < rank + 1; j++)
			a[i][j] = rank;

	int** b = new int* [size];
	b[0] = new int[size * 2 * size];
	for (i = 1; i < size; i++)
		b[i] = b[i - 1] + 2*size;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < 2*size; j++)
			b[i][j] = -1;

	int* RC = new int[size];
	for (int i = 0; i < size; i++)
		RC[i] =2*( i + 1);

	int* ds = new int[size];
	for (int i = 0; i < size; i++)
		ds[i] = i *2* size;

MPI_Gatherv(*a,2*(rank+1),MPI_INT,*b,RC,ds,MPI_INT,0,MPI_COMM_WORLD);

	if (rank == 0)
	{
		printf("rank = %d a: \n", rank);
		for (i = 0; i < size ; i++)
		{
			for (j = 0; j <size*2 ; j++)
				printf(" %d ", b[i][j]);
			printf("\n ");
		}
	}

	MPI_Finalize();
	return 0;
}