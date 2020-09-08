add_executable(
    frame_test
    frame_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (frame_test ${GLFW_LIB})
target_link_libraries (frame_test ${GLAD_LIB})