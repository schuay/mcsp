include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(graph
    edge.cpp
    graph.cpp
    node.cpp
)

target_link_libraries(graph
    ${LIBCGRAPH_LIBRARY}
)

add_executable(graph_test
    graph_test.cpp
)

target_link_libraries(graph_test
    graph
)
