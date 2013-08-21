include_directories(
    ${GTEST_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

add_executable(sequential_tests sequential.cpp)
target_link_libraries(sequential_tests ${GTEST_LIBRARY}
                                       ${GTEST_MAIN_LIBRARY}
                                       generator
                                       graph
                                       sequential)
add_test(NAME sequential_tests COMMAND sequential_tests)
