cmake_minimum_required(VERSION 3.8)
project(AlgorithmPractice)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Sort.h Sort.cpp DP.h DP.cpp KMP.cpp KMP.h)
add_executable(AlgorithmPractice ${SOURCE_FILES})