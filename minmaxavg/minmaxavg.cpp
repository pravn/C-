#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cassert>
#include <fstream>
#include <numeric>

struct Iteration{
  int num;
  float val;

  Iteration(int num, float val):num(num),val(val)
  {
  }

};

void compute_average(const std::vector<Iteration> v){
  float sum=0;
  std::vector<Iteration>::const_iterator i;
  for(i=v.begin();i!=v.end(); i++){
    sum +=i->val;
  }

  float average = sum/v.size();
  std::cout << "average over " << v.size() << " iterations = " << average << std::endl; 

}

void read_body(std::istream &is, std::vector<Iteration> &v){
    std::string line;
    int num;
    float val;

    while(getline(is, line, '\n')){
      std::istringstream iss(line);
      if(!(iss >> num >> val))
	std::cerr << "Malformed line, skipping: " << line << std::endl;
      else{
      v.push_back(Iteration(num, val));
      }
    }

  }


int main(){
  std::vector<Iteration> iteration_vector;

  std::ifstream filename;
  filename.open("iteration_values.txt", std::ios::in);

  if(!filename) {
    std::cout << "Could not open file :" << "iteration_values.txt\n" << "Bailing " << std::endl;
    return -1;
  }
  
  read_body(filename, iteration_vector);
  
  std::vector<Iteration>::iterator i;

  for(i=iteration_vector.begin(); i!=iteration_vector.end(); i++){
    std::cout << i->num << " " << i->val << std::endl;
  }

  filename.close();

  compute_average(iteration_vector);

  return 0;

}


  
    
  
      
    
    
