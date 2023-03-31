
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int a;
	double st1, st2;
	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int n = 100000000;
	int* a = new int [n];
	int* b = new int [n];;
	

	if (rank == 0)
	{
		for (int i = 0; i < n; i++)
			a[i] = 0;

		st1 = MPI_Wtime();
		MPI_Sendrecv(a, n, MPI_INT, 1, 777, b, n, MPI_INT, 1, 777, MPI_COMM_WORLD, &stat);
		st2 = MPI_Wtime();

		cout << "rank: " << rank << "\ttime: " << (st2 - st1) << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	if (rank == 1)
	{
		int* b = new int[n];
		for (int i = 0; i < n; i++)
			b[i] = 1;

		st1 = MPI_Wtime();
		MPI_Sendrecv(b, n, MPI_INT, 0, 777, a, n, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
		st2 = MPI_Wtime();

		cout << "rank: " << rank << "\ttime: " << (st2 - st1) << "\n";
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	MPI_Finalize();
	return 0;
}