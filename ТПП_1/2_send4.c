#include <stdio.h>
#include "mpi.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
int rank;
int size;
int n=15,s=0;
MPI_Status stat;
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

if (rank==0)
{
int* a=new int[5*size];
    for (int i=0; i<5*size;i++)
    a[i]=i;
     for (int i=1; i<size;i++)
    MPI_Send(&a[5*i],5,MPI_INT,i,777,MPI_COMM_WORLD);
    delete[]a;
    int* c=new int[size];
    for (int i=1; i<size;i++)
     MPI_Recv(&c[i],1,MPI_INT,i,777,MPI_COMM_WORLD,&stat);
      printf( "rank = %d, c: ",rank );
    for (int i=0; i<size;i++)
 printf( " %d ",c[i]);
printf( " \n ");
      delete[]c;
}
else
{
int* b=new int[5];
    MPI_Recv(b,5,MPI_INT,0,777,MPI_COMM_WORLD,&stat);
        for (int i=0; i<5;i++)
    s+=b[i];
MPI_Send(&s,1,MPI_INT,0,777,MPI_COMM_WORLD);
 
delete[]b;

}


//sleep(rank);


MPI_Finalize();
return 0;
}

