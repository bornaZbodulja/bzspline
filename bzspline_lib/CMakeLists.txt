find_package(Eigen3 REQUIRED)

set(SPLINE_LIB_NAME "bzspline_lib")

add_library(${SPLINE_LIB_NAME} INTERFACE)
target_include_directories(${SPLINE_LIB_NAME} INTERFACE
  ${EIGEN3_INCLUDE_DIRS} 
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(${SPLINE_LIB_NAME} INTERFACE ${EIGEN3_LIBS})

install(FILES "${SPLINE_LIB_NAME}Config.cmake" 
  DESTINATION "share/${SPLINE_LIB_NAME}/cmake"
)

install(TARGETS ${SPLINE_LIB_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)

install(DIRECTORY include/basis include/de_boor include/spline
  DESTINATION include
)