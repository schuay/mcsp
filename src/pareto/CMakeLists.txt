include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(pareto
    less.cpp
    linked_queue.cpp
    priority_linked_queue.cpp
)
