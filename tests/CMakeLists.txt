if (BUILD_TESTING)
    list(APPEND TEST_CASES
        data_utils_test
        de_boor_test
        b_spline_test
        bezier_spline_test
    )
    foreach(TEST_CASE ${TEST_CASES})
        add_executable(${TEST_CASE} ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_CASE}.cpp)
        target_link_libraries(${TEST_CASE} PRIVATE bzspline_lib gtest gtest_main pthread)
    endforeach(TEST_CASE ${TEST_CASES})
    
endif()