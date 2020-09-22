add_executable(
    cube_map_test
    cube_map_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (cube_map_test ${GLFW_LIB})
target_link_libraries (cube_map_test ${GLAD_LIB})
target_link_libraries (cube_map_test ${ASSIMP_LIB})