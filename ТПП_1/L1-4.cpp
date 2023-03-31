#include <stdio.h>
#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
	int rank, size;
	int n1 = pow(10,6), n2 = pow(10,7), n3 = pow(10,8), n4 = pow(10,9);
	double s = 0, s0 = 0;
	double t0, t1, dt;

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	t0 = MPI_Wtime();

	int n = n1;

	if (rank == 0)
	{
		for (int i = 1; i < size; i++)
		MPI_Send(&n, 1, MPI_INT, i, 777, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(&n, 1, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
	}
	
	for (int i = rank; i < n; i += size)
	s += 1.0/(1.0 + i);
	cout << "s = " << s << endl;
	
	if (rank == 0)
	{
		for (int i = 1; i < size; i++)
		{
		MPI_Recv(&s0, 1, MPI_DOUBLE, i, 777, MPI_COMM_WORLD, &stat);
		s += s0;
		}
		cout << "rank = " << rank << ", " << "n = " << n << ", " << "s = " << s << endl;
	}
	else
	{
		MPI_Send(&s, 1, MPI_DOUBLE, 0, 777, MPI_COMM_WORLD);
	}
	

	t1 = MPI_Wtime();

	dt = t1 - t0;
	cout << "time: " << dt << endl;

	MPI_Finalize();
	return 0;
}