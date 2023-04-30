cmake_minimum_required(VERSION 3.10)
project(bzspline VERSION 1.0)

add_compile_options(-std=c++17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-declarations")
set(BUILD_SHARED_LIBS ON)

add_subdirectory(bzspline_lib)
add_subdirectory(tests)