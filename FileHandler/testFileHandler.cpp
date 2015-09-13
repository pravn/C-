#include "file_handler.h"
#include <fstream>
#include <iostream>
#include <memory>


void delFileHandler(FileHandler *f){std:: cout << "Deleting ptr" << std::endl; delete[] f;}

int main(int argc, char **argv){
    MPI_Init(&argc, &argv);
    int rank, size;
    std::ostringstream s;
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::string testFileString="testDumpFile";

        std::shared_ptr <FileHandler> fileHandlePtr = std::shared_ptr<FileHandler> (new FileHandler(testFileString));
	
	s << "Rank: " << rank << std::endl;
        s << "This is a monstrous conception." << std::endl
          << "Everything is broken." << std::endl;

        fileHandlePtr->write(s.str());

    MPI_Finalize();
    return(0);

    }
    
