#include <memory>
#include <iostream>
#include "DataObject.h"
#include "dump_logs.h"

int main(int argc, char **argv){

  //we will run with 3 ranks 
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  //we will run on 3 ranks 
  //Each rank is initialized with particles with different inputs 
  //See below for how they are initialized

  //Exit if rank!=3
  if(size!=3) {
    std::cout << "Must run on 3 ranks. Abort." << std::endl;
    MPI_Finalize();
    exit(0);
  }
  
      const int numBodies = 100;

  //We will initialize on three ranks
  //Rank 0 will initialize with zeros;
  //Rank 1 with 1s 
  //Rank 2 with 2s

  //Structure of arrays. 
  DataObject particles(numBodies);

  if(rank==0){
    particles.setZero();
  }
  else if(rank==1){
    particles.setUnity();
  }
  else if(rank==2){
    particles.setTwo();
  }
  
  particles.print_keys();
  
  Logs::DumpLogs dumpLogs(&particles);
  dumpLogs.dumpLogs();
  
  MPI_Finalize();
  return(0);

}


  
  

  
  

  

