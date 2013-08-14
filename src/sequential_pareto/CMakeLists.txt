include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(sequential_pareto
    sequential_pareto.cpp
)

target_link_libraries(sequential_pareto
    graph
)

add_executable(sequential_pareto_test
    sequential_pareto_test.cpp
)

target_link_libraries(sequential_pareto_test
    generator
    sequential_pareto
)
