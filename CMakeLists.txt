cmake_minimum_required(VERSION 3.6)
project(SieveOfEratosthenes)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")

add_executable(SieveOfEratosthenes SieveOfEratosthenes.cpp)
