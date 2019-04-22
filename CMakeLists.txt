cmake_minimum_required(VERSION 3.9)
project(os-jit)

set(CMAKE_CXX_STANDARD 14)

add_executable(os-jit os-jit.cpp worker.cpp)
