include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${PHEET_INCLUDE_DIR}
)

add_library(parallel
    label_set.cpp
    local_label_map.cpp
    locking_vector.cpp
    parallel.cpp
)

target_link_libraries(parallel
    graph
    pareto
    sp
)

add_executable(pmcsp
    pmcsp.cpp
)

target_link_libraries(pmcsp
    generator
    parallel
    ${CMAKE_THREAD_LIBS_INIT}
    ${HWLOC_LIBRARIES}
)
