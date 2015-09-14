#ifndef _FILEHANDLER_
#define _FILEHANDLER_

#include <string>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <mpi.h>


class FileHandler{
public:
  FileHandler(std::string fileName){
    assert(fileName.length()>0);
    std::ostringstream ss;
    ss << fileName << "_" << rank() << ".txt"; 
    file_handle.open(ss.str(),std::ios::out);
  }

  void write(std::string s){
    file_handle << s; 
  }

  ~FileHandler(){
        file_handle.close();
  }

  int rank(){
    MPI_Comm_rank(MPI_COMM_WORLD, &this->r);
      return this->r;
    }

  int size(){
      MPI_Comm_size(MPI_COMM_WORLD, &this->s);
      return this->s;
    }

 private:
  int r;
  int s;
  std::ofstream file_handle;
};
    
#endif


       
     
