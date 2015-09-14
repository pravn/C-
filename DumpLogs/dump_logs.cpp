#include "dump_logs.h"
#include <string>
#include <iostream>
#include <memory>
#include <sstream>
#include <iomanip>

//Deleting singlet file pointers
void Logs::delFileHandler(FileHandler *f){
  #ifdef PRINT_DEBUG
  std:: cout << "Deleting ptr" << std::endl; 
  #endif
  delete f;
}

void Logs::delVecFileHandler(FileHandler *f){
   delete[] f;
 }


void Logs::write_header(const DataObject *obj, std::shared_ptr<FileHandler>fileHandlePtr){
  assert((obj!=NULL) && (fileHandlePtr));
const size_t n=obj->getParticleSize();
  std::ostringstream hdr;
  
  for(size_t i=0; i<n; ++i){
    hdr << "# ";
    hdr << i << ". ";  
    hdr << obj->getName(i) << std::endl;
  }
    fileHandlePtr->write(hdr.str());
}

void Logs::write_data(const DataObject *t, std::shared_ptr<FileHandler>fileHandlePtr){
  assert((t!=NULL)&&(fileHandlePtr)); 
  std::ostringstream ss;

  ss.precision(2);
  ss << std::fixed;

  for(size_t i=0; i<t->getSize(); ++i){
    for(size_t j=0; j<t->getParticleSize(); ++j){
      ss << std::setw(8) << t->positions[i].x[j];

	if(j!=t->getParticleSize()-1){
	ss << " ";
      }
    }
    ss << std::endl;
  }

  fileHandlePtr->write(ss.str());
}

  
void Logs::dumpLogs(const DataObject *u){

  const DataObject *data = u;

  std::ostringstream dumpStringstream;
  std::string dumpFileString = "dump";

  std::ostringstream ss;

  ss << dumpFileString;

  
  std::shared_ptr<FileHandler> fileHandlePtr = std::shared_ptr<FileHandler> (new FileHandler(ss.str()), delFileHandler);

  write_header(data, fileHandlePtr);
  write_data(data, fileHandlePtr);

  }

       
     
