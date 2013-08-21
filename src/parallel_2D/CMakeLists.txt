include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(parallel_2D
    label_set.cpp
    local_label_map.cpp
    parallel_2D.cpp
)

target_link_libraries(parallel_2D
    graph
)

add_executable(parallel_2D_test
    parallel_2D_test.cpp
)

target_link_libraries(parallel_2D_test
    generator
    parallel_2D
)
