#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int rank;
	int size;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int n = 0;

	for (int i = size + 1; i > 1; i--)
		n += i;

	cout << "n = " << n << "\n";

	int* a = new int[size - rank + 1];
	for (int i = 0; i < size - rank + 1; i++)
		a[i] = rank;

	int* b = new int[n];
	
	for (int i = 0; i < n; i++)
		b[i] = 0;

	cout << "\trank = " << rank << "\n";
	cout << "\ta: ";
	for (int i = 0; i < size - rank + 1; i++)
		cout << " " << a[i];
	cout << "\n";

	int* r = new int[size];

	for (int i = 0; i < size; i++)
		r[i] = size - rank + 1;

	int* s = new int[size];
	s[size - 1] = size - rank + 1;
	for (int i = size + 1; i > 2; i--)
		s[i - 3] = i - 1 + s[i - 2];

	MPI_Gatherv(a, size - rank + 1, MPI_INT, b, r, s,MPI_INT, 0, MPI_COMM_WORLD);
	
	if (rank == 0)
	{
		cout << "-----end massive-----\n";
		cout << "\tb: ";
		for (int i = 0; i < n; i++)
			cout << " " << b[i];
		cout << "\n";
	}
	
	MPI_Finalize();
	return 0;
}