#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
	int rank, size;
	int n = 10;

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		cout << "---------(rank = " << rank << ")---------\n";
		int** a = new int* [size];
		a[0] = new int[size * n];

		for (int i = 1; i < size; i++)
		{
			a[i] = a[i - 1] + n;
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}

		for (int i = 1; i < size; i++)
		{
			MPI_Recv(a[i], n, MPI_INT, i, 777, MPI_COMM_WORLD, &stat);
		}

		cout << "A: \n";
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < n; j++)
			{
				
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		int* b = new int[n];

		cout << "---------(rank = " << rank << ")---------\n";
		
		cout << "B: \n";
		for (int i = 0; i < n; i++)
		{
			b[i] = 10 * (i + 1) + rank + 1;
			cout << b[i] << " ";
		}
		cout << endl;

		MPI_Send(&b[0], n, MPI_INT, 0, 777, MPI_COMM_WORLD);		
	}


	MPI_Finalize();
	return 0;
}