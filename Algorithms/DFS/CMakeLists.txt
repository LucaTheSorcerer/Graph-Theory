cmake_minimum_required(VERSION 3.25)
project(DFS)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS Graph.h)

add_executable(DFS main.cpp Graph.cpp)
