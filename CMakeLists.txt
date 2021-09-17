cmake_minimum_required(VERSION 3.16.3)
# This will be the name of the 
# executable
project(cmake-test)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external/poppler)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external)

# specify the C++ standard
# Grabbed this from here: 
# https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html#adding-a-library-step-2
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)


message("${CMAKE_MODULE_PATH}")
add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(adder)
add_subdirectory(external/glfw)
add_subdirectory(external/poppler)

target_link_libraries(${PROJECT_NAME} adder)

target_link_directories(${PROJECT_NAME}
  PRIVATE external/glfw/src
)

# Need this to link glfw, but not adder
target_link_libraries(${PROJECT} adder glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_SOURCE_DIR}/adder"
    PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/include"
)