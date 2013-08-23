include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${PHEET_INCLUDE_DIR}
)

add_library(parallel_2D
    label_set.cpp
    local_label_map.cpp
    parallel_2D.cpp
)

target_link_libraries(parallel_2D
    graph
)

add_executable(pmcsp
    pmcsp.cpp
)

target_link_libraries(pmcsp
    generator
    parallel_2D
    ${CMAKE_THREAD_LIBS_INIT}
    ${HWLOC_LIBRARIES}
)
