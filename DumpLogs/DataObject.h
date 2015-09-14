#ifndef _DATA_OBJECT_
#define _DATA_OBJECT_ 
#include <vector>
#include <cassert>
#include <map>
#include <string>
#include <iostream>

struct float3{
  float x[3];


  float3(){
    x[0] = 0.0f;
    x[1] = 0.0f;
    x[2] = 0.0f;
  }

  float3(float t){
    x[0] = t;
    x[1] = t;
    x[2] = t;
  }

  float3(float xval, float yval, float zval){
    x[0] = xval;
    x[1] = yval;
    x[2] = zval;
  }
    
};


//TODO: templatize this to handle double
class DataObject{
 public:
  //Let us create a particle for fun
  std::vector<float3> positions;

 std::string getName(size_t i) const {
    assert(i<sizeof(float3)/sizeof(float));
    return const_cast<DataObject*> (this)->name[i];
  }

  DataObject(size_t n){
    std::cout << "Requests n=" << n << " particles " << std::endl;
    positions.resize(n);


    //explicitly initialize a 'zero' vector
    float3 zero(0.0f);

    for(std::vector<float3>::iterator it = positions.begin(); it<positions.end(); it++){
      *it = zero;
    }

    name.insert(std::make_pair(0, "x"));
    name.insert(std::make_pair(1, "y"));
    name.insert(std::make_pair(2, "z"));

  }


const size_t getSize() const {
    return positions.size();
  }
  
const size_t getParticleSize() const{
  return this->particleSize;
  }

void  randomize(){
    for(size_t i=0; i<positions.size(); i++){
      positions[i].x[0] = rand()/RAND_MAX -1.0f;
      positions[i].x[1] = rand()/RAND_MAX -1.0f;
      positions[i].x[2] = rand()/RAND_MAX -1.0f;
    }
  }

  
  void setZero(){
    float zero(0.0f);
    for(size_t i=0; i<positions.size(); i++){
      positions[i] = zero;
    }
  }


void  setUnity(){
  float3 one(1.0f);
    for(size_t i=0; i<positions.size(); i++){
      positions[i] = one;
    }
}   

  void setTwo(){
    float3 two(2.0f);
    for(size_t i=0; i<positions.size(); i++){
      positions[i] = two;
    }
  }


 void print(){
   std::cout << "Printing particle sizes and header information " << std::endl;
   for(size_t i=0; i<getParticleSize(); i++){
     std::cout << getName(i) << std::endl;
   }


   std:: cout << "Printing attributes of each particle: " << std::endl;

   for (size_t i=0; i<getSize(); i++){
     std::cout << i << " " << getName(0) << " " << positions[i].x[0] << std::endl;
     std::cout << i << " " << getName(1) << " " << positions[i].x[1] << std::endl;
     std::cout << i << " " << getName(2) << " " << positions[i].x[2] << std::endl;
   }
 }


   void print_keys(){
     std::cout << "Printing keys (char tag for particle element dimensions)" << std::endl;
     std::cout << "particleSize (dimensions) : " << getParticleSize() << std::endl;
       

     for (int i=0; i<getParticleSize(); i++){
       std::cout << "Dimension " << i << ":" << getName(i) << std::endl;
     }
   }

 private:
  std::map<size_t, std::string> name;
  const size_t particleSize = sizeof(float3)/sizeof(float);

};

#endif    


