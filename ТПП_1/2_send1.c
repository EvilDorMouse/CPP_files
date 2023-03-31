#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=10;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
int* a=new int[n];
if (rank==0)
{
    for (int i=0; i<n;i++)
    a[i]=i;
    MPI_Send(&a[2],4,MPI_INT,1,777,MPI_COMM_WORLD);
}
if (rank==1){
    for (int i=0; i<n;i++)
    a[i]=-1;
    MPI_Recv(&a[1],4,MPI_INT,0,777,MPI_COMM_WORLD,&stat);
}

  printf( "rank = %d, a: ",rank );
    for (int i=0; i<n;i++)
 printf( " %d ",a[i]);
printf( " \n ");
delete[]a;
MPI_Finalize();
return 0;
}

