#include <stdio.h>
#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	int size0 = 0;
	int m = 0;

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);


	if (rank == 0)
	{
		int n = 2;

		if (size - 1 % 2 == 0)
			size0 = size - 1;
		else
			size0 = size - 2;
		
		MPI_Sendrecv(&n, 1, MPI_INT, rank + 2, 777, &m, 1, MPI_INT, size0, 777, MPI_COMM_WORLD, &stat);

		cout << "-----< " << rank << " >-----\n" << "\tm = " << m << "\n";
	}
	else if (rank == 1)
	{
		int n = 1;

		if (size - 1 % 2 != 0)
			size0 = size - 1;
		else
			size0 = size - 2;

		MPI_Sendrecv(&n, 1, MPI_INT, rank + 2, 777, &m, 1, MPI_INT, size0, 777, MPI_COMM_WORLD, &stat);

		cout << "-----< " << rank << " >-----\n" << "\tm = " << m << "\n";
	}
	else if (rank == size - 1 && (size - 1) % 2 == 0)
	{
		int m0 = m;
		m0++;
		cout << "-----< " << rank << " >-----\n" << "\tm = " << m;

		MPI_Sendrecv(&m0, 1, MPI_INT, 0, 777, &m, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
	}
	else if (rank == size - 1 && (size - 1) % 2 != 0)
	{
		int m0 = m;
		m0++;
		cout << "-----< " << rank << " >-----\n" << "\tm = " << m;

		MPI_Sendrecv(&m0, 1, MPI_INT, 1, 777, &m, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
	}
	else if (rank % 2 == 0 && size - 1 - rank >= 2)
	{
		int m0 = m;
		m0++;
		cout << "-----< " << rank << " >-----\n" << "\tm = " << m;
		
		MPI_Sendrecv(&m0, 1, MPI_INT, rank + 2, 777, &m, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
	}
	else if (rank % 2 != 0 && size - 1 - rank >=2)
	{
		int m0 = m;
		m0++;
		cout << "-----< " << rank << " >-----\n" << "\tm = " << m;

		MPI_Sendrecv(&m0, 1, MPI_INT, rank + 2, 777, &m, 1, MPI_INT, rank - 2, 777, MPI_COMM_WORLD, &stat);
	}

	MPI_Finalize();
	return 0;
}