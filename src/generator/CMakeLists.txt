include_directories(
    ${CMAKE_SOURCE_DIR}/uthash/src
)

add_library(generator
    generator.cpp
)

target_link_libraries(generator
    graph
)

add_executable(generator_test
    generator_test.cpp
)

target_link_libraries(generator_test
    generator
)
