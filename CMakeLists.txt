cmake_minimum_required(VERSION 3.5)  # Minimum version of CMake

project(MyProject)  # Name of your project

# Set C++14 standard
set(CMAKE_CXX_STANDARD 14)

# Google Test setup
add_subdirectory(googletest)  # Add googletest subdirectory
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})  # Include Google Test headers

# Define executable
add_executable(us gs.cpp)  # Create executable "us" from "gs.cpp"

# Link Google Test libraries
target_link_libraries(us gtest gtest_main pthread)
