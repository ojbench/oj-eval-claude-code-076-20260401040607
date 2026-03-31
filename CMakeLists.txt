cmake_minimum_required(VERSION 3.10)
project(problem_076)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include the src.hpp header
include_directories(${CMAKE_SOURCE_DIR})

add_executable(code main.cpp)
