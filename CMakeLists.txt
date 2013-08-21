cmake_minimum_required(VERSION 2.8.0)

project(mcsp)

if(NOT PHEET_PATH)
    set(PHEET_PATH "${CMAKE_SOURCE_DIR}/../pheet")
endif()

find_package(Doxygen)
find_package(GTest)
find_package(Threads)

find_library(LIBCGRAPH_LIBRARY cgraph)

find_path(PHEET_INCLUDE_DIR pheet/pheet.h PATHS ${PHEET_PATH})
if(PHEET_INCLUDE_DIR)
    message(STATUS "Pheet found in ${PHEET_INCLUDE_DIR}")
else()
    message(FATAL_ERROR "Pheet not found")
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions("-Wall -Wextra -pedantic -std=c++11")
endif()

enable_testing()

add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(test)
