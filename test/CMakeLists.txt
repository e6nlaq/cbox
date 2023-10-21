cmake_minimum_required(VERSION 3.5)

project(cbox_test CXX)
set(CMAKE_CXX_STANDARD 23)

add_executable(is_option is_option.cpp)
add_executable(options_check options_check.cpp)

target_link_libraries(is_option gtest_main gtest)
target_link_libraries(options_check gtest_main gtest)
