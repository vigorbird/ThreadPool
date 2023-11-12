cmake_minimum_required(VERSION 3.0)


project(test)


set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

include_directories(./)

add_executable(test main.cpp)
