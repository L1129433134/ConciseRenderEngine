add_executable(
    lighting_map_test
    lighting_map_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (lighting_map_test ${GLFW_LIB})
target_link_libraries (lighting_map_test ${GLAD_LIB})