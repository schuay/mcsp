include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(sequential
    sequential.cpp
)

target_link_libraries(sequential
    graph
)

add_executable(sequential_test
    sequential_test.cpp
)

target_link_libraries(sequential_test
    generator
    sequential
)
