
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int a;
	double st1, st2, rt1, rt2;
	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	int n = 100000000;

	if (rank == 0)
	{
		int* a = new int [n];
		for (int i = 0; i < n; i++)
			a[i] = 0;

		int* b = new int[n];

		st1 = MPI_Wtime();
		MPI_Send(a, n, MPI_INT, 1, 777, MPI_COMM_WORLD);
		st2 = MPI_Wtime();

		rt1 = MPI_Wtime();
		MPI_Recv(b, n, MPI_INT, 1, 777, MPI_COMM_WORLD, &stat);
		rt2 = MPI_Wtime();
		
		cout << "rank: " << rank << "\ttime: " << (st2 - st1) + (rt2 - rt1) << "\n";
	}
	if (rank == 1)
	{
		int* a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = 1;

		int* b = new int[n];

		rt1 = MPI_Wtime();
		MPI_Recv(b, n, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
		rt2 = MPI_Wtime();

		st1 = MPI_Wtime();
		MPI_Send(a, n, MPI_INT, 0, 777, MPI_COMM_WORLD);
		st2 = MPI_Wtime();

		cout << "rank: " << rank << "\ttime: " << (st2 - st1) + (rt2 - rt1) << "\n";
	}
	MPI_Finalize();
	return 0;
}