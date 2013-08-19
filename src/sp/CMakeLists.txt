include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(sp
    path.cpp
    shortest_paths.cpp
)

target_link_libraries(sp
    graph
)
