cmake_minimum_required(VERSION 3.24)
project(711_2)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Graph.h)

add_executable(711_2 app.cpp Graph.cpp)
