cmake_minimum_required(VERSION 3.24)
project(L1)

set(CMAKE_CXX_STANDARD 17)
set(PROJECT_HEADERS
        Graph.h
        )
set(PROJECT_SOURCES
        app.cpp
        Graph.cpp
        )

add_executable(L1 app.cpp Graph.cpp)
