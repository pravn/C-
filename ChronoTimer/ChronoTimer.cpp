#include <iostream>
#include <memory>
#include "ChronoTimer.h"
#include <unistd.h>

main(){
  std::unique_ptr<ChronoTimer> chronoTimer(new ChronoTimer);
  
  chronoTimer->startTimer();
  
  //do something
  sleep(10);
  
  chronoTimer->stopTimer();

  std::cout << "Elapsed time 1: " << chronoTimer->getElapsedTime() << std::endl;

  chronoTimer->startTimer();
  sleep(2);
  chronoTimer->stopTimer();

  std::cout << "Elapsed time 2: " << chronoTimer->getElapsedTime() << std::endl;
    

}
