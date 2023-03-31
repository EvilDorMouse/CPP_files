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
		cout << "---------(rank = " << rank << ")---------" << endl;
		int *a = new int [2*size];

		cout << "A: " << endl;
		for (int i = 0; i < 2 * size; i++)
		{
			a[i] = i;
			cout << a[i] << " ";
		}
		cout << endl;

		for (int j = 1; j < size; j++)
		{
			for (int i = j; i < 2 * size; i += size)
			{
				MPI_Send(&a[i], 1, MPI_INT, j, 777, MPI_COMM_WORLD);
			}
		}
	}
	else
	{
		int* b = new int[2];
		for (int i = 0; i < 2; i++)
		{
			MPI_Recv(&b[i], 1, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
		}
		cout << "---------(rank = " << rank << ")---------" << endl;
		cout << "B: " << b[0] << " " << b[1] << endl;
	}
	

	MPI_Finalize();
	return 0;
}