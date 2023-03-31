#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int i, s = 0;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int* b = new int[3];
	for (i = 0; i < 3; i++)
		b[i] = rank;
	int* a = new int[3 * size];
	MPI_Gather(b, 3, MPI_INT, a, 3, MPI_INT, 0, MPI_COMM_WORLD);
	for (i = 0; i < 100000000 * rank; i++)
		s += 1;
	if (rank == 0)
	{
		cout << "\trank = " << rank << endl;
		cout << "\ta: ";
		for (i = 0; i < 3 * size; i++)
			cout << " " << a[i];
		cout << endl;
	}
	MPI_Finalize();
	return 0;
	}