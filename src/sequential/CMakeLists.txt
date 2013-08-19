include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

add_library(sequential
    sequential.cpp
)

target_link_libraries(sequential
    graph
    sp
)

add_executable(smcsp
    smcsp.cpp
)

target_link_libraries(smcsp
    generator
    sequential
)
