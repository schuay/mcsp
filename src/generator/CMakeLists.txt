include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(generator
    generator.cpp
)

target_link_libraries(generator
    graph
)

add_executable(gengraph
    gengraph.cpp
)

target_link_libraries(gengraph
    generator
)
