cmake_minimum_required(VERSION 3.25)
project(Prim)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Graph.h)

add_executable(Prim main.cpp Graph.cpp)
