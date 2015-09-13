README
------
This repository contains some of my experiments and implementations. 


Build with cmake. We need a C++ compiler (mine is gcc/4.8 when first created) which can 
provide c++-11. The build rules are in cmake. However, it should not be any more than 
adding -std=c++-11 to the build rules.  

mkdir build && cd build \n
cmake <path/to/src>  \n
make 


