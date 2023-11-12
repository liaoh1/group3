cmake_minimum_required(VERSION 2.8)  # Minimum version of CMake

project(GSTestGroup3)  # Name of your project

# Set C++14 standard
set(CMAKE_CXX_STANDARD 14)

# Google Test setup
add_subdirectory(googletest)  # Add googletest subdirectory
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})  # Include Google Test headers

include_directories(${CMAKE_SOURCE_DIR})

add_executable(gs main.cpp gs.cpp) 

add_executable(test gsTest.cpp gs.cpp)  # Create executable "us" from "gs.cpp"

# Link Google Test libraries
target_link_libraries(test gtest gtest_main pthread)

