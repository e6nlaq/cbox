cmake_minimum_required(VERSION 3.0)

project(cbox_test CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(is_option is_option.cpp)

target_link_libraries(is_option gtest_main gtest)