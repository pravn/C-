#include <iostream>
#include <vector>

template <typename T>
class SmartArray{
public:
  SmartArray(int n_in): n(n_in)
  { 
    a = new T[n];
    std::cout << "Created array of size " << n << std::endl;

    init(0);
  }


  void init (T val){
    for(int i=0; i<n; i++){
      a[i]=val;
    }
  }


    void print(){
      //first 10 elements
      for (int i=0; i<((n>10)?10:n); i++){
	std::cout << i << "\t" << a[i] << std::endl;
      }
    }


  ~SmartArray(){
    std::cout << "Destroying array " << std::endl;
    delete[] a;
  }

  
private:
  int n;
  T *a;
  };


  int main(){
    int n=20;
    
  std::cout << "Creating Vector of " << n << " ints." << std::endl;
  SmartArray<int> a_int(n);
  a_int.print();


  std::cout << "Creating Vector of " << n << " floats." << std::endl;
  SmartArray<float> a_float(n);
  
  a_float.init(1);

  a_float.print();
  
  }

  



