cmake_minimum_required(VERSION 3.0)

project(algocpp_math_test CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(tmp tmp.cpp)

target_link_libraries(tmp gtest_main gtest)