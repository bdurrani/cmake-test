cmake_minimum_required(VERSION 3.16.3)

# This will be the name of the 
# executable.
# This is also the source of the 
# version information
project(cmaketest VERSION 1.0)

# myglewlib is the variable
# glew is the actual lib

find_library(myglewlib glew NAMES glew2 GLEW GLEW2 DOC "glew library")

# 3.18 let's you skip all this via the newly
# added [REQUIRED] keyword for find_library
if (${myglewlib} STREQUAL myglewlib-NOTFOUND)
	message(FATAL_ERROR "no glew, sad day")
else()
	message(STATUS "glew found! as ${myglewlib}")
endif()

find_library(myglulib glu NAMES GLU DOC "glu library")
if (${myglulib} STREQUAL myglulib-NOTFOUND)
	message(FATAL_ERROR "no glu, sad day")
else()
	message(STATUS "glu found! as ${myglulib}")
endif()

find_library(mygllib gl NAMES GL DOC "gl library")
if (${mygllib} STREQUAL mygllib-NOTFOUND)
	message(FATAL_ERROR "no gl, sad day")
else()
	message(STATUS "gl found! as ${mygllib}")
endif()



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
  ${myglewlib} ${myglulib} ${mygllib}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/cmaketestConfig.h" DESTINATION include)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
