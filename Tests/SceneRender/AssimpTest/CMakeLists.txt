add_executable(
    assimp_test
    assimp_test.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Camera/camera.cpp
    ${PROJECT_SOURCE_DIR}/SceneRender/Shader/shader.cpp
)
target_link_libraries (assimp_test ${GLFW_LIB})
target_link_libraries (assimp_test ${GLAD_LIB})
target_link_libraries (assimp_test ${ASSIMP_LIB})