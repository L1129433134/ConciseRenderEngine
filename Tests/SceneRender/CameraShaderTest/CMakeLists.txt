add_executable(
    camera_shader_test
    camera_shader_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (camera_shader_test ${GLFW_LIB})
target_link_libraries (camera_shader_test ${GLAD_LIB})