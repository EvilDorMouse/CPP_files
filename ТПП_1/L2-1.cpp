#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
	int rank, size;
	int a(0);

	MPI_Status stat;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

		if (rank == 0)
		{
			a = 1;
			MPI_Send(&a, 1, MPI_INT, 1, 777, MPI_COMM_WORLD);
			cout << "---------(rank = " << rank  << ")---------"<< endl;
			cout << "res = " << a << endl;
			MPI_Recv(&a, 1, MPI_INT, 0, 777, MPI_COMM_WORLD, &stat);
			cout << "---------(rank = " << rank << ")---------" << endl;
		}
		else if (rank == size - 1)
		{
			MPI_Recv(&a, 1, MPI_INT, size - 2, 777, MPI_COMM_WORLD, &stat);
			a++;
			MPI_Send(&a, 1, MPI_INT, 0, 777, MPI_COMM_WORLD);
			cout << "---------(rank = " << rank << ")---------" << endl;
		}
		else
		{
			MPI_Recv(&a, 1, MPI_INT, rank - 1, 777, MPI_COMM_WORLD, &stat);
			a++;
			MPI_Send(&a, 1, MPI_INT, rank + 1, 777, MPI_COMM_WORLD);
			cout << "---------(rank = " << rank << ")---------" << endl;
		}

	cout << "res = " << a << endl;

	MPI_Finalize();
	return 0;
}