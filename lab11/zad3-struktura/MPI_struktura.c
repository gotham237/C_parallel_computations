#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#include <unistd.h>

#include "mpi.h"

struct rekord {
  char imie[10];
  int liczba_int;
  double liczba_double;
}

int main( int argc, char** argv ){ 
  
  int rank, ranksent, size, source, dest, tag, i;
  MPI_Status status;
  struct rekord r;

  strcpy(r1.imie, "Szymon");
  r1.liczba_int = 0;
  r1.liczba_double = 0.0;
  
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &rank );
  MPI_Comm_size( MPI_COMM_WORLD, &size );

  
  
  if(size>1){
    
    if( rank != 0 ){ dest=0; tag=0; 

      dest=0;
      gethostname(name, 50);
      MPI_Send( &rank, 1, MPI_INT, dest, tag, MPI_COMM_WORLD );
      MPI_Send( &name, 50, MPI_CHAR, dest, 1, MPI_COMM_WORLD );
      
    } else {

      for( i=1; i<size; i++ ) { 

	      MPI_Recv( &rank, 1, MPI_INT, i, 0, MPI_COMM_WORLD, &status );
        MPI_Recv( &name, 50, MPI_CHAR, i, 1, MPI_COMM_WORLD, &status) ;
	      printf("Dane od procesu o randze (status.MPI_SOURCE ->) %d: %d (i=%d)\n", 
	      status.MPI_SOURCE, rank, i );
        printf("Przesyłam rank: %d, przesylam znaki: %s\n", rank, name);
      }
      
    }

  }
  else{
	printf("Pojedynczy proces o randze: %d (brak komunikatów)\n", rank);
  }

  
  MPI_Finalize(); 
  
  return(0);

}

