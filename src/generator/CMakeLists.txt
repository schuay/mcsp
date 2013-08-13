include_directories(
    ${CMAKE_SOURCE_DIR}/uthash/src
)

add_library(generator
    generator.cpp
)

target_link_libraries(generator
    graph
)
