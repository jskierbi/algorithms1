cmake_minimum_required(VERSION 3.10)
project(algorithms1)

set(CMAKE_CXX_STANDARD 14)

################################
# GTest
################################
ADD_SUBDIRECTORY(gtest-1.8.1)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable(runUnitTests test/main.cpp test/01_quick_union/union_find_test.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gtest_main pthread)
add_test(runUnitTests runUnitTests)

add_executable(algorithms1 src/01_quick_union/main.cpp src/01_quick_union/union_find.cpp src/01_quick_union/union_find.hpp)