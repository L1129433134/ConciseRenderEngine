cmake_minimum_required(VERSION 3.0.0)
project(ConciseRenderEngine VERSION 0.1.0)

include(CTest)
enable_testing()

# 附加包含目录
include_directories(ConciseRenderEngine/Model)
include_directories(SceneRender/Camera)
include_directories(SceneRender/Shader)
include_directories(SceneRender/ThirdParty/include)

# 编译入口
# add_subdirectory (Tests/Camera) 
add_subdirectory (Tests/SceneRender/CameraShaderTest) 

# 链接器附加库目录
find_library(GLFW_LIB libglfw3dll.a HINTS SceneRender/ThirdParty/lib)
find_library(GLAD_LIB libglad.a HINTS SceneRender/ThirdParty/lib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
