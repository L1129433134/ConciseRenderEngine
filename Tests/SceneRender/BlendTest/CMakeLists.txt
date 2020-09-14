add_executable(
    blend_test
    blend_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (blend_test ${GLFW_LIB})
target_link_libraries (blend_test ${GLAD_LIB})