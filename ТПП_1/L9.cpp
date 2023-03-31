
#include "mpi.h"
#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;

void Broadcast(void* buffer, int count, MPI_Datatype datatype, int root);

int main(int argc, char* argv[])
{
	double t0, t;
	double bt0, bt;
	int n = pow(10, 9);
	double* a = new double[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}

	MPI_Init(&argc, &argv);

	t0 = MPI_Wtime();
	Broadcast(&a[0], n, MPI_DOUBLE, 0);
	t = MPI_Wtime();
	cout << "MYf = " << t - t0 << endl;

	bt0 = MPI_Wtime();
	MPI_Bcast(&a, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	bt = MPI_Wtime();
	cout << "System = " << bt - bt0 << endl;

	MPI_Finalize();
	return 0;
}

void Broadcast(void* buffer, int count, MPI_Datatype datatype, int root)
{
	int rank;
	int size;

	int i = 0;
	int k = 0;

	MPI_Status stat;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// ------------------------------------

	int NowIt;
	int temp1 = log(rank+1) / log(2);
	double temp2 = log(rank+1) / log(2);

	if (temp2 - temp1 == 0)
	{
		NowIt = temp1;
	}
	else
	{
		NowIt = temp1 + 1;
	}
	i = NowIt;
	k = rank + pow(2, i);

	// ------------------------------------

	
	if (rank == root)
	{
		while (k < size)
		{
			i++;

			MPI_Send(buffer, count, datatype, k, 777, MPI_COMM_WORLD); 
			cout << "rank = " << rank << ", send to " << k << "\n";

			k = rank + pow(2, i);
		}
	}
	else
	{
		double* n = new double[pow(10,9)];

		MPI_Recv(&n, count, datatype, MPI_ANY_SOURCE, 777, MPI_COMM_WORLD, &stat);

		while (k < size)
		{
			i++;

			MPI_Send(&n, count, datatype, k, 777, MPI_COMM_WORLD);
			cout << "rank = " << rank << ", send to " << k << ", n = " << n << "\n";

			k = rank + pow(2, i);
		}
	}
}