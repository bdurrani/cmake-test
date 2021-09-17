cmake_minimum_required(VERSION 3.16.3)
# This will be the name of the 
# executable
project(cmake-test)

# specify the C++ standard
# Grabbed this from here: 
# https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html#adding-a-library-step-2
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)

target_link_libraries(${PROJECT_NAME} adder)

# This does not look like a requirement
# But I'll leave this here anyway
# target_link_directories(${PROJECT} PUBLIC adder)

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/adder")