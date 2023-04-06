cmake_minimum_required(VERSION 3.25)
project(712_2)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        Graph.h
        )

add_executable(712_2 main.cpp Graph.cpp Graph.h)
