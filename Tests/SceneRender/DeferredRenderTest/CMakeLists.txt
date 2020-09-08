add_executable(
    deferred_render_test
    deferred_render_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (deferred_render_test ${GLFW_LIB})
target_link_libraries (deferred_render_test ${GLAD_LIB})
target_link_libraries (deferred_render_test ${ASSIMP_LIB})