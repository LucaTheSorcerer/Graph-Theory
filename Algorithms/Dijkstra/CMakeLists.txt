cmake_minimum_required(VERSION 3.25)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS Graph.h)

add_executable(Dijkstra main.cpp Graph.cpp Graph.h)
