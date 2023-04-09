cmake_minimum_required(VERSION 3.10)
project(bzspline_lib VERSION 1.0)

add_compile_options(-std=c++17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations")
set(BUILD_SHARED_LIBS ON)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIRS} include)

add_library(bzspline INTERFACE)
target_link_libraries(bzspline INTERFACE ${EIGEN3_LIBS})
target_include_directories(bzspline INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(FILES "${PROJECT_NAME}Config.cmake" 
  DESTINATION "share/${PROJECT_NAME}/cmake"
)
install(TARGETS
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
install(DIRECTORY include/basis include/de_boor include/spline
  DESTINATION include
)

if (BUILD_TESTING)
    list(APPEND TEST_CASES
        data_utils_test
        de_boor_test
        b_spline_test
        bezier_spline_test
    )
    foreach(TEST_CASE ${TEST_CASES})
        add_executable(${TEST_CASE} ${CMAKE_CURRENT_SOURCE_DIR}/tests/${TEST_CASE}.cpp)
        target_link_libraries(${TEST_CASE} PRIVATE bzspline gtest gtest_main pthread)
    endforeach(TEST_CASE ${TEST_CASES})
    
endif()