#include <chrono>
#include <ctime>

#ifndef _CHRONOTIMER_H
#define _CHRONOTIMER_H
class ChronoTimer{
 public:
  ChronoTimer(){
    startTime=std::chrono::system_clock::now();
    elapsedTime=startTime-startTime;
  }

  void startTimer(){
    startTime= std::chrono::system_clock::now();
  }

  void stopTimer(){
    stopTime = std::chrono::system_clock::now();
    elapsedTime += stopTime-startTime;
  }

  double getElapsedTime(){
    return elapsedTime.count();
  }

 private:
  std::chrono::time_point<std::chrono::system_clock> startTime;
  std::chrono::time_point<std::chrono::system_clock> stopTime;
  std::chrono::duration<double> elapsedTime;
};
#endif
