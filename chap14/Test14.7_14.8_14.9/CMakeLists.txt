cmake_minimum_required(VERSION 3.22)
project(Test14.7_14.8_14.9)

set(CMAKE_CXX_STANDARD 17)
add_executable(${PROJECT_NAME} worker0.h worker0.cpp worktest.cpp)