cmake_minimum_required(VERSION 3.8)

project(CBOX)

set(CMAKE_CXX_STANDARD 20)

include_directories("./include")
add_executable(cbox main.cpp)
