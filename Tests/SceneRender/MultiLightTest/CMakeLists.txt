add_executable(
    multi_light_test
    multi_light_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (multi_light_test ${GLFW_LIB})
target_link_libraries (multi_light_test ${GLAD_LIB})