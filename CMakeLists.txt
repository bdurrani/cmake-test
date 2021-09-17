cmake_minimum_required(VERSION 3.16.3)

# This will be the name of the 
# executable.
# This is also the source of the 
# version information
project(cmaketest VERSION 1.0)


# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external/poppler)
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external)
# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external/poppler/cmake/modules)

# specify the C++ standard
# Grabbed this from here: 
# https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html#adding-a-library-step-2
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_ADDER "A simple addition lib" ON)

# optional library logic
if(USE_ADDER)
  add_subdirectory(adder)

  list(APPEND EXTRA_LIBS adder)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/adder")
  list(APPEND EXTRA_LINKS adder)

endif()

configure_file(cmaketestConfig.h.in cmaketestConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(external/glfw)
# can't get poppler to build directly
# add_subdirectory(external/poppler)

target_include_directories(${PROJECT_NAME} 
    PUBLIC "${PROJECT_SOURCE_DIR}/external/glfw/include"
    ${EXTRA_INCLUDES}
)

target_link_directories(${PROJECT_NAME}
  PRIVATE external/glfw/src
  ${EXTRA_LIBS}
)

# Need this to link glfw, but not adder
target_link_libraries(${PROJECT_NAME} 
  ${EXTRA_LINKS} 
  glfw
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_NAME}/cmaketestConfig.h" DESTINATION include)
