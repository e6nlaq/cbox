cmake_minimum_required(VERSION 3.5)

project(cbox_test CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(./algocpp/includes/)

add_executable(is_option is_option.cpp)
add_executable(options_check options_check.cpp)
add_executable(fill_zero fill_zero.cpp)

target_link_libraries(is_option gtest_main gtest)
target_link_libraries(options_check gtest_main gtest)
target_link_libraries(fill_zero gtest_main gtest)
