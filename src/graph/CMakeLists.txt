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
