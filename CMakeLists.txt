cmake_minimum_required(VERSION 3.12)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_playground src/main.cpp src/linked_list.hpp src/union_find.cpp src/union_find.hpp)