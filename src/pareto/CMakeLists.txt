include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(pareto
    less.cpp
    linked_queue.cpp
    locked_set.cpp
    naive_linked_queue.cpp
    naive_set.cpp
    priority_linked_queue.cpp
)
