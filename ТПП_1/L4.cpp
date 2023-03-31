#include <mpi.h>
#include <stdio.h>
int main(int argc, char* argv[]) {
	int j;
	long int n = 1000000000;
	double t1, t2, s(0);
	MPI_Init(&argc, &argv);
	t1 = MPI_Wtime();
	for (j = 0; j < n; j++)
		s = s + 0.00000000001 + 0.00000000001;
	t2 = MPI_Wtime();
	printf("n=%d MF=%f t= %f s=%f\n", 2 * n, (2.0 * n) / (1000000 * (t2 - t1)), t2 - t1, s);
	MPI_Finalize();
	return(0);
}