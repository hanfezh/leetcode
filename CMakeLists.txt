cmake_minimum_required(VERSION 3.0)

project(leetcode)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR on)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/algorithms)
