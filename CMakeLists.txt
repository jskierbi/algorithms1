cmake_minimum_required(VERSION 3.12)
project(cpp_playground)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_playground src/01_quick_union/main.cpp src/01_quick_union/union_find.cpp src/01_quick_union/union_find.hpp)