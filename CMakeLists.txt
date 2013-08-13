cmake_minimum_required(VERSION 2.8.0)

project(mcsp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

find_package(Check)
find_package(Doxygen)

find_library(LIBCGRAPH_LIBRARY cgraph)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions("-Wall -Wextra -pedantic -std=c++11 -O3")
endif()

if(DOXYGEN_FOUND)
    add_subdirectory(doc)
endif()

add_subdirectory(src)

if(CHECK_FOUND)
    enable_testing()
    add_subdirectory(test)
endif()
