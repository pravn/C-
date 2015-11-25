cmake_minimum_required(VERSION 2.8)
SET(CMAKE_BUILD_TYPE Debug)

SET(CMAKE_VERBOSE_MAKEFILE TRUE)

ADD_EXECUTABLE(function_template 
  function_template.cpp)

ADD_EXECUTABLE(class_template
  class_template.cpp)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

