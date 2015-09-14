
#include <vector>
#include <memory>
#include <fstream>
#include "DataObject.h" 
#include "file_handler.h"

namespace Logs{

#ifndef DUMPLOGS_H
#define DUMPLOGS_H



 //convenience routines called from dumpLogs();
 //We could ideally declare them as part of the class itself
 //However, this is a custom 'hack' in the sense that it recognizes 
 //that the data can be written as a common header file and data. So we just declare them loosely.


void dumpLogs(const DataObject *data);

  void write_header(const DataObject *data, std::shared_ptr<FileHandler> fileHandlePtr);
  void write_data(const DataObject *data, std::shared_ptr<FileHandler> fileHandlePtr);

 void delFileHandler(FileHandler *f);
 void delVecFileHandler(FileHandler *f);

#endif

}


