README
------
This implementation creates log files for an MPI environment. 
Each rank dumps out a log file with a '_rank' at the end of the filename (implemented in 'FileHandler').
The actual writing out of the contents depends on the structure of what is to be dumped out. 
In this case, they belong to a class. 

The conundrum I was faced with was in deciding how to piece together the somewhat disparate contents of 
printing out the elements comprising the class with the mechanism that appends a tag at the end of the file. 

To part that writes out the contents could be designed as a member of the class that holds the data. I had, however, 
assumed (perhaps for neatness) that the way the print class is designed should be modifiable - i.e. it should be 
within the user's control as long as he has access to the data (this opens up another issue regarding the private/publicness) 
of the data, and I may have had compromise in order to get on with it). Furthermore, it is clear that the piece that 
appends the mpi rank tag at the end of the file is also separate from the others. This is the crux of the design difficulties 
I had to reconcile, which I relate below.

Spelling it out more compactly, we have the following pieces in play:

1) Driver program produces data (embedded in a class).
2) Client handles how data is printed (formatting, etc.).
3) Printing is done by each MPI rank. 
4) 1), 2) and 3) are independent. In particular, 2) and 3) should not form part of a class. I would reckon that we \
could properly handle these objections by creating a derived class containing 2) and 3) as members. But we do not 
use inheritance in this case. 

Implementation
--------------
1) and 2) can be addressed by handing the print mechanism the data, which the driver program passes 
around as an object. We then ask the log file name generator (MPI File handler) to create these. The name itself is decided 
by the print mechanism, and the file name generator's task is only to create these names for each rank. 

As mentioned above, we do NOT want any shared membership between the printer and the log file generator. 
I had a very hard time wrapping my head around this for some reason. We could simply decide that the file handler and print mechanism 
are separate entities and in essence, do not have any kind of connection - sort of designed in a 'C' style way. 
However, I would like to think that they do indeed share a connection, albeit in a very loose and subtle way. 

I chanced upon Scott Meyers' item in Effective C++ that answers this very exact problem. We can couple these functionalities 
by grouping them in a namespace. 


namespace Logs{
	  
	  class DumpLogs{
			 public:	
	  	  	 	DumpLogs(const class *data){
					       workingData = data; 
					       		   

				dumpLogImplementation(){
					Create name of files = fileName
					Call MPI file handler to append a '_rank' to the end of fileName
					Now do the printing/logging
				}
					
					

	  		private: 
	  	      		 <Some Type, could be class or struct or anything> *workingData;

	      	    	  }	  	  

	   MPIFileHandler *fileHandler; //or use smart pointer
	   <other attributes> 
	   };


Client code:

       dumpLogImplementation(){
		fileHandler = new FileHandler(attribs);
		
		write out implementation for logging

		delete fileHandler;

		}



		
		
		











