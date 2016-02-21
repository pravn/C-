cmake_minimum_required(VERSION 2.8)

PROJECT(MINMAXAVG)

add_executable(minmaxavg minmaxavg.cpp)

file(COPY "${CMAKE_SOURCE_DIR}/iteration_values.txt" DESTINATION "${CMAKE_BINARY_DIR}")
