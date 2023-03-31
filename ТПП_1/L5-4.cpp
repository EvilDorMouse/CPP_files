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
		int** a = new int* [3*size];
		a[0] = new int[3*size * n];

		for (int i = 1; i < 3*size; i++)
		{
			a[i] = a[i - 1] + n;
		}

		for (int i = 0; i < 3*size; i++)
		{
			for (int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}

		for (int i = 1; i < size; i++)
		{
			MPI_Recv(a[3*i], 3*n, MPI_INT, i, 777, MPI_COMM_WORLD, &stat);
		}

		cout << "---------(rank = " << rank << ")---------\n";
		cout << "A: \n";
		for (int i = 0; i < 3*size; i++)
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
		int** b = new int *[3];
		b[0] = new int[3 * n];

		for (int i = 1; i < 3; i++)
		{
			b[i] = b[i - 1] + n;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[i][j] = 10 * (i +3*rank + 1) + j + 1;
			}
		}

		cout << "---------(rank = " << rank << ")---------\n";

		cout << "B: \n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << b[i][j] << " ";
			}
			cout << "\n";
		}

		MPI_Send(b[0], 3*n, MPI_INT, 0, 777, MPI_COMM_WORLD);
		
	}


	MPI_Finalize();
	return 0;
}