README
------
This implementation creates log files for an MPI environment. Each rank dumps out a log file with a '_rank' at the end of the filename (implemented in 'FileHandler'). The actual writing out of the contents depends on the structure of what is to be dumped out. We pass around pointers to data and group the operations comprising the printing mechanism in a namespace to perform printing and logging. I found this more intuitive in this case than using a 'class', which is more to the point when we group arrays and objects and operations that are carried out on them.

I chanced upon a Scott Meyers' item in Effective C++ that answers this very exact problem. We can couple some functionalities by grouping them in a namespace. 


Driver program (main):

The code initializes a number of particles (float3 - x, y, z) in structure of arrays fashion (basically a very primitive imitation of the nbody simulator from NVIDIA's CUDA SDK sample). The idea is to implement a logging system. For each particle, we write out a log file as follows:


<br> "0. x" </br>

<br> "1. y" </br>

<br> "2. z" </br>


<br> "x value for particle 0" "y value for particle 0" "z value for particle 0" </br>

<br> "x value for particle 1" "y value for particle 1" "z value for particle 1" </br>

<br> "x value for particle 2" "y value for particle 2" "z value for particle 2" <br>
and so on.

This is done for each MPI rank, which then writes out a file with a _rank appended to it.

Ancillary use cases include 'vector' and 'map'. In subsequent posts, I hope to create some examples for the STL and templatization. We could use templates to extend the functionality of our code to handle both single and double precision arithmatic.
			

	
		
		











