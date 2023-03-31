#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "mpi.h"

using namespace std;

int main(int argc, char* argv[])
{
    int my_rank;
    int size;
    char name[MPI_MAX_PROCESSOR_NAME];
    int resultlen(0);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("Hello world! I'm rank (processor number) %d of %d processor \n", my_rank, size);
    
    double time = MPI_Wtick();
    cout << "Time: " << time << endl;

    cout << "MPI_Get_processor_name: ";
   
    MPI_Get_processor_name(name, &resultlen);
    cout << "name = " << name << ", " << "resultlen = " << resultlen << endl;

    MPI_Finalize();
    return 0;
}