add_executable(
   point_test  
   point_test.cpp
  ${PROJECT_SOURCE_DIR}/ConciseRenderEngine/Mathematics/point.cpp
)

add_executable(
    matrix_test  
    matrix_test.cpp
    ${PROJECT_SOURCE_DIR}/ConciseRenderEngine/Mathematics/matrix.cpp
)