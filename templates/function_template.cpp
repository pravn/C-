#include <iostream>
#include <vector>

template <typename T>
void init(std::vector<T> &a, T val){
  std::cout << "val=" << val << std::endl;
  for(int i=0; i<a.size(); i++){
    a[i]=val;
  }
}


template <typename T>
void print(std::vector<T>a){
  std::cout << "Printing first 10 elements " << std::endl;

  int lmax=(a.size()>10)?10:a.size();

  for(int i=0; i<lmax; i++){
    std::cout << i << "\t" <<  a[i] << std::endl;
  }
    
 
}
  
main(){
  int n=20;
  std::cout << "Creating Vector of " << n << " ints." << std::endl;

  std::vector<int> a(n);
  
  init(a,1);

  print(a);

}
  
