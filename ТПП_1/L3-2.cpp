#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
	int rank, size;

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		cout << "---------(rank = " << rank << ")---------\n";
		int m = size * (size + 1) / 2;

		int* a0 = new int[m];

		a0[0] = 0;

		for (int j = 1; j < size; j++)
		{
			MPI_Recv(&a0[j * (j + 1) / 2], j + 1, MPI_INT, j, 777, MPI_COMM_WORLD, &stat);
		}

		cout << "M: ";
		for (int i = 0; i < m; i++)
		{
			cout << a0[i] << " ";
		}
		cout << endl;
	}
	else
	{
		int* a = new int[rank + 1];

		cout << "---------(rank = " << rank << ")---------\n" << "M: ";
		for (int i = 0; i < rank + 1; i++)
		{
			a[i] = rank;
			cout << a[i] << " ";
		}
		cout << endl;

		MPI_Send(&a[0], rank + 1, MPI_INT, 0, 777, MPI_COMM_WORLD);
	}

	MPI_Finalize();
	return 0;
}