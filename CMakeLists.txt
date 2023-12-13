cmake_minimum_required(VERSION 3.10.2)
project(rational_operator_overload_assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(rational_operator_overload_assignment main.cpp rational.cpp rational.h)
